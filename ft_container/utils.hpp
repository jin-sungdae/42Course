#ifndef UTILS_HPP
# define UTILS_HPP

#include <memory>
#include <iostream>
#include "vector.hpp"
#include "iterator.hpp"
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
}

#endif