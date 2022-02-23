#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
typename T::iterator easyfind(T &a, int b){
    typename T::iterator	result = find(a.begin(), a.end(), b);

	if (result == a.end())
		return a.end();
	return result;
}

#endif