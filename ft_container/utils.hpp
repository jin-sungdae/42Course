#ifndef UTILS_HPP
# define UTILS_HPP

#include <memory>
#include <iostream>
#include "vector.hpp"
#include "iterator/iterator.hpp"
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

    struct true_type {};
	struct false_type {};

	template<typename _Tp>
		struct is_integer
		{
			enum { value = 0 };
			typedef false_type type;
		};

	template<>
		struct is_integer<bool>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<char>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<signed char>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<unsigned char>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<short>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<unsigned short>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<int>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<unsigned int>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<long>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<unsigned long>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<long long>
		{
			enum { value = 1 };
			typedef true_type type;
		};

	template<>
		struct is_integer<unsigned long long>
		{
			enum { value = 1 };
			typedef true_type type;
		};
}

#endif