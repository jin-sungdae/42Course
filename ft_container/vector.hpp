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

        protected:
            allocator_type              _alloc;
            value_type*                 _array;
            size_type                   _size;
            size_type                   _capacity;
        explicit vector (const allocator_type& alloc = allocator_type()) : 
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

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

        // ** capacity ** //
        size_type size() const;

        size_type max_size() const;

        void resize (size_type n, value_type val = value_type());

        size_type capacity() const;

        bool empty() const;
        
        void reserve (size_type n);
    

        // ** Element access ** //
        // operator[]
        reference operator[](size_type n);
        const_reference operator[](size_type n) const;
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
    //     struct _Vector_impl : public _Alloc
	// 	{
	// 		pointer _start;
	// 		pointer _finish;
	// 		pointer _end_of_storage;

	// 		_Vector_impl (void) : allocator_type(), _start(), _finish(), _end_of_storage() {}

	// 		_Vector_impl(_Alloc const& a) : allocator_type(a), _start(), _finish(), _end_of_storage() {}

	// 		void _swap_data (_Vector_impl& x) {
	// 			ft::swap(_start, x._start);
	// 			ft::swap(_finish, x._finish);
	// 			ft::swap(_end_of_storage, x._end_of_storage);
	// 			}
	// 	};
    //     _Vector_impl	_impl;
    //     allocator_type __alloc_;
    //     pointer __start_;
    //     pointer __end_;
    //     pointer __end_capacity_;
    //     void _init_dispatch(size_type n, const calue_type& val, true_type){
    //         this->_impl._start = _allocate(n);
    //         this->_impl._end_of_storage = this->_impl._start + n;
    //     }
        
    //     template <typename InputIterator>
    //     void _init_dispatch(InputIterator first, InputIterator last, false_type){
    //         typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
    //         _init_rage(first, last, IterCategory());
    //     }

    //     void _init_fill(size_type n, const value_type& val){
    //         pointer cur = this-> _impl._start;
    //         try{
    //             for (;n > 0; --n, ++cur)
    //                 __alloc_.construct(cur, val);
    //             this->_impl._finish = cur;
    //         } catch (std::exception& e){
    //             __alloc.destroy(this->_impl._start);
    //             throw;
    //         }
    //     }

    //     void _check_range(size_type n){
    //         if (n >= size())
    //             throw std::out_of_range("Out of Range");
    //     }

    //     void _assign_dispatch(size_type n, value_type& val, true_type){
    //         reserve(n);
    //         _init_fill(n, val);
    //     }

    //     template<typename InputIterator>
    //     void _assign_dispatch(InputIterator first, InputIterator last, false_type){
    //         typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
    //         _assign_range(first, last, IterCategory());
    //     }

    //     template <typename InputIterator>
    //     void _assign_range(InputIterator first, InputIterator last, ft::input_iterator_tag){
    //         try{
    //             for (; first != last; ++first)
    //                 put_back(*first);
    //         } catch (std::exception& e){
    //             clear();
    //             throw;
    //         }
    //     }

    //     template <typename InputIterator>
    //     void _assign_range(InputIterator first, InputIterator last, ft::forward_iterator_tag){
    //         const size_type n = ft::distance(first, last);

    //         reserve(n);
    //         _cpy_range(first, last);
    //     }

    //     iterator _insert_dispatch(iterator position, size_type n, const value_type& val, true_type){
    //         long long pos = position.base() - this->_impl._start;
    //         reserve(size() + n);
    //         if (pos == static_cast<long long>(size())){
    //             for (; n > 0; n--)
    //                 push_back(val);
    //         } else {
    //             this->_impl._finish += n;
    //             for (long long i = size() - 1; i >= pos; i--)
    //                 this->at(i) = this->at(i - n);
    //             for (; n > 0; n--)
    //                 __alloc_.construct(this->_impl._start + pos + n - 1, val);
    //         }
    //         return (iterator(this->_impl._start + pos));
    //     }

    //     template <typename InputIterator>
    //     void _insert_dispatch(iterator position, InputIterator first, InputIterator last, false_type){
    //         typedef typename ft::iterator_traits<InputIterator>::iterator_category IterCategory;
    //         _insert_range(position, first, last, IterCategory());
    //     }

    //     template <typename InputIterator>
    //     void _insert_range(iterator position, InputIterator first, InputIterator last, ft::input_iterator_tag){
    //         for (;first != last; first++){
    //             position = insert(position, *first);
    //             position++;
    //         }
    //     }

    //     template <typename InputIterator>
    //     void _insert_range(iteraotr position, InputIterator first, InputIterator last, ft::forward_iterator_tag){
    //         if (first != last){
    //             size_type n = ft::distance(first, last);
    //             size_type post = position.base() - this->_impl._start;
    //             reserve(size() + n);
    //             this->_impl._finish += n;
    //             for (size_type i = size() - i; i - n >= pos; i--)
    //                 this->at(i) = this->at(i - n);
    //             last--;
    //             for (; n > 0; n--, last--)
    //                 __alloc_construct(this->_impl._start + pos + n - 1, * last);
    //         }
    //     }

    // protected:
    //     pointer _allocate (size_t n) {
	// 				allocator_type	alloc;
					
	// 				alloc = _get_T_allocator();
	// 				if (n == 0)
	// 					return (pointer());
	// 				else
	// 					return (alloc.allocate(n));
	// 			}
    //     void _deallocate (pointer p, size_t n)
	// 			{
	// 				allocator_type	alloc;
					
	// 				alloc = _get_T_allocator();
	// 				if (p)
	// 					alloc.deallocate(p, n);
	// 			}
    //     allocator_type& _get_T_allocator (void) {
	// 	    return (*static_cast<allocator_type*>(&this->_M_impl));
	// 	}

	// 	const allocator_type& _get_T_allocator (void) const {
	// 		return (*static_cast<const allocator_type*>(&this->_M_impl));
	// 	}
					
        
    };

    //////////////////////////////////////==============================/////////////////////////////////////////////
    template <typename T, typename Alloc>
    vector<T, Alloc>::vector (const allocator_type & alloc) : _alloc(alloc), _array(0), _size(0), _capacity(0){}

    template <typename T, typename Alloc>
    vector (size_type n, const value_type& val , const allocator_type& alloc) : _alloc(alloc), _array(0), _size(n), _capacity(n) {
       _array = _alloc.allocate(_capacity);
       for (size_t i = 0; i < _size; i++)
            _alloc.construct(_array + i, val);
   }

   template <typename T, typename Alloc>                //>>>>>>>?
   template <typename InputIterator>
   vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc) : _alloc(alloc), _array(0), _size(0), _capacity(0){
       typedef typename ft::is_integer<InputIterator>::type is_int;
       this->assign(first, last);
   }

   template <typename T, typename Alloc>
   vector<T, Alloc>::vector (vector const& a) : _array(0), _size(0), _capacity(0){
       *this = a;
   }

   template <typename T, typename Alloc>
   vector<T, Alloc>::~vector(void) {
       this->claer();
       if (_array != NULL) _alloc.deallocate(_array, this->capacity());
       _array = NULL;
   }

   //////////////////////////////////////==============================/////////////////////////////////////////////
   template <typename T, typename Alloc>
   typename vector<T, Alloc>::iterator      vector<T, Alloc>::begin(){
       return (_array);
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::const_iterator vector<T, Alloc>::begin() const{
       return (_array);
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::iterator      vector<T, Alloc>::end(){
       return (_array + _size);
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::const_iterator vector<T, Alloc>::end() const {
       return (_array + _size);
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::reverse_iterator  vector<T, Alloc>::rbegin(){
       return (reverse_iterator(vector<T, Alloc>::end()));
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::const_reverse_iterator  vector<T, Alloc>::rbegin() const{
       return (const_reverse_iterator(vector<T, Alloc>::end()));
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::reverse_iterator vector<T, Alloc>::rend(){
       return (reverse_iterator(vector<T, Alloc>::begin()));
   }

   template <typename T, typename Alloc>
   typename vector<T, Alloc>::const_reverse_iterator vector<T, Alloc>::rend() const {
       return (const_reverse_iterator(vector<T, Alloc>::begin()));
   }

    //////////////////////////////////////==============================/////////////////////////////////////////////

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type        vector<T, Alloc>::size() const{
        return this->_size;
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type        vector<T, Alloc>::max_size() const{
        return (_alloc.max_size());
    }

    template <typename T, typename Alloc>
    void    vector<T, Alloc>::resize (size_type n, value_type val){
        if (n < _size)
            _size + n;
        else if (n > _size){
            if (n > _capacity){
                for (; _size < n; )
                    push_back(val);
            } else if (n <= capacity){
                for (; _size < n; _size++)
                    _array[_size] = val;
            }
            _size = n;
        }
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type    vector<T, Alloc>::capacity() const {
        return (this->capacity);
    }

    template <typename T, typename Alloc>
    bool    vector<T, Alloc>::empty() const {
        return (_size == 0 ? true : false);
    }

    template <typename T, typename Alloc>
    void    vector<T, Alloc>::reserve(size_type n){
        if (_capacity < n){
            T* tmp = _alloc.allocate(n);
            size_type tmp_size = _size;
            for (size_t i = 0; i < _size; i++){
                _alloc.construct(tmp + i, *(_array + i));
            }
            Array_clear_free(_size, _capacity, &_array, _alloc);
            _array = tmp;
            _capacity = n;
            _size = tmp_size;
        }
    }

    //////////////////////////////////////==============================/////////////////////////////////////////////
    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference    vector<T, Alloc>::operator[] (size_type n){
        return ((this->_array)[n]);
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference  vector<T, Alloc>::operator[] (size_type n) const {
        return ((this->_array)[n]);
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference vector<T, Alloc>::at (size_type n){
        if (n >= size())
            throw std::out_of_range("Out of Range");
        return (*(this->_array + n));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference  vector<T, Alloc>::at (size_type n) const {
        if (n >= size())
            throw std::out_of_range("Out of Range");
        return (*(this->_array + n));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference    vector<T, Alloc>::front() {
        return (*(this->_array));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>const_reference    vector<T, Alloc>::front() const {
        return (*(this->_array));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>reference  vector<T, Alloc>::back() {
        return (*(this-> array + _size - 1));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>const_reference  vector<T, Alloc>::back() const {
        return (*(this-> array + _size - 1));
    }

    //////////////////////////////////////==============================/////////////////////////////////////////////
        template <class InputIterator>
            void assign (InputIterator first, InputIterator last);          // ?
        
        template <typename T, typename Alloc>
        void    vector<T, Alloc>::assign(size_type n, const value_type& val){
            Array_clear_free(_size, _capacity, &_array, _alloc);
            _size = n;
            _capacity = n;
            _array = _alloc.allocate(n);
            for (size_type i = 0; i < n; i++){
                _alloc.construct(_array + i, val);
            }
        }

        template <typename T, typename Alloc>
        vector<T, Alloc>&   vector<T, Alloc>::operator=(const vector<T, Alloc>& n){
            if (this == &n)
                return (*this);
            Array_clear_free(_size, _capacity, &_array, _alloc);
            this->_size = n._size;
            this->_alloc = n._alloc;
            this->_capacity = n._capacity;
            _array = _alloc.allocate(n._capacity);
            for (size_t i = 0; i < n._size; i++)
                _alloc.construct(_array + i, n._array[i]);
            return (*this);
        }

        template <typename T, typename Alloc>
        void vector<T, Alloc>::push_back (const value_type& val){
            if (_size + 1 > _capacity){
                reserve(increase_capacity(_size, 1, _capacity));
            }
            _alloc.construct(_array + _size, val);
            _size++;
        }

        template <typename T, typename Alloc>
        void vector<T, Alloc>::pop_back() {
            if (_size != 0)
                _size--;
            _alloc.destroy(_array + _size);
        }
        
        template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last);
        
        iterator erase (iterator position);
        
        iterator erase (iterator first, iterator last);
        
        template <class T, class Alloc>
            void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
    

        void get_allocator();
}

#endif