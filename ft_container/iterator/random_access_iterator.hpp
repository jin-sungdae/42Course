#ifndef RANDOM_ACCESS_ITERATOR_HPP
#define RANDOM_ACCESS_ITERATOR_HPP


namespace ft{
    template<typename T>
    class random_access_iterator : ft::iterator<random_access_iterator_tag, T>{
        public :
            typedef typename ft::iterator<ft::random_access_iterator_tag, T>
    };
}

#endif