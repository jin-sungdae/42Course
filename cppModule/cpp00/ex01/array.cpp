#include "array.hpp"

Array::Array()
{
    this->index = 0;
    this->check_index = 0;
}

void Array::searchBook()
{
	int j;

    j = 0;
    if (index == 0)
    {
        std::cout << RED << "NO SEARCH INDEX" << NC << std:: endl;
        return ;
    }
	if (check_index >= 8)
    {
        while (j < 8)
		    book[j++].showsubInfo();
    }
	else
        while (j < index)
            book[j++].showsubInfo();
	int check_index = 0;
    std::cout << CYN << "press index :" ;
    while (!(std::cin >> check_index) || (check_index < 0 || check_index >= index))
    {
        std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << RED << "# Invalid Index\n~" << NC;
    }
	book[check_index].showInfo();
}

void Array::addBook()
{
    int new_index = 0;
    
    if (index < 8)
    {
        book[index].getInfo();
        book[index].setIndex(index);
    }
    else
    {
        new_index = index % 8;
        book[new_index].getInfo();
        book[new_index].setIndex(new_index);
    }
    index++;
    check_index++;
}

void Array::setIndex(int i)
{
    index = i;
}

int Array::getIndex()
{
    return index;
}

Array::~Array()
{}