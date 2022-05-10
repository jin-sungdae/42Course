#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include "utils.hpp"
#include "pair.hpp"
#include "binary_search_tree.hpp"
#include "iterator/iterator.hpp"

namespace ft 
{

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
               private:

    public :
        typedef Key     key_type;
        typedef T       mapped_type;
        typedef pair<Key, T> value_type;
        typedef Compare     key_compare;
        class   value_compare;
        typedef Alloc       allocator_type;
        typedef typename    allocator_type::reference       reference;
        typedef typename    allocator_type::const_reference const_reference;
        typedef typename    allocator_type::pointer         pointer;
        typedef typename    allocator_type::const_pointer   const_pointer;

        // map = 이진트리 //
        typedef ft::Node<value_type>    node_type;
        typedef node_type*  node_ptr;
        
    private :
        node_ptr    _Node;
        std::allocator<node_type>   _allocNode;
        allocator_type  _alloc;
        key_compare _k_comp;
        size_t  _size;
        
        typedef ft::iterator<value_type, map>                   iterator;
        typedef ft::iterator<const value_type, map>             const_iterator;
        typedef ft::reverse_iterator<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator<const_iterator>            const_reverse_iterator;

        typedef ptrdiff_t   difference_type;
        typedef size_t      size_type;



        explict map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type())
        : _Node(0), _alloc(alloc), _k_comp(comp), _size(0)
        {
            this->_Node = _allocNode.allocate(1);
            allocNode_construct(&_Node);
        };

        template <class InputIterator>
        map (InputIterator first, InputIterator last, const key_compare& _comp = key_compare(), const allocator_type & alloc = allocator_type())
        : _Node(0), _alloc(alloc), _k_comp(_comp), _size(0)
        {
            this->_Node = _allocNode.allocate(1);
            allocNode_construct(&_Node);
            insert(first, last);
        };

        map (const map& x) : _Node(0), _alloc(x._alloc), _k_comp(x._k_comp), _size(0)
        {
            this->_Node = _allocNode.allocate(1);
            allocNode_construct(&_Node);
            (*this) = x;
        };
        ~map (void)
        {
            clear();
            this->_allocNode.deallocate(_Node, 1);
        }

        // operator= //
        map& operator= (const map& x);

        // ** Iterators ** //
        iterator begin();
        const_iterator begin() const;
        iterator end();
        const_iterator end() const;
        reverse_iterator rbegin();
        const_reverse_iterator rbegin() const;
        reverse_iterator rend();
        const_reverse_iterator rend() const;
    
        // ** capacity ** //
        bool empty() const;
        size_type size() const;
        size_type max_size() const;

        // ** Element access ** //
        // operatro[]
        mapped_type& operator[] (const key_type& k);

        // ** Modifiers ** //
        pair<iterator, bool> insert(const value_type& val);
        iterator insert (iterator position, const value_type& val);
        template <class InputIterator>
        void insert (InputIterator first, InputIterator last);

        void erase(iterator position, typename ft::enable_if<!ft::is_integral<iterator>::value, iterator>::type* = nullptr);
        size_type erase (const key_type& k);
        void erase (iterator first, iterator last);
        void swap(map& x);
        void clear();

        // ** Observers ** //
        key_compare key_comp() const;
        value_compare value_comp() const;

        // ** Operations ** //
        iterator find(const key_type& k);
        const_iterator find(const key_type& k) const;
        size_type count(const key_type& k)const;
        iterator lower_bound(const key_type& k);
        const_iterator lower_bound(const key_type& k) const;
        iterator upper_bound(const key_type & k);
        const_iterator upper_bound(const key_type& k) const;
        pair<iterator, iterator> equal_range(const key_type & k);
        pair<const_iterator, const_iterator> equal_range(const key_type& k) const;

        allocator_type  get_allocator() const;
        // ** Allocator ** //
        
    private:
        bool _key_eq(const key_type &k1, const key_type &k2) const;
        node_ptr new_setNode(Key first);
        node_ptr new_setNode(Key first, T second);
        void tree_clear(node_ptr node);

        template <class node_ptr>
        void    allocNode_construct(node_ptr *Node);
    };

    template <class Key, class T, class Compare, class Alloc>
    ft::map<Key, T, Compare, Alloc>& ft::map<Key, T, Compare, Alloc>::operator= (const map &x)
    {
        if (this == &x)
            return (*this);
        this->clear();
        iterator start = x.begin();
        iterator last = x.end();
        for (; start != last; start++)
        {
            BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(start->first, start->second), maxNode(_Node), _size);
            _size++;
        }
        return (*this);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::begin(void)
    {
        return (iterator(findLeftNode(_Node)));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::begin(void) const
    {
        return const_iterator(findLeftNode(_Node));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::end(void)
    {
        return (findRightNode(_Node));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::end(void) const
    {
        return (findRightNode(_Node));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator  map<Key, T, Compare, Alloc>::rbegin(void)
    {
        return reverse_iterator(this->end());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rbegin(void) const
    {
        return const_reverse_iterator(this->end());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::reverse_iterator  map<Key, T, Compare, Alloc>::rend(void)
    {
        return reverse_iterator(this->begin());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator map<Key, T, Compare, Alloc>::rend(void) const
    {
        return const_reverse_iterator(this->begin());
    }

    template<class Key, class T, class Compare, class Alloc>
    bool    map<Key, T, Compare, Alloc>::empty() const
    {
        if (_size == 0) return (1);
        return (0);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::size() const
    {
        return (_size);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type  map<Key, T, Compare, Alloc>::max_size() const
    {
        return (this->_allocNode.max_size());
    }
}

#endif