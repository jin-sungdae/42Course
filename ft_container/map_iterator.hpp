#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "utils.hpp"

namespace ft
{
    template <typename T, typename node_type>
    class map_iterator
    {
    public :
        node_type   *_node;
        map_iterator(node_type *src);
    
        typedef T                   value_type;
        typedef ptrdiff_t           difference_type;
        typedef value_type&         reference;
        typedef value_type*         pointer;

        map_iterator(void);

        template <typename mapIt>
        map_iterator(const mapIt &it);

        virtual ~map_iterator(void);
        map_iterator &operator=(map_iterator const & map);
        template <class U>
        bool operator==(const map_iterator<U, node_type> &map) const;
        template <class U>
        bool operator!=(const map_iterator<U, node_type> &map) const;

        map_iterator    &operator++(void);
        map_iterator    operator++(int);
        map_iterator    &operator--(void);
        map_iterator    operator--(int);

        reference       operator*(void) const;
        pointer         operator->(void) const;
        operator map_iterator<const T, node_type>(void) const
        {
            return map_iterator<const T, node_type>(this->_node);
        }
    };

    template <typename T, typename node_type>
    map_iterator<T, node_type>::map_iterator(void) : _node(NULL) {}

    template <typename T, typename node_type>
    map_iterator<T, node_type>::map_iterator(node_type *src)
    {
        this->_node = src;
    }
    
    template <typename T, typename node_type>
    template <typename mapIt>
    map_iterator<T, node_type>::map_iterator(const mapIt &it)
    {
        this->_node = it._node;
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type>::~map_iterator(void) 
    {
        return ;
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type> &map_iterator<T, node_type>::operator=(const map_iterator &a)
    {
        if (this == &a)
            return (*this);
        this->_node = a._node;
        return (*this);
    }

    template <typename T, typename node_type>
    template <class U>
    bool    map_iterator<T, node_type>::operator==(const map_iterator<U, node_type> & a) const
    {
        return (this->_node == a._node);
    }

    template <typename T, typename node_type>
    template <class U>
    bool    map_iterator<T, node_type>::operator!=(const map_iterator<U, node_type> & a) const
    {
        return (this->_node != a._node);
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type> &map_iterator<T, node_type>::operator++(void)
    {
        if (this->_node->rightNode != NULL)
        {
            this->_node = findLeftNode(this->_node->rightNode);
        }
        else
        {
            node_type *child = this->_node;

            this->_node = this->_node->parent;
            while (this->_node && child == this->_node->rightNode)
            {
                child = this->_node;
                this->_node = this->_node->parent;
            }
        }
        return (*this);
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type>  map_iterator<T, node_type>::operator++(int)
    {
        map_iterator    tmp(*this);
        ++(*this);
        return (tmp);
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type>& map_iterator<T, node_type>::operator--(void)
    {
        if (this->_node->leftNode != NULL)
        {
            this->_node = findRightNode(this->_node->leftNode);
        }
        else
        {
            node_type *child = this->_node;
            this->_node = this->_node->parent;
            while (this->_node && child == this->_node->leftNode)
            {
                child = this->_node;
                this->_node = this->_node->parent;
            }
        }
        return (*this);
    }

    template <typename T, typename node_type>
    map_iterator<T, node_type>  map_iterator<T, node_type>::operator--(int)
    {
        map_iterator    tmp(*this);
        --(*this);
        return (tmp);
    }

    template <typename T, typename node_type>
    typename map_iterator<T, node_type>::reference  map_iterator<T, node_type>::operator*(void) const
    {
        return (this->_node->data);
    }

    template <typename T, typename node_type>
    typename map_iterator<T, node_type>::pointer    map_iterator<T, node_type>::operator->(void) const
    {
        return &(this->operator*());
    }
}

#endif