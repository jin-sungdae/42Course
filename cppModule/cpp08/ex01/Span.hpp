#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
public:
	Span();
	~Span();
	Span(unsigned int num);
	Span(Span const & s);
	Span & operator=(Span const & s);

	void addNumber(int num);
	int shortestSpan();
	int longestSpan();
private:
	unsigned int storageSize;
	std::vector<int> storage;
};

#endif