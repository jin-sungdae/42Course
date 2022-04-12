#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "./iterator/random_access_iterator.hpp"

namespace ft {
    template<class  T, class Alloc = std::allocator<T>>
        class vector{
        public :

        typedef T                                               value_type;
        typedef Alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_referenc         const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;


        explicit vector (const allocator_type& alloc = allocator_type()) : __alloc_(alloc), __start_(nullptr), __end_(nullptr), __end_capacity(nullptr);
        {}
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()) : __alloc_(alloc), __start_(nullptr), __end_(nullptr), __end_capacity_(nullptr) {
            this.__start_ = alloc.allocate(n);
            this.__end_capacity_ = this.__start_ + n;
            this.__end_ = this.__start_;
            while (n--){
                alloc.construct(this.__end_, val);
                end++;
            }
        }
        template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        vector (const vector& x);
        ~vector();
    
        typedef typename std::vector<T>::container_type::iterator iterator;

        // ** iterators ** //
        iterator begin();
        
        const_iterator begin() const;
        
        iterator end();
        
        const_iterator end() const;
        
        reverse_iterator rbegin();
        
        const_reverse_iterator rbegin() const;
        
        reverse_iterator rend();
        
        const_reverse_iterator rend() const;
        
        const_iterator cbegin() const noexcept;
        
        const_iterator cend() const noexcept;
        
        const_reverse_iterator crbegin() const noexcept;
       
        const_reverse_iterator crend() const noexcept;

        // ** capacity ** //
        size_type size() const;

        size_type max_size() const;

        void resize (size_type n, value_type val = value_type());

        size_type capacity() const;

        bool empty() const;
        
        void reserve (size_type n);
    

        // ** Element access ** //
        // operator[]
        reference at (size_type n);
        const_reference at (size_type n) const;
        reference front();
        const_reference front() const;
        reference back();
        const_reference back() const;
    

        // ** modifiers ** //
        template <class InputIterator>
            void assign (InputIterator first, InputIterator last);
        
        void push_back (const value_type& val);

        void pop_back();
        
        template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
        
        iterator erase (iterator position);
        
        iterator erase (iterator first, iterator last);
        
        template <class T, class Alloc>
            void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
    
        // ** Allocator ** //
        void get_allocator();

        // ** Non-member function overloads ** //
        // relational operators
        // swap

        // ** Template specializeations ** //
        // vector<bool>
    private:
        allocator_type __alloc_;
        pointer __start_;
        pointer __end_;
        pointer __end_capacity_;
    };
}

#endif