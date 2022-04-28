#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "utils.hpp"
#include "pair.hpp"
#include "iterator/iterator.hpp"

namespace ft {

    template <class Arg1, class Arg2, class Result>
        struct binary_function {
            typedef Arg1 first_argument_type;
            typedef Arg2 second_argument_type;
            typedef Result result_type;
        };
    
    template <class T> struct less : binary_function <T,T,bool> {
        bool operator() (const T& x, const T& y) const {return x<y;}
    };
    
    
template < class Key,                                     // map::key_type
           class T,                                       // map::mapped_type
           class Compare = less<Key>,                     // map::key_compare
           class Alloc = std::allocator<ft::pair<const Key,T>>    // map::allocator_type
           > class map{
    public :
        typedef Key     key_type;
        typedef T       mapped_type;
        typedef pair<Key, T> value_type;
        typedef compare     key_compare;
        class   value_compare
        typedef typename    Alloc       allocator_type;
        typedef typename    allocator_type::reference       reference;
        typedef typename    allocator_type::const_reference const_reference;
        typedef typename    allocator_type::pointer         pointer;
        typedef typename    allocator_type::const_pointer   const_pointer;

        // map = 이진트리 //

        
        
        typedef ft::iterator<value_type, map>                   iterator;
        typedef ft::iterator<const value_type, map>             const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;




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