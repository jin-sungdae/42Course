#ifndef VECTOR_ITERATOR_HPP
#define VECTOR_ITERATOR_HPP
#include <iostream>

namespace ft
{
    template<bool, typename T = void>
    struct enable_if {};

    template <typenmae T>
    struct enable_if <true, T>
    {
        typedef T type;
    };

    template<typename T, bool _bool>
    struct integral_constant
    {
        typedef bool value_type;
        typedef T type;
        static const value_type value = _bool;
    };

    template <class Ty>
    struct is_integral : public integral_constant<T, false> {} ;
    template <>
    struct is_integral<bool> : public integral_constant<bool, true> {};
    template <>
    struct is_integral<char> : public integral_constant<char, true> {};
     template <>
    struct is_integral<unsigned char> : public integral_constant<unsigned char, true> {};
     template <>
    struct is_integral<signed char> : public integral_constant<signed char, true> {};
     template <>
    struct is_integral<wchar_t> : public integral_constant<wchar_t true> {};
     template <>
    struct is_integral<short> : public integral_constant<short, true> {};
     template <>
    struct is_integral<unsigned short> : public integral_constant<unsigned short, true> {};
     template <>
    struct is_integral<int> : public integral_constant<int, true> {};
     template <>
    struct is_integral<unsigned int> : public integral_constant<unsigned int, true> {};
     template <>
    struct is_integral<long> : public integral_constant<long, true> {};
     template <>
    struct is_integral<unsigned long> : public integral_constant<unsigned long, true> {};
    template <>
    struct is_integral<short int> : public integral_constant<short int, true>{};
    template <>
    struct is_integral<long int> : public integral_constant<long int, true> {};
    template <>
    struct is_integral<long long int> : public integral_constant<long long int, true>{};
    template <>
    struct is_integral <unsigned short int> : public integral_constant<unsgined short int, true> {};
    template<>
	struct is_integral<unsigned long int> : public integral_constant<unsigned long int, true> {} ;
	template<>
	struct is_integral<unsigned long long int> : public integral_constant<unsigned long long, true> {} ;
	template<>
	struct is_integral<char *> : public integral_constant<char *, true> {} ;
	template<>
	struct is_integral<std::string> : public integral_constant<std::string, true> {} ;

    struct input_iterator_tag {};
    struct output_iterator_tag {};
    struct forward_iterator_tag : public input_iterator_tag, output_iterator_tag {};
    struct bidirectional_iterator_tag : public forward_iterator_tag {};
    struct random_access_iterator_tag : public bidirectional_iterator_tag {};

    template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    struct iterator
	{
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
	};

    template <typename Iterator> 
    struct iterator_traits
    {
        typedef typename iterator::value_type            value_type;
		typedef typename iterator::difference_type       difference_type;
		typedef typename iterator::pointer               pointer;
		typedef typename iterator::reference             reference;
    };

    template <typename T> 
    struct iterator_traits<T*>
    {
        typedef T                                       value_type;
        typedef T*                                      pointer;
        typedef T&                                      reference;
        typedef ptrdiff_t                               difference_type;
    };

    template <typename T>
    struct iterator_traits<const T*>
    {
        typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef	ptrdiff_t								difference_type;
    };

    template <typename T, class InputIterator>
    typename iterator_traits<T*>::difference_type   distance(InputIterator first, InputIterator last)
    {
        typename iterator_traits<T*>::difference_type res = 0;
        while (first != last)
        {
            first++;
            res++;
        }
        return res;
    }

    template <typename RandomIterator>
    class vector_iterator : public iterator<std::random_access_iterator_tag, RandomIterator>
    {
    public :
        typedef RandomIterator                                                      iterator_type;
        typedef typename iterator_traits<iterator_type*>::value_type                value_type;
        typedef typename iterator_traits<iterator_type*>::difference_type           difference_type;
        typedef typename iterator_traits<iterator_type*>::pointer                   pointer;
        typedef typename iterator_traits<iterator_type*>::reference                 reference;
        RandomIterator*                                                             _ptr;

        vector_iterator() : _ptr(0) {};
        vector_iterator(RandomIterator *ptr) : _ptr(ptr) {};
        vector_iterator(const vector_iterator &vi) : _ptr(vi._ptr) {};

        template <typename T>
        bool        operator==(const vector_iterator<T> & vi) const;
        template <typename T>
        bool        operator!=(const vector_iterator<T> & vi) const;
        RandomIterator&     operator*() const;
        RandomIterator*     operator->() const;

        vector_iterator&    operator--();
        vector_iterator     operator--(int);
        vector_iterator&    operator==(const vector_iterator &vi)
        {
            if (this == &vi)
                return (*this);
            this->_ptr = vi._ptr;
            return (*this);
        }
        vector_iterator&    operator++();
        vector_iterator     operator++(int);
        vector_iterator     operator+(difference_type n) const;
        vector_iterator     operator-(difference_type n) const;
        template<typename T>
        difference_type     operator-(const vector_iteratorT> &vi) const;
        template<typename T>
        difference_type     operator+(const vector_iteratorT> &vi) const;
        template<typename T>
        bool                operator<(const vector_iterator<T> & vi) const;
        template<typename T>
        bool                operator>(const vector_iterator<T> & vi) const;
        template<typename T>
        bool                operator<=(const vector_iterator<T> & vi) const;
        template<typename T>
        bool                operator>=(const vector_iterator<T> & vi) const;
        vector_iterator&    operator+=(difference_type n);
        vecotr_iterator&    operator-=(difference_type n);
        RandomIterator& operator[](const difference_type n) const;
        operator vector_iterator<const RandomIterator> () const
        {
            return (vector_iterator<const RandomIterator>(this->_ptr));
        }
    };

    template <typename RandomIterator>
    template <typename T>
    bool    vector_iterator<RandomIterator>::operator==(const vector_iterator<T> &vi) const
    {
        return (this->_ptr == vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    bool    vector_iterator<RandomIterator>::operator!=(const vector_iterator<T> &vi) const
    {
        return (this->_ptr != vi._ptr);
    }

    template <typename RandomIterator>
    RandomIterator&     vector_iterator<RandomIterator>::operator*() const
    {
        return (*(this->_ptr));
    }

    template <typename RandomIterator>
    RandomIterator*     vector_iterator<RandomIterator>::operator->() const
    {
        return (this->_ptr);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator>&    vector_iterator<RandomIterator>::operator--()
    {
        --(this->_ptr);
        return (*this);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator>    vector_iterator<RandomIterator>::operator--(int)
    {
        vector_iterator<RandomIterator> tmp(*this);
        (this->_ptr)--;
        return (tmp);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator>&    vector_iterator<RandomIterator>::operator++()
    {
        ++(this->_ptr);
        return (*this);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator>    vector_iterator<RandomIterator>::operator++(int)
    {
        vector_iterator<RandomIterator> tmp(*this);
        (this->_ptr)++;
        return (tmp);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator> vector_iterator<RandomIterator>::operator+(difference_type n) const
    {
        return vector_iterator<RandomIterator> (this->_ptr + n);
    }

    template <typename RandomIterator>
    vector_iterator<RandomIterator> vector_iterator<RandomIterator>::operator-(difference_type n) const
    {
        return vector_iterator<RandomIterator> (this->_ptr - n);
    }

    template <typename RandomIterator>
    template <typename T>
    typename iterator_traits<RandomIterator*>::difference_type vector_iterator<RandomIterator>::operator-(const vector_iterator<T> & vi)
    {
        return (this->_ptr - vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    typename iterator_traits<RandomIterator*>::difference_type vector_iterator<RandomIterator>::operator+(const vector_iterator<T> & vi)
    {
        return (this->_ptr + vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    bool vector_iterator<RandomIterator>::operator<(const vector_iterator<T> &vi) const
    {
        return (this->_ptr < vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    bool vector_iterator<RandomIterator>::operator<=(const vector_iterator<T> &vi) const
    {
        return (this->_ptr <= vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    bool vector_iterator<RandomIterator>::operator>(const vector_iterator<T> &vi) const
    {
        return (this->_ptr > vi._ptr);
    }

    template <typename RandomIterator>
    template <typename T>
    bool vector_iterator<RandomIterator>::operator>=(const vector_iterator<T> &vi) const
    {
        return (this->_ptr >= vi._ptr);
    }

    template<typename RandomIterator>
    vector_iterator<RandomIterator>& vector_iterator<RandomIterator>::operator+=(difference_type n)
    {
        this->_ptr = this->_ptr + n;
        return (*this);
    }

    template<typename RandomIterator>
    vector_iterator<RandomIterator>& vector_iterator<RandomIterator>::operator-=(difference_type n)
    {
        this->_ptr = this->_ptr - n;
        return (*this);
    }

    template <typename RandomIterator>
    RandomIterator& vector_iterator<RandomIterator>::operator[] (const difference_type n) const
    {
        return (*(this->_ptr + n));
    }

    template <class Iterator>
    class reverse_iterator_tag
    {
    public :
        typedef Iterator                                                    iterator_type;
        typedef typename    iterator_traits<Iterator>::value_type           vluae_type;
        typedef typename    iterator_traits<Iterator>::difference_type      difference_type;
        typedef typename    iterator_traits<Iterator>::pointer              pointer;
        typedef typename    iterator_traits<Iterator>::reference            reference;

    private:
        iterator_type   _ptr;
    public:
        reverse_iterator_tag() : _ptr() {};
        reverse_iterator_tag(iterator_type ptr) : _ptr(ptr);
        template<class T>
        reverse_iterator_tag(const reverse_iterator_tag<T> & rit) : _ptr(rit.base()) {};
        virtual ~reverse_iterator_tag() {}

        reference operator*() const
        {
            iterator_type tmp = _ptr;
            return (*(--tmp));
        }

        reverse_iterator_tag operator+(difference_type n) const
        {
            return (reverse_iterator_tag(_ptr - n));
        }

        reverse_iterator_tag& operator++()
        {
            --_ptr;
            return (*this);
        }

        reverse_iterator_tag operator++(int) {
            reverse_iterator_tag rit = *this;
            ++(*this);
            return (rit);
        }

        reverse_iterator_tag& operator+= (difference_type n)
        {
            _ptr -= n;
            return (*this);
        }

        reverse_iterator_tag operator- (difference_type n) const
        {
            return (reverse_iterator_tag(_ptr + n));
        }

        reverse_iterator_tag& operator-- ()
        {
            ++_ptr;
            return (*this);
        }

        reverse_iterator_tag operator-- (int) 
        {
            reverse_iterator_tag rit = *this;
            ++(_ptr);
            return (rit);
        }

        reverse_iterator_tag& operator-=(difference_type n)
        {
            _ptr += n;
            return (*this);
        }

        pointer operator->() const
        {
            return &(operator*());
        }

        reference operator[] (difference_type n) const
        {
            return *this->operator+(n);
        }
        iterator_type base() const
        {
            return (this->_ptr);
        }
    };

    template <class iterator>
    reverse_iterator_tag<Iterator> operator+ (typename reverse_iterator_tag<Iterator>::difference_type n, const reverse_iterator_tag<Iterator>& rit)
    {
        return (reverse_iterator_tag<Iterator>(rit.base() - n));
    }

    template <class iterator1, class iterator2>
    bool operator== (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() == rhs.base());
    }

    template <class iterator1, class iterator2>
    bool operator!= (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() != rhs.base());
    }

    template <class iterator1, class iterator2>
    bool operator> (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() < rhs.base());
    }

    template <class iterator1, class iterator2>
    bool operator>= (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() <= rhs.base());
    }

    template <class iterator1, class iterator2>
    bool operator< (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() > rhs.base());
    }

    template <class iterator1, class iterator2>
    bool operator<= (const reverse_iterator_tag<iterator1> & lhs, const reverse_iterator_tag<iterator2> & rhs)
    {
        return (lhs.base() >= rhs.base());
    }

}

#endif