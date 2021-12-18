#ifndef COURSEWORK_BINARY_FILE_HPP
#define COURSEWORK_BINARY_FILE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <cstring>


using namespace std;

class BinaryFile : public std::fstream {
public:
    static char *listName;

    BinaryFile();

    BinaryFile(const char *name, bool flag);

    void setElem(const char *set_str);

    void addElem();

    void addFile(const char *fileName);

    void createFile(const char *fileName);

    friend std::ostream &operator<<(std::ostream &out, BinaryFile &file);


private:
    streampos next;
    unsigned long length;
    char *string;

};

#endif //COURSEWORK_BINARY_FILE_HPP
