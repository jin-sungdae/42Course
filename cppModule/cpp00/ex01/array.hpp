#ifndef ARRAY
#define ARRAY
#include "phonebook.hpp"


class Array{
private:
    phoneBook book[8];
    int index;
    int check_index;
public:
    Array();
    void searchBook();
    void addBook();
    void setIndex(int i);
    int getIndex();
    ~Array();
};
#endif