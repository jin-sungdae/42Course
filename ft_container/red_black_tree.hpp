#ifndef RED_BLACK_TREE_HPP
#define RED_BLACK_TREE_HPP

#include <iostream>
#include "map.hpp";

namespace ft{
    template <typename T, class Alloc = std::allocator<T>>
    struct RedBlackNode;

    template <typename T, class Compare = less<T>, class Alloc = std::allocator<T>>
    class RedBlackTree;

    template <typename T, class Compare, class Alloc>
    bool operator==(RedBlackTree<T, Compare, Alloc> const& lhs, RedBlackTree<T, Compare, Alloc> const& rhs);

    template <typename T, class Compare, class Alloc, class Value_Compare, bool Same_Compare>
    bool operator<(RedBlackTree<T, Compare, Alloc> const& lhs, RedBlackTree<T, Compare, Alloc> const& rhs);

    
}


#endif