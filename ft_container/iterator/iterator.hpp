#ifndef ITERATOR_HPP
#define ITERATOR_HPP

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

           template <class iterator> 
                    class reverse_iterator{
                    public :
                        typedef iterator        iterator_type;
                        typedef typename ft::iterator_traits<Iterator>::iterator_category    iterator_category;
                        typedef typename iterator_traits<Iterator>::value_type           value_type;
                        typedef typename iterator_traits<Iterator>::difference_type      difference_type;
                        typedef typename iterator_traits<Iterator>::pointer              pointer;
                        typedef typename iterator_traits<Iterator>::reference            reference;

                        reverse_iterator() :_elem(){}
                        ~reverse_iterator();
                        explicit reverse_iterator (iterator_type it) : _elem(it){}

                        template <class Iter>
                            reverse_iterator (const reverse_iterator<Iter>& rev_it) : _elem(rev_it.base());

                        iterator_type base() const {
                            return _elem;
                        }

                        reference operator*() const {
                            iterator_type temp = _elem;
                            return *(--temp);
                        }

                        reverse_iterator operator+ (difference_type n) const {
                            return reverse_iterator(_elem - n);
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
                            _elem -= n;
                            return *this;
                        }

                        reverse_iterator operator- (difference_type n) const {
                            return reverse_iterator(_elem + n);
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
                            _elem += n;
                            return *this;
                        }

                        pointer operator->() const {
                            return &(operator*());
                        }

                        reference operator[] (difference_type n) const {
                            return this->base()[-n - 1];
                        }
                            
                        private :
                            iterator_type   _elem;
                    };
                    template <class Iterator>
                        bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() == rhs.base();)
                        }
                    template <class Iterator>
                        bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() != rhs.base();)
                        }
                    template <class Iterator>
                        bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() < rhs.base();)
                        }
                    template <class Iterator>
                        bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() <= rhs.base();)
                        }
                    template <class Iterator>
                        bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() >rhs.base();)
                        }
                    template <class Iterator>
                        bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs) {
                            return (lhs.base() >= rhs.base();)
                        }
                    template <class Iterator>
                        reverse_iterator<Iterator> operator+ (typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator>& rev_it){
                            return (rev_it + n);
                        }
                    template <class Iterator>
                        typename reverse_iterator<Iterator>::difference_type operator- ( const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs){
                            return (lhs.base() - rhs.base());
                        }
}
#endif