#ifndef __UTILS_HPP__
# define __UTILS_HPP__
#include <iostream>
namespace ft{
    template <typename T>
    void swap(T & a, T& b){
        T temp;
        temp = a;
        a = b;
        b = temp;
    }

    template <typename T>
    T& max(const T& a, const T& b){
        if (a < b)
            return (b);
        return (a);
    }

    template <typename T>
    bool itcmp (const T& a, const T& b){
        if (a.size() != b.size())
            return (false);
        typedef typename T::const_iterator const_iterator;
        const_iterator it1;
        const_iterator it2;
        const_iterator end1;
        const_iterator end2;

        it1 = a.begin();
        it2 = b.begin();
        end1 = a.end();
        end2 = b.end();
        if (it1 == it2 && end1 == end2)
            return (true);
        while (it1 != end1 && it2 != end2 && *it1 == *it2){
            it1++;
            it2++;
        }
        return (*it1 == *it2);
    }

    template <typename T1, typename T2>
    bool itcmp (T1 first1, T1 last1, T2 first2){
        while (first1 != last1 && *first1 == *first2){
            first1++;
            first2++;
        }
        return (*first1 == *first2);
    }

    template <typename T>
    bool itinf (const T& a, const T& b){
        typedef typename T::const_iterator const_iterator;
        const_iterator it1;
        const_iterator it2;

        it1 = a.begin();
        it2 = b.begin();
        while (it1 != a.end()){
            if (it2 == b.end() || *it2 < * it1)
                return (false);
            else if (*it1 < *it2)
                return (true);
            ++it1;
            ++it2;
        }
        return (it2 != b.end());
    }

    size_t increase_capacity(size_t _size, size_t n, size_t _capacity)
	{
	    if(_capacity == 0)
	        _capacity = 1;
	    while(_size + n >= _capacity)
	        _capacity = _capacity * 2;
	    return _capacity;
	}

   	template <typename size_type, typename value_type, typename Alloc>
	void Array_clear_free(size_type &_size, size_type &_capacity, value_type** _array, Alloc _alloc)
	{
		if ((*_array) != NULL)
		{
			for (size_t i = 0; i < _size; ++i)
				_alloc.destroy((*_array) + i);
			_alloc.deallocate((*_array), _capacity);
			(*_array) = 0;
			_size = 0;
			_capacity = 0;
		}
	}

    template <typename InputIterator1, typename InputIterator2>
    bool equal (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1)
        {
            if (!(*first1 == *first2))
                return false;
            ++first1;
            ++first2;
        }
        return true;
    }

 	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2 < *first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
								InputIterator2 first2, InputIterator2 last2,
								Compare comp)
	{
		while (first1 != last1) {
			if (first2 == last2 || comp(*first2, *first1)) return false;
			else if (comp(*first1, *first2)) return true;
			++first1;
            ++first2;
		}
		return (first2 != last2);
	}

    template <bool isConst, typename isFalse, typename isTrue>
    struct chooseConst {};


    template <typename isFalse, typename isTrue>
    struct chooseConst<false, isFalse, isTrue>
    {
        typedef isFalse type;
    };


    template <typename isFalse, typename isTrue>
    struct chooseConst<true, isFalse, isTrue>
    {
        typedef isTrue type;
    };
}

#endif