#ifndef MAP_HPP
#define MAP_HPP
#include <iostream>
#include <memory>
#include <string>
#include "../util/utils.hpp"
#include "../map/pair.hpp"
#include "../map/binary_search_tree.hpp"
#include "../map/map_iterator.hpp"
#include "../vector/vector_iterator.hpp"

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
           class Alloc = std::allocator<ft::pair<const Key,T> >    // map::allocator_type
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
    public :
        typedef ft::map_iterator<value_type, node_type>                   iterator;
        typedef ft::map_iterator<const value_type, node_type>             const_iterator;
        typedef ft::reverse_iterator_tag<iterator>                  reverse_iterator;
        typedef ft::reverse_iterator_tag<const_iterator>            const_reverse_iterator;

        typedef ptrdiff_t   difference_type;
        typedef size_t      size_type;



        explicit map(const key_compare &comp = key_compare(), const allocator_type& alloc = allocator_type())
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
            BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(start->first, start->second), findRightNode(_Node), _size);
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
    typename map<Key, T, Compare, Alloc>::reverse_iterator      map<Key, T, Compare, Alloc>::rend(void)
    {
        return reverse_iterator(this->begin());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_reverse_iterator    map<Key, T, Compare, Alloc>::rend(void) const
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

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::mapped_type&      map<Key, T, Compare, Alloc>::operator[] (const key_type& k)
    {
        if (_size != 0 && BST_SearchNode<node_ptr, Key>(_Node, findRightNode(_Node), k))
            ;
        else 
        {
            BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(k), findRightNode(_Node), _size);
            _size++;
        }
        return (this->find(k)->second);
    }

    template <class Key, class T, class Compare, class Alloc>
    ft::pair<typename ft::map<Key, T, Compare, Alloc>::iterator, bool> ft::map<Key, T, Compare, Alloc>::insert (const value_type & val)
    {
        ft::pair<iterator, bool> res;

        res.second = 1;
        if (_size != 0 && BST_SearchNodeBool<node_ptr, Key>(_Node, findRightNode(_Node), val.first))
        {
            res.second = 0;
        }
        else
        {
            BST_InsertNode<value_type, key_compare>((&_Node), new_setNode(val.first, val.second), findRightNode(_Node), _size);
            _size++;
        }
        res.first = this->find(val.first);
        return (res);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::iterator  ft::map<Key, T, Compare, Alloc>::insert(iterator position, const value_type &val)
    {
        static_cast<void>(position);
        this->insert(val);
        return this->insert(val).first;
    }

    template <class Key, class T, class Compare, class Alloc>
    template <class InputIterator>
    void ft::map<Key, T, Compare, Alloc>::insert (InputIterator first, InputIterator last)
    {
        for (; first != last; first++)
            this->insert(*first);
    }

    template <class Key, class T, class Compare, class Alloc>
    void ft::map<Key, T, Compare, Alloc>::erase (iterator position, typename enable_if<!is_integral<iterator>::value, iterator>::type*)
    {
        erase((*position).first);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::size_type ft::map<Key, T, Compare, Alloc>::erase(const key_type& k)
    {
        iterator element = find(k);

        if (element == this->end())
            return (0);
        BST_RemoveNode(&(element._node), &_Node, _allocNode);
        _size--;
        return (1);
    }

    template <class Key, class T, class Compare, class Alloc>
    void ft::map<Key, T, Compare, Alloc>::erase(iterator first, iterator last)
    {
        for (; first != last; )
        {
            iterator next = first;
            next++;
            erase(first);
            first = next;
        }
    }

    template <class Key, class T, class Compare, class Alloc>
    void ft::map<Key, T, Compare, Alloc>::swap (ft::map<Key, T, Compare, Alloc>& x)
    {
        node_ptr tmp = x._Node;
        size_t tmp_size = x._size;

        x._Node = this->_Node;
        x._size = this->_size;

        this->_Node = tmp;
        this->_size = tmp_size;
    }

    template <class Key, class T, class Compare, class Alloc>
    void ft::map<Key, T, Compare, Alloc>::clear()
    {
        _size = 0;
        tree_clear(_Node);
        this->_Node = _allocNode.allocate(1);
        allocNode_construct(&_Node);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::key_compare ft::map<Key, T, Compare, Alloc>::key_comp() const
    {
        return (key_compare());
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::value_compare  ft::map<Key, T, Compare, Alloc>::value_comp() const
    {
        return (value_compare(key_compare()));
    }

    template <class Key, class T, class Compare, class Alloc>
    class map<Key, T, Compare, Alloc>::value_compare : binary_function<value_type, value_type, bool>
    {
    friend class map;
    protected:
        Compare comp;
        value_compare (Compare c) : comp(c) {}
    public:
        typedef bool result_type;
        typedef value_type first_args_type;
        typedef value_type second_args_type;
        bool operator() (const value_type& x, const value_type& y) const
        {
            return (comp(x.first, y.first));
        }
    };

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::find(const key_type &k)
    {
        iterator it = this->begin();
        iterator ite = this->end();

        while (it != ite)
        {
            if (this->_key_eq(it->first, k))
                break;
            ++it;
            if (it._node == NULL)
                break;
        }
        return (it);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::size_type map<Key, T, Compare, Alloc>::count (const key_type &k) const
    {
        return (BST_SearchNodeBool<node_ptr, Key> (_Node, findRightNode(_Node), k));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator  map<Key, T, Compare, Alloc>::lower_bound (const key_type&k)
    {
        iterator it = this->begin();
        iterator ite = this->end();

        while (it != ite)
        {
            if (!this->_k_comp(it->first, k))
                break;
            ++it;
        }
        return (it);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator    map<Key, T, Compare, Alloc>::lower_bound(const key_type &k) const
    {
        iterator it = this->begin();
        iterator ite =this->end();

        while (it != ite)
        {
            if (!this->_k_comp(it->first, k))
                break;
            ++it;
        }
        return (it);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::iterator      map<Key, T, Compare, Alloc>::upper_bound (const key_type& k)
    {
        iterator it = this->begin();
        iterator ite = this->end();

        while (it != ite)
        {
            if (this->_k_comp(k, it->first))
                break;
            ++it;
        }
        return (it);
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::const_iterator map<Key, T, Compare, Alloc>::upper_bound(const key_type & k) const
    {
        iterator it = this->begin();
        iterator ite = this->end();

        while (it != ite)
        {
            if (this->_k_comp(k, it->first))
                break;
            ++it;
        }
        return (it);
    }

    template <class Key, class T, class Compare, class Alloc>
    pair <typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>    map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
    {
        return (make_pair<const_iterator, const_iterator> (lower_bound(k), upper_bound(k)));
    }

    template <class Key, class T, class Compare, class Alloc>
    pair <typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>   map<Key, T, Compare, Alloc>::equal_range(const key_type &k)
    {
        return (pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
    }

    template <class Key, class T, class Compare, class Alloc>
    typename map<Key, T, Compare, Alloc>::allocator_type    map<Key, T, Compare, Alloc>::get_allocator() const
    {
        return (_alloc);
    }

    template<class Key, class T, class Compare, class Alloc>
    void map<Key, T, Compare, Alloc>::tree_clear(node_ptr node) {
        if (node == NULL)
            return ;
        this->tree_clear(node->leftNode);
        this->tree_clear(node->rightNode);
        this->_allocNode.deallocate(node, 1);
        node = NULL;
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::node_ptr  ft::map<Key, T, Compare, Alloc>::new_setNode(Key first)
    {
        node_ptr tmp = _allocNode.allocate(1);
        _allocNode.construct(tmp, node_type(pair<Key, T>()));
        tmp->data.first = first;
        return tmp;
    }

    template <class Key, class T, class Compare, class Alloc>
    typename ft::map<Key, T, Compare, Alloc>::node_ptr  ft::map<Key, T, Compare, Alloc>::new_setNode(Key first, T second)
    {
        node_ptr tmp = _allocNode.allocate(1);
        _allocNode.construct(tmp, node_type(pair<Key, T>(first, second)));
        allocNode_construct(&tmp);
        return tmp;
    }

    template <class Key, class T, class Compare, class Alloc>
    bool map<Key, T, Compare, Alloc>::_key_eq(const key_type &k1, const key_type &k2) const {
        return (!this->_k_comp(k1, k2) && !this->_k_comp(k2, k1));
    }

    template<class Key, class T, class Compare, class Alloc>
    template <class new_node_ptr>
    void    map<Key, T, Compare, Alloc>::allocNode_construct(new_node_ptr *Node)
    {
        (*Node)->parent = 0;
        (*Node)->leftNode = 0;
        (*Node)->rightNode = 0;
    }

    template<class Key, class T, class Compare, class Alloc>
    bool operator== (const ft::map<Key, T, Compare, Alloc>& first, const ft::map<Key, T, Compare, Alloc>& second)
    {
        if (first.size() != second.size())
            return false;
        return (ft::equal(first.begin(), first.end(), second.begin()) ? true : false);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator!= (const ft::map<Key, T, Compare, Alloc> &first, const ft::map<Key, T, Compare, Alloc>& second)
    {
        return (!(first == second));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator < (const ft::map<Key, T, Compare, Alloc> &first ,const ft::map <Key, T, Compare, Alloc>& second)
    {
        return (first > second);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator <= (const ft::map<Key, T, Compare, Alloc> & first, const ft::map<Key, T, Compare, Alloc> & second)
    {
        return (!(first > second));
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator > (const ft::map<Key, T, Compare, Alloc> & first, const ft::map<Key, T, Compare, Alloc> & second)
    {
        return (first < second);
    }

    template <class Key, class T, class Compare, class Alloc>
    bool operator >= (const ft::map<Key, T, Compare, Alloc> & first, const ft::map<Key, T, Compare, Alloc> & second)
    {
        return (!(first < second));
    }

    template <class Key, class T, class Compare , class Alloc>
    void swap (map<Key, T, Compare, Alloc> & x, map <Key, T, Compare , Alloc> & y)
    {
        x.swap(y);
    }
}

#endif