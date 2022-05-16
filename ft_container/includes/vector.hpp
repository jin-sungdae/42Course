#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "../vector/vector_iterator.hpp"
#include "../util/utils.hpp"

namespace ft {
    template < class T, class Alloc = std::allocator<T> >
    class vector {
    public :
        typedef T                                               value_type;
        typedef Alloc                                           allocator_type;
        typedef typename allocator_type::reference              reference;
        typedef typename allocator_type::const_reference        const_reference;
        typedef typename allocator_type::pointer                pointer;
        typedef typename allocator_type::const_pointer          const_pointer;
        typedef vector_iterator<value_type>                     iterator;
        typedef vector_iterator<const value_type>               const_iterator;
        typedef reverse_iterator_tag<iterator>                  reverse_iterator;
        typedef reverse_iterator_tag<const_iterator>            const_reverse_iterator;
        typedef ptrdiff_t                                       difference_type;
        typedef size_t                                          size_type;

    protected:
        allocator_type                                          _alloc;
        value_type*                                             _array;
        size_type                                               _size;
        size_type                                               _capacity;
    public:
        explicit vector (const allocator_type& alloc = allocator_type());
        explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());

        template <class InputIterator>
            vector (InputIterator first, InputIterator last,
             const allocator_type& alloc = allocator_type(), 
             typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr);
        vector (const vector& x);
        ~vector();
        vector& operator= (const vector& rhd); 

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
        void        assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value > :: type* = 0);
        void        assign(size_type n, const value_type& val);

        void push_back (const value_type& val);

        void pop_back();
        
        iterator insert (iterator position, const value_type& val);
        void insert (iterator position, size_type n, const value_type& val);
		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = nullptr);

                
         
        iterator erase (iterator position);
        
        iterator erase (iterator first, iterator last);
        
   
        void clear();
        void swap (vector& x );
    
        // ** Allocator ** //
        allocator_type get_allocator() const;

        // ** Non-member function overloads ** //
        // relational operators
        // swap

        // ** Template specializeations ** //
        // vector<bool>  
    };

    //////////////////////////////////////==============================/////////////////////////////////////////////
    template <typename T, typename Alloc>
    vector<T, Alloc>::vector (const allocator_type & alloc) : _alloc(alloc), _array(0), _size(0), _capacity(0){}

    template <typename T, typename Alloc>
    vector<T, Alloc>::vector (size_type n, const value_type& val , const allocator_type& alloc) : _alloc(alloc), _array(0), _size(n), _capacity(n) {
       _array = _alloc.allocate(_capacity);
       for (size_t i = 0; i < _size; i++)
            _alloc.construct(_array + i, val);
   }

   template <typename T, typename Alloc>            
   template <typename InputIterator>
   vector<T, Alloc>::vector (InputIterator first, InputIterator last, const allocator_type& alloc, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type*) : _alloc(alloc), _array(0), _size(0), _capacity(0)
   {
       this->assign(first, last);
   }

   template <typename T, typename Alloc>
   vector<T, Alloc>::vector (vector const& a) : _array(0), _size(0), _capacity(0){
       *this = a;
   }

   template <typename T, typename Alloc>
   vector<T, Alloc>::~vector(void) {
       this->clear();
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
            _size = n;
        else if (n > _size){
            if (n > _capacity){
                for (; _size < n; )
                    push_back(val);
            } else if (n <= _capacity){
                for (; _size < n; _size++)
                    _array[_size] = val;
            }
            _size = n;
        }
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::size_type    vector<T, Alloc>::capacity() const {
        return (this->_capacity);
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
    typename vector<T, Alloc>::const_reference    vector<T, Alloc>::front() const {
        return (*(this->_array));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::reference  vector<T, Alloc>::back() {
        return (*(this-> _array + _size - 1));
    }

    template <typename T, typename Alloc>
    typename vector<T, Alloc>::const_reference  vector<T, Alloc>::back() const {
        return (*(this-> _array + _size - 1));
    }

    //////////////////////////////////////==============================/////////////////////////////////////////////
        template <typename T, class Alloc>
        template <class InputIterator>
        void        vector<T, Alloc>::assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value > :: type*)
        {
            ptrdiff_t distan_value = distance<InputIterator>(first, last);
            pointer     tmp_array = _alloc.allocate(distan_value);
            for (int i = 0; first != last; i++)
            {
                _alloc.construct((tmp_array + i), (*first));
                first++;
            }
            Array_clear_free(_size, _capacity, &_array, _alloc);
            _size = distan_value;
		    _capacity = distan_value;
		    _array = tmp_array;
        }
        
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

        template<typename T, typename Alloc>
        typename vector<T,Alloc>::iterator   vector<T,Alloc>::insert (iterator position, const value_type& val)
		{
			size_type								idx;
		    int									    put_position_ptr_flag = 0; 

		    _capacity = increase_capacity(_size, 0, _capacity); 
		    T* tmp = _alloc.allocate(_capacity);
		    size_type tmp_capacity = _capacity;
		    size_type tmp_size = _size;
		    for(size_type i = 0; i < _size + 1; i++)
		    {
			    if(put_position_ptr_flag == 0 && _array + i == position._ptr)
			    {
				    _alloc.construct(tmp + i, val);
				    put_position_ptr_flag = 1;
				    idx = i;
			    }
			    else
				    _alloc.construct(tmp + i, *(_array + i - put_position_ptr_flag));
		    }
		    Array_clear_free(_size, _capacity, &_array, _alloc);
		    _array = tmp;
		    _size = tmp_size + 1;
		    _capacity = tmp_capacity;
		    return (iterator(this->begin() + idx));
		}

        template<typename T, typename Alloc>
        void vector<T, Alloc>::insert (iterator position, size_type n, const value_type& val)
		{
			if (n != 0)
		    {
			    size_type							j = 0;
			    int								    put_position_ptr_flag = 0;

			    _capacity = increase_capacity(_size, n, _capacity);
			    T* tmp = _alloc.allocate(_capacity);
			    size_type tmp_capacity = _capacity;
			    size_type tmp_size = _size;
			    for(size_t i = 0; i < _size + n + 1; i++)
			    {
				    if(put_position_ptr_flag == 0 && _array + i == position._ptr)
				    {
					    for(j = 0; j < n; j++)
					    {
						    _alloc.construct(tmp + i + j, val);
					    }
					    put_position_ptr_flag = 1;
					    i = i + j; 
					    //수정 : 인덱스 조정.
				    }
				    else
				    {
					    _alloc.construct(tmp + i - put_position_ptr_flag, *(_array + (i - j) - put_position_ptr_flag));
				    }
			    }
			    Array_clear_free(_size, _capacity, &_array, _alloc);
			    _array = tmp;
			    _capacity = tmp_capacity;
			    _size = tmp_size + n;
		    }
		}

        template <typename T, class Alloc>
        template <class InputIterator>
		void vector<T, Alloc>::insert (iterator position, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type*)
		{
			int										put_position_ptr_flag = 0;
		    int										j = 0;

		    difference_type cnt = distance<T, InputIterator>(first, last);
		    size_type tmp_size = cnt + _size;
		    size_type tmp_capacity = increase_capacity(_size, cnt, _capacity);
		    T* tmp = _alloc.allocate(tmp_capacity);

		    for(size_t i = 0; i < _size + cnt + 1; i++)
		    {
			    if(put_position_ptr_flag != 1 && _array + i == position._ptr)
			    {
				    for(j = 0; first != last; first++)
				    {
					    _alloc.construct(tmp + i + j, (*first));
					    j++;
				    }
				    put_position_ptr_flag = 1;
				    i = i + j;
			    }
			    else
			    {
				    _alloc.construct(tmp + i - put_position_ptr_flag, *(_array + (i - j) - put_position_ptr_flag));
			    }
		    }
		    Array_clear_free(_size, _capacity, &_array, _alloc);
		    _array = tmp;
		    _capacity = tmp_capacity;
		    _size = tmp_size;
		}

        template <typename T, class Alloc>
	    typename vector<T, Alloc>::iterator	vector<T, Alloc>::erase(iterator position)
	    {
		    size_t									idx = 0;

		    T* tmp = _array;
		    for(size_t i = 0; i < _size; i++)
		    {
			    if(tmp == position._ptr)
			    {
				    idx = i;
				    _alloc.destroy(_array + i);
				    for(; i < _size; i++)
				    {
					    _alloc.construct(_array + i, *(_array + i + 1));
					    _alloc.destroy(tmp + i);
				    }
				    _size--;
			    }
			    tmp++;
		    }
		    return (iterator(_array + idx));
	    }
        
        template <typename T, typename Alloc>
        typename vector<T, Alloc>::iterator     vector<T, Alloc>::erase (iterator first, iterator last) {
            size_t  idx = 0;
            T *tmp = _array;
            difference_type length = last - first;
            if (length > 0){
                for (size_t i = 0; i < _size; i++){
                    if (tmp == first._ptr){
                        idx = i;
                        for (int j = 0; first != last; first++, j++)
                            _alloc.destroy(_array + i + j);
                        for (; i < _size - length; i++){
                            _alloc.construct(_array + i, *(_array + i + length));
                            _alloc.destroy(_array + i + length);
                        }
                        _size = _size - length;
                    }
                    tmp++;
                }
            }
            return iterator(_array + idx);
        }

        template <typename T, typename Alloc>
        void vector<T, Alloc>::clear()
        {
            for (size_t i = 0; i < _size; i++){
                _alloc.destroy(_array + i);
            }
            _size = 0;
        }

        template <typename T, typename Alloc>
        typename::ft::vector<T, Alloc>::allocator_type      vector<T, Alloc>::get_allocator() const{
            return (_alloc);
        }

        template <typename T, typename Alloc>
        void vector<T, Alloc>::swap(vector & x){
            allocator_type  tmp_alloc = _alloc;
            T*  tmp_array = _array;
            size_type tmp_size = _size;
            size_type tmp_capacity = _capacity;

            _alloc = x._alloc;
            _array = x._array;
            _size = x._size;
            _capacity = x._capacity;

            x._alloc = tmp_alloc;
            x._array = tmp_array;
            x._size = tmp_size;
            x._capacity = tmp_capacity;
        }

        template <class T, class Alloc>
	    void swap (ft::vector<T,Alloc>& x, ft::vector<T,Alloc>& y)
	    {
		    x.swap(y);
	    }

        template <typename T, typename Alloc>
        bool operator== (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            if (one.size() != two.size()){
                return false;
            }
            return (ft::equal(one.begin(), one.end(), two.begin()) ? true : false);
        }

        template <typename T, typename Alloc>
        bool operator!= (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            return (!(one == two));
        }

        template <typename T, typename Alloc>
        bool operator< (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            return ft::lexicographical_compare(one.begin(), one.end(), two.begin(), two.end()) ? true :false;
        }

        template <typename T, typename Alloc>
        bool operator> (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            return two < one;
        }

        template <typename T, typename Alloc>
        bool operator<= (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            return !(one > two);
        }



        template <typename T, typename Alloc>
        bool operator>= (const ft::vector<T, Alloc>& one, const ft::vector<T, Alloc>& two){
            return !(one < two);
        }
}

#endif