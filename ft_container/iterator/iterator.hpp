#ifndef ITERATOR_HPP
#define ITERATOR_HPP
#include <iterator>
#include <stddef.h>

namespace ft {

        struct input_iterator_tag {};
        struct output_iterator_tag {};
        struct forward_iterator_tag : public input_iterator_tag{};
        struct bidirectional_iterator_tag : public forward_iterator_tag {};
        struct random_access_iterator_tag : public bidirectional_iterator_tag {};
        

        template <class Category, class T, class Distance = ptrdiff_t,
          class Pointer = T*, class Reference = T&>
            struct iterator {
                typedef T         value_type;
                typedef Distance  difference_type;
                typedef Pointer   pointer;
                typedef Reference reference;
                typedef Category  iterator_category;
            };
            
        template<typename Iterator>
            struct iterator_traits {
                typedef typename Iterator::difference_type      difference_type;
                typedef typename Iterator::value_type           value_type;
                typedef typename Iterator::pointer              pointer;
                typedef typename Iterator::reference            reference;
                typedef typename Iterator::iterator_category    iterator_category;
            };
        
        template<typename T>
            struct iterator_traits<T*> {
                typedef ptrdiff_t                      difference_type;
                typedef T                              value_type;
                typedef T*                             pointer;
                typedef T&                             reference;
                typedef random_access_iterator_tag     iterator_category;
            };
        
        template<typename T>
            struct iterator_traits<const T*> {
                typedef ptrdiff_t                      difference_type;
                typedef T                              value_type;
                typedef const T*                       pointer;
                typedef const T&                       reference;
                typedef random_access_iterator_tag     iterator_category;
            };
        
        template<typename _Iterator>
            typename ft::iterator_traits<_Iterator>::iterator_category iterator_category(const _Iterator&) {
                return typename ft::iterator_traits<_Iterator>::iterator_category();
            }

	template<typename _InputIterator>
		typename ft::iterator_traits<_InputIterator>::difference_type
		distance(_InputIterator first, _InputIterator last,
							 input_iterator_tag)
		{
			typename ft::iterator_traits<_InputIterator>::difference_type n = 0;
			while (first != last)
			{
				++first;
				++n;
			}
			return (n);
		}

	template<typename _RandomAccessIterator>
		typename ft::iterator_traits<_RandomAccessIterator>::difference_type
		distance(_RandomAccessIterator first, _RandomAccessIterator last,
							 random_access_iterator_tag)
		{
			return (last - first);
		}

	template<typename _InputIterator>
		inline
		typename ft::iterator_traits<_InputIterator>::difference_type
		distance(_InputIterator first, _InputIterator last)
		{
			return (ft::distance(first, last,
					 ft::iterator_category(first)));
		}

	template<typename _InputIterator, typename _Distance>
		inline void
		advance(_InputIterator& i, _Distance n, input_iterator_tag)
		{
			while (n--)
				++i;
		}

	template<typename _BidirectionalIterator, typename _Distance>
		inline void
		advance(_BidirectionalIterator& i, _Distance n,
				bidirectional_iterator_tag)
		{
			if (n > 0)
				while (n--)
					++i;
			else
				while (n++)
					--i;
		}

	template<typename _RandomAccessIterator, typename _Distance>
		inline void
		advance(_RandomAccessIterator& i, _Distance n,
							random_access_iterator_tag)
		{
			i += n;
		}

	template<typename _InputIterator, typename _Distance>
		inline void
		advance(_InputIterator& i, _Distance n)
		{
			typename ft::iterator_traits<_InputIterator>::difference_type d = n;
			ft::advance(i, d, ft::iterator_category(i));
		}

        template <typename _Iterator> 
            class reverse_iterator 
            : public iterator < typename ft::iterator_traits<_Iterator>::iterator_category,
                                typename ft::iterator_traits<_Iterator>::value_type,
                                typename ft::iterator_traits<_Iterator>::difference_type,
                                typename ft::iterator_traits<_Iterator>::pointer,
                                typename ft::iterator_traits<_Iterator>::reference>
            {
            protected:
                _Iterator curr;
                typedef ft::iterator_traits<_Iterator>      traits_type;
            
            public:
                typedef _Iterator                               iterator_type;
                typedef typename traits_type::difference_type   difference_type;
                typedef typename traits_type::pointer           pointer;
                typedef typename traits_type::reference         reference;
                reverse_iterator() : curr(){}
                reverse_iterator(iterator_type it) : curr(it) {}
                reverse_iterator(const iterator_type it) : curr(it){}

                template<typename _Iterator>
                    reverse_iterator(const reverse_iterator<_Iterator> & ri) : curr(ri.base()) {}

                iterator_type base() const {
                    return curr;
                }

                reference operator*() const {
                    _Iterator temp = curr;
                    return *(--temp);
                }

                reverse_iterator operator+ (difference_type n) const {
                    return reverse_iterator(curr - n);
                }

                reverse_iterator& operator++() {
                    return *this;
                }

                reverse_iterator  operator++(int) {
                    iterator_type temp = *this;
                    ++(*this);
                    return temp;
                }

                reverse_iterator& operator+= (difference_type n) {
                    curr -= n;
                    return *this;
                }

                reverse_iterator operator- (difference_type n) const {
                    return reverse_iterator(curr + n);
                }

                reverse_iterator& operator--() {
                    return *this;
                }

                reverse_iterator  operator--(int) {
                    iterator_type temp = *this;
                    --(*this);
                    return temp;
                }

                reverse_iterator& operator-= (difference_type n) {
                    curr += n;
                    return *this;
                }

                pointer operator->() const {
                    return &(operator*());
                }

                reference operator[] (difference_type n) const {
                    return *(*this + n);
                }
            };
            template <typename _Iterator>
                bool operator== (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() == second.base());
                }
            template <typename _Iterator>
                bool operator!= (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() != second.base());
                }
            template <typename _Iterator>
                bool operator<  (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() < second.base());
                }
            template <typename _Iterator>
                bool operator<= (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() <= second.base());
                }
            template <typename _Iterator>
                bool operator>  (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() > second.base());
                }
            template <typename _Iterator>
                bool operator>= (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second) {
                    return (first.base() >= second.base());
                }
            template <typename _Iterator>
                typename reverse_iterator<_Iterator>::difference_type operator- (const reverse_iterator<_Iterator>& first, const reverse_iterator<_Iterator>& second){
                    return (second.base() - first.base());
                }
            template <typename _Iterator>
                typename reverse_iterator<_Iterator> operator+ (typename reverse_iterator<_Iterator>::difference_type n, const reverse_iterator<_Iterator> & num){
                    return (reverse_iterator<_Iterator>(x.base() - n));
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator== (const reverse_iterator<_IteratorOne)& first, const reverse_iterator<_IteratorTwo>& second) {
                    return (first.base() == second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator!= (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (first.base() != second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator> (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (first.base() > second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator>= (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (first.base() >= second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator< (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (first.base() < second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                bool operator<= (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (first.base() <= second.base());
                }
            template <typename _IteratorOne, typename _IteratorTwo>
                typename reverse_iterator<_IteratorOne>::difference_type operator- (const reverse_iterator<_IteratorOne>& first, const reverse_iterator<_IteratorTwo>& second){
                    return (second.base() = first.base());
                }
        
        template<typename _Iterator, typename _Container>
            class iterator
            {
            protected:
                _Iterator curr;
                typedef ft::iterator_traits<_Iterator>              traits_t;
            public:
                typedef _Iterator                                   iterator_t;
                typedef typename traits_t::iterator_category        iterator_category;
                typedef typename traits_t::value_type               value_type;
                typedef typename traits_t::difference_type          difference_type;
                typedef typename traits_t::reference                reference;
                typedef typename traits_t::pointer                  pointer;

                iterator() : curr(_Iteraotr()) {}

                explicit
                iterator(const _Iterator& i) :curr(i){}

                reference operator* () const {
                    return (*curr);
                }

                pointer operator-> () const{
                    return (curr);
                }

                iterator& operator++ () {
                    ++curr;
                    return (*this);
                }

                iterator operator++ (int){
                    return (iterator(curr++));
                }

                iterator& operator-- () {
                    --curr;
                    return (*this);
                }

                iterator operator-- (int){
                    return (iterator(curr--));
                }

                reference operator[] (difference_type n) const{
                    return (curr[n]);
                }

                iterator& operator+= (difference_type n){
                    curr += n;
                    return (*this);
                }

                iterator& operaotr-= (difference_type n){
                    curr -= n;
                    return (*this);
                }

                iterator operator- (difference_type n) const {
                    return (iterator(curr - n));
                }

                iterator operator+ (difference_type n) const {
                    return (iterator(curr + n));
                }

                const _Iterator& base() const{
                    return (curr);
                }
            };
         template<typename _Iterator, typename _Container>
            bool operator== (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two){
                return (one.base() == two.base());
            }
        template<typename _Iterator, typename _Container>
            bool operator!= (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two){
                return (one.base() != two.base());
            }
        template<typename _Iterator, typename _Container>
            bool operator< (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>&two){
                return (one.base() < two.base());
            }
        template<typename _Iterator, tpyename _Container>
            bool operator<= (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two) {
                return (one.base() <= two.base());
            }
        template<typename _Iterator, typename _Container>
            bool operator> (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two) {
                return (one.base() > two.base());
            }
        template<typename _Iterator, typename _Container>
            bool operator>= (const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two){
                return (one.base() >= two.base());
            }
        template<typename _Iterator, typename _Container>
            typename iterator<_Iterator, _Container>::diiference_type operator-(const iterator<_Iterator, _Container>& one, const iterator<_Iterator, _Container>& two){
                return (one.base() - two.base());
            }
        template<typename _Iterator, typename _Container>
            iterator<_Iterator, _Container> operator+ (typename iterator<_Iterator, _Container>::difference_type n, const iterator<_Iterator, _Container>& num){
                return (iterator<_Iterator, _Container>(num.base() + n));
            }

        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator== (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() == two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator!= (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() != two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator< (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() < two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator< (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() < two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator<= (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() <= two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator> (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() > two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            bool operator>= (const iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container)& two){
                return (one.base() >= two.base());
            }
        template<typename _IteratorOne, typename _IteratorTwo, typename _Container>
            typename iterator<_IteratorOne, _Container>::difference_type operator- (cont iterator<_IteratorOne, _Container>& one, const iterator<_IteratorTwo, _Container>& two){
                return (one.base() - two.base());
            }
}
#endif