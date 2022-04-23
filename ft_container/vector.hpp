#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "./iterator/iterator.hpp"

namespace ft {
    template<typename T, typename Alloc = std::allocator<T> >
        class vector{
        public :

                typedef T                                               value_type;
                typedef Alloc                                           allocator_type;
                typedef typename allocator_type::reference              reference;
                typedef typename allocator_type::const_referenc         const_reference;
                typedef typename allocator_type::pointer                pointer;
                typedef typename allocator_type::const_pointer          const_pointer;
                typedef ft::iterator<pointer, vector>                   iterator;
                typedef ft::iterator<const_pointer, vector>             const_iterator;
                typedef ft::reverse_iterator<iterator>                  reverse_iterator;
                typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;
                typedef ptrdiff_t                                       difference_type;
                typedef size_t                                          size_type;

                
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val - value_type(), const allocator_type& alloc = allocator_type());

        template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type());
        vector (const vector& x);
        ~vector();

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
        struct _Vector_impl : public _Alloc
		{
			pointer _start;
			pointer _finish;
			pointer _end_of_storage;

			_Vector_impl (void) : allocator_type(), _start(), _finish(), _end_of_storage() {}

			_Vector_impl(_Alloc const& a) : allocator_type(a), _start(), _finish(), _end_of_storage() {}

			void _swap_data (_Vector_impl& x) {
				ft::swap(_start, x._start);
				ft::swap(_finish, x._finish);
				ft::swap(_end_of_storage, x._end_of_storage);
				}
		};
        _Vector_impl	_impl;
        allocator_type __alloc_;
        pointer __start_;
        pointer __end_;
        pointer __end_capacity_;
        void _init_dispatch(size_type n, const calue_type& val, true_type){
            this->_impl._start = _allocate(n);
            this->_impl._end_of_storage = this->_impl._start + n;
        }
        
        template <typename InputIterator>
        void _init_dispatch(InputIterator first, InputIterator last, false_type){
            typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
            _init_rage(first, last, IterCategory());
        }

        void _init_fill(size_type n, const value_type& val){
            pointer cur = this-> _impl._start;
            try{
                for (;n > 0; --n, ++cur)
                    __alloc_.construct(cur, val);
                this->_impl._finish = cur;
            } catch (std::exception& e){
                __alloc.destroy(this->_impl._start);
                throw;
            }
        }

        void _check_range(size_type n){
            if (n >= size())
                throw std::out_of_range("Out of Range");
        }

        void _assign_dispatch(size_type n, value_type& val, true_type){
            reserve(n);
            _init_fill(n, val);
        }

        template<typename InputIterator>
        void _assign_dispatch(InputIterator first, InputIterator last, false_type){
            typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
            _assign_range(first, last, IterCategory());
        }

        template <typename InputIterator>
        void _assign_range(InputIterator first, InputIterator last, ft::input_iterator_tag){
            try{
                for (; first != last; ++first)
                    put_back(*first);
            } catch (std::exception& e){
                clear();
                throw;
            }
        }

        template <typename InputIterator>
        void _assign_range(InputIterator first, InputIterator last, ft::forward_iterator_tag){
            const size_type n = ft::distance(first, last);

            reserve(n);
            _cpy_range(first, last);
        }

        iterator _insert_dispatch(iterator position, size_type n, const value_type& val, true_type){
            long long pos = position.base() - this->_impl._start;
            reserve(size() + n);
            if (pos == static_cast<long long>(size())){
                for (; n > 0; n--)
                    push_back(val);
            } else {
                this->_impl._finish += n;
                for (long long i = size() - 1; i >= pos; i--)
                    this->at(i) = this->at(i - n);
                for (; n > 0; n--)
                    __alloc_.construct(this->_impl._start + pos + n - 1, val);
            }
            return (iterator(this->_impl._start + pos));
        }

        template <typename InputIterator>
        void _insert_dispatch(iterator position, InputIterator first, InputIterator last, false_type){
            typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
            _insert_range(position, first, last, IterCategory());
        }

        template <typename InputIterator>
        void _insert_range(iterator position, InputIterator first, InputIterator last, ft::input_iterator_tag){
            for (;first != last; first++){
                position = insert(position, *first);
                position++;
            }
        }

        template <typename InputIterator>
        void _insert_range(iteraotr position, InputIterator first, InputIterator last, ft::forward_iterator_tag){
            if (first != last){
                size_type n = ft::distance(first, last);
                size_type post = position.base() - this->_impl._start;
                reserve(size() + n);
                this->_impl._finish += n;
                for (size_type i = size() - i; i - n >= pos; i--)
                    this->at(i) = this->at(i - n);
                last--;
                for (; n > 0; n--, last--)
                    __alloc_construct(this->_impl._start + pos + n - 1, * last);
            }
        }

    protected:
        pointer _allocate (size_t n) {
					allocator_type	alloc;
					
					alloc = _get_T_allocator();
					if (n == 0)
						return (pointer());
					else
						return (alloc.allocate(n));
				}
        void _deallocate (pointer p, size_t n)
				{
					allocator_type	alloc;
					
					alloc = _get_T_allocator();
					if (p)
						alloc.deallocate(p, n);
				}
        allocator_type& _get_T_allocator (void) {
		    return (*static_cast<allocator_type*>(&this->_M_impl));
		}

		const allocator_type& _get_T_allocator (void) const {
			return (*static_cast<const allocator_type*>(&this->_M_impl));
		}
					
        
    };
}

#endif