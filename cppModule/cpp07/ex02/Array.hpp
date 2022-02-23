#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template<typename T>
class Array{
public:
    Array<T>() : size(0), arry(NULL){
        std::cout << "Array Constructor called" << std::endl;
    }

    Array<T>(const unsigned int size) : size(size) {
        std::cout << "Array one constructor called" << std::endl;
        if (size < 0){
            throw std::overflow_error("overflow low num");
        }
        this->arry = new T[size];
    }

    ~Array<T>( void ){
 		std::cout << "Array Destructor called" << std::endl;
 		if (this->size > 0)
 			delete [] this->arry;
 	}

     Array<T>(const Array<T> & array ){
 		std::cout << "Array a little copy called" << std::endl;
 		*this = array;
 	}

    Array<T>	&operator=( const Array<T> &array )
 	{
 		std::cout << "Array deep copy called" << std::endl;
 		if (this == &array)
 			return *this;
 		if (this->size > 0)
 			delete [] this->arry;
 		this->size = array.getSize();
 		this->arry = new T[this->size];
 		for (int i = 0; i < this->size; i++)
 			this->arry[i] = array[i];
 		return *this;
 	}

    T	&operator[](const int index) const
 	{
 		if (index >= this->size || index < 0)
 			throw std::overflow_error("overflow low num");
 		return this->arry[index];
 	}

    int getSize() const {
        return (this->size);
    }

private:
    int size;
    T  *arry;

};


#endif