#include <vector>
#include <iostream>
#include "easyfind.hpp"

template<typename T>
void	displayIterator(T it, T end){
    if (it != end)
 		std::cout << "iterator: " << *it << std::endl;
	else
		std::cout << "iterator reached the end of container" << std::endl;
}

int	main( void ){
	std::vector<int>	v;
	std::vector<int>::iterator	it;

	for (int i = 1; i < 60; i+=2)
		v.push_back(i);
	it = easyfind(v, 43);
	displayIterator(it, v.end());
	it = easyfind(v, 42);
	displayIterator(it, v.end());
}