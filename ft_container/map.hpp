#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "utils.hpp"
#include "iterator/iterator.hpp"

namespace ft {
    
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = allocator<pair<const Key,T> >    // map::allocator_type
           > class map{
    public :
        typedef Key     key_type;
        typedef T       mapped_type;
        typedef pair<Key, T> value_type;
        typedef compare     key_compare;
        typedef typename    value_compare

        map();
        ~map();
        // operatr =

        // ** Iterators ** //
        void begin();
        void end();
        void rbegin();
        void rend();
    
        // ** capacity ** //
        void empty();
        void size();
        void max_size();

        // ** Element access ** //
        // operatro[]

        // ** Modifiers ** //
        void insert();
        void erase();
        void swap();
        void clear();

        // ** Observers ** //
        void key_comp();
        void value_comp();

        // ** Operations ** //
        void find();
        void count();
        void lower_bound();
        void upper_bound();
        void equal_range();

        // ** Allocator ** //
        void get_allocator();
    private:
    };
}

#endif