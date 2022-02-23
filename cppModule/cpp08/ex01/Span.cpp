#include "Span.hpp"

Span::Span():storageSize(0){
	std::cout << "Span default constructor called" << std::endl;
}


Span::Span(unsigned int storageSize) : storageSize(storageSize){
	std::cout << "one parm Span constructor called" << std::endl;
}

Span::Span(Span const & s){
	std::cout << "Span a little Copy called" << std::endl;
	*this = s;
}

Span::~Span(){
	std::cout << "Span destructor called" << std::endl;
}

Span &Span::operator=(Span const & s){
	this->storage = s.storage;
	this->storageSize = s.storageSize;
	return *this;
}

void Span::addNumber(int num){
	if (this->storage.size() == this->storageSize)
		throw std::out_of_range("Full storage Size");
	this->storage.push_back(num);
}

int Span::shortestSpan(){
	std::vector<int> temp = this->storage;
	std::vector<int>::iterator it;
	int result = -1;

	if (this->storage.size() <= 1)
		throw std::logic_error("Not enough Number");
	sort(temp.begin(), temp.end());
	result = *(temp.begin() + 1) - *temp.begin();
	if (temp.size() == 2)
		return result;
	for (it = temp.begin() + 1; it != temp.end() -1 && result != 0; it++){
		if (*(it + 1) - *it < result)
			result = *(it + 1) - *it;
	}
	return result;
}

int Span::longestSpan(){
	std::vector<int> temp = this->storage;
	
	if (this->storage.size() <= 1)
		throw std::logic_error("Not enough Number");
	sort(temp.begin(), temp.end());
	return *(temp.end() - 1) - *temp.begin();
}