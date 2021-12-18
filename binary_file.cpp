#include "binary_file.hpp"
#include <string>
#include <iostream>

BinaryFile::BinaryFile(const char *name, bool flag) : basic_fstream(name, ios::in | ios::out | ios::binary) {
    streampos i = 0;
    unsigned long l = 0;
    if (!is_open()) {
        throw "Error! File not open";
    } else {
        // if flag == true: an existing file will be opened
        // else: a new file will be created
        if (!flag) {
            write(listName, strlen(listName)); // Запись заголовка
            write((char *) &i, sizeof(i)); // Запись указателя
            write((char *) &l, sizeof(l)); // Запись длины
        }
        cout << "File opened" << endl;
    }

}

BinaryFile::BinaryFile() : basic_fstream() {}

void BinaryFile::setElem(const char *set_str) {
    length = strlen(set_str);
    string = new char[length + 1];
    for (int i = 0; i < length; ++i) {
        string[i] = set_str[i];
    }
    cout << "String: " << string << endl;
    cout << "Length: " << length << endl;
}

void BinaryFile::addElem() {
    unsigned long nameLength = strlen(listName); // длина заголовка
    seekg(nameLength + sizeof(streampos), ios::beg); // пропускаем заголовок и первый указатель
    unsigned long first_lng = 0;

    read((char *) (&first_lng), sizeof(first_lng)); // Читаем длину первого элемента

    seekp(nameLength, ios::beg); // Пропускаем заголовок

    if (first_lng == 0) {
        // Если длина первого ==, значит список пустой и нужно добавить первый элемент
        write((char *) &next, sizeof(next));
        write((char *) &length, sizeof(length));
        write(string, length);
    } else {
        streampos _next;
        unsigned long _length;
        char *bufString;
        streampos curPos = nameLength;

        do {
            streampos prev = tellg(); // записываем поз-ю перед указателем пред-го
            read((char *) &_next, sizeof(_next)); // читаем указатель на следующий элемент
            read((char *) &_length, sizeof(_length));// читаем длину строки
            bufString = new char[_length + 1];
            read(bufString, _length); // читаем строку
            curPos += sizeof(_length) + sizeof(streampos) + _length; // записываем текущую позицию
            // Если указатель = 0, значит достигли конца, записываем здесь новый элемент
            if (_next == 0) {
                seekp(curPos, ios::beg); // перемещаемся для записи элемента
                write((char *) &next, sizeof(next));
                write((char *) &length, sizeof(length));
                write(string, length);;

                // Записываем указатель на новый элемент в предыдущем
                seekp(prev, ios::beg);
                _next = tellp();
                write((char *) &curPos, sizeof(curPos));
                break;
            }
        } while (true);
    }

}

// Перегрузка оператора вывода
std::ostream &operator<<(ostream &out, BinaryFile &file) {
    streampos _next;
    unsigned long _length;
    char *strout;

    file.seekg(strlen(BinaryFile::listName), ios::beg); // Пропускаем заголовок
    out << "List:" << endl;
    int i = 1;

    do {
        file.read((char *) &_next, sizeof(_next)); // Читаем указатель на следующий элемент
        file.read((char *) &_length, sizeof(_length)); // Читаем длину следующего элемента
        strout = new char[_length];
        file.read(strout, _length);
        out << i << ") \t" << strout << endl;
        delete[]strout;
        i++;
    } while (_next);

    return out;
}


void BinaryFile::addFile(const char *fileName) {
    ifstream fin;
    fin.open(fileName, ios::in);

    if (!fin.is_open()) {
        cout << "Error! File not open" << endl;
        return;
    } else {
        std::string word;
        while (fin >> word) {
            char *bufString = new char[word.size()];
            strcpy(bufString, word.c_str());
            setElem(bufString);
            delete[]bufString;
            addElem();
        }
        fin.close();
    }
}

void BinaryFile::createFile(const char *fileName) {
    ofstream fout;
    fout.open(fileName, ios::out);
    if (!fout.is_open()) {
        cout << "Error! File not open" << endl;
        return;
    }
    streampos _next;
    unsigned long _length;
    seekg(strlen(listName), ios::beg); // Пропускаем заголовок
    do {
        read((char *) &_next, sizeof(_next)); // Читаем указатель на следующий элемент
        read((char *) &_length, sizeof(_length)); // Читаем длину

        char *strout = new char[_length + 1];
        read(strout, _length);// Читаем строку
        strout[_length] = '\0';
        fout << strout << " ";
    } while (_next); // пока указатель на следующий элемент не равен 0
}



