#include <iostream>
#include "binary_file.hpp"
#include <string>

#define HELP "Menu: \n \
1) new \t\t\t\t\t Create new binary file. \n \
2) open \t\t\t\t\t Open binary file. \n \
3) add \t\t\t\t\t Add string. \n \
4) show \t\t\t\t\t Show string list. \n \
5) read \t\t\t\t\t Read strings from  file. \n \
6) write \t\t\t\t\t Write strings to file. \n \
7) help \t\t\t\t\t Command List. \n \
8) close \t\t\t\t\t Close file. \n \
0) exit \t\t\t\t\t Close programm."

using namespace std;

// заголовок по умолчанию
char *BinaryFile::listName = (char *) ("bin");

/*int main() {
    cout << HELP << endl;

    std::string str;
    bool flag = true;
    BinaryFile file;

    do {
        cout << ">";
        getline(cin, str);
        switch (str[0]) {
            case '1': {
                try {
                    file = BinaryFile("../data/new_bin.dat", false);
                    if (!file) {
                        throw -1;
                    }
                    cout << "File connect." << endl;
                }
                catch (int a) {
                    cerr << "File not found";
                }
                break;
            }
            case '2': {
                try {
                    file = BinaryFile("../data/bin.dat",true);
                    if (!file) {
                        throw -1;
                    }
                    cout << "File connect." << endl;
                }
                catch (int a) {
                    cerr << "File not found";
                }
                break;
            }
            case '3': {
                try {
                    if (!file.is_open()) {
                        throw -1;
                    }
                    string temp_str;
                    cout << "String: ";
                    cin >> temp_str;
                    file.setElem((char *) temp_str.c_str());
                    file.addElem();
                }
                catch (int a) {
                    cerr << "File is not open!" << endl;
                }
                break;
            }
            case '4': {
                try {
                    if (!file.is_open()) {
                        throw -1;
                    }
                    cout << file << endl;
                }
                catch (int a) {
                    cerr << "File is not open!" << endl;
                }
                break;
            }
            case '5': {
                try {
                    if (!file.is_open()) {
                        throw -1;
                    }
                    file.addFile("../data/for_read.txt");
                    cout << "Complete!" << endl;
                }
                catch (int a) {
                    cerr << "File is not open!" << endl;
                }
                break;

            }
            case '6': {
                try {
                    if (!file.is_open()) {
                        throw -1;
                    }
                    file.createFile("../data/for_write.txt");
                    cout << "Complete!" << endl;
                }
                catch (int a) {
                    cerr << "File is not open!" << endl;
                }
                break;
            }
            case '7' : {
                cout << HELP << endl;
                break;
            }
            case '8': {
                file.close();
                cout << "File closed!" << endl;
                break;
            }
            case '0' : {
                flag = false;
                break;
            }
            case '\0' : {
                break;
            }
            default: {
                cout << "Command was not recognized" << endl;
                break;
            }

        }
    } while (flag);
    return 0;
}*/

/*
int main() {
    char set_str[] = "foo1234";
    int length = strlen(set_str);
    char *string1 = new char[length + 1];
    char *string2 = new char[length + 1];
    const char *i = set_str;
    char *j = string1;

    while (*i ) {
        *j = *i;
        ++i;
        ++j;
    }
    for (int k = 0; k < length; ++k) {
        string2[k] = set_str[k];
    }
    cout << string1 << endl;
    cout << string2 << endl;
    cout << strcmp(string1, string2);
}*/
