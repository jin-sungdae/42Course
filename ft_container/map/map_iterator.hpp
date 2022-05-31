#ifndef __MAP_ITERATOR_HPP__
#define __MAP_ITERATOR_HPP__

#include "../util/utils.hpp"

namespace ft
{
    template <typename T, typename node_type>
    class map_iterator
    {
    public :
        node_type   *_node;
        map_iterator(node_type *src);
        map_iterator(const map_iterator &vi);

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
  
        operator map_iterator<const T, node_type>(void) const {
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
    map_iterator<T, node_type>::map_iterator(const map_iterator &vi)
    {
        this->_node = vi._node;
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

    // template <class Key, class T, class Compare, typename Node, bool B>
    // class map_iterator
    // {

    //     public:
        
    //         typedef Key                                             key_type;
    //         typedef Compare                                         key_compare;
    //         typedef T                                               mapped_type;
            
    //         typedef ft::pair<const key_type, mapped_type>           value_type;
    //         typedef long int                                        difference_type;
    //         typedef size_t                                          size_type;
            
    //         typedef std::bidirectional_iterator_tag                                     iterator_category;
    //         typedef typename chooseConst<B, value_type&, const value_type&>::type       reference;
    //         typedef typename chooseConst<B, value_type*, const value_type*>::type       pointer;
    //         typedef Node*                                                               nodePtr;
            
    //     private:

    //         nodePtr         _node;      
    //         nodePtr         _lastElem;  
    //         key_compare     _comp;      

    //     public:

    //         map_iterator(nodePtr node = 0, nodePtr lastElem = 0, 
    //                     const key_compare& comp = key_compare()) :
    //             _node(node), _lastElem(lastElem), _comp(comp) {}
        

    //         map_iterator(const map_iterator<Key, T, Compare, Node, false>& copy)
    //         {
    //             _node = copy.getNode();
    //             _lastElem = copy.getLastElem();
    //             _comp = copy.getCompare();
    //         }
            
    //         ~map_iterator() {}

    //         map_iterator& operator=(const map_iterator& assign)
    //         {
    //             if (this != &assign)
    //             {
    //                 _node = assign._node;
    //                 _lastElem = assign._lastElem;
    //                 _comp = assign._comp;
    //             }
    //             return (*this);
    //         }

    //         nodePtr getNode() const             { return _node; }

    //         nodePtr getLastElem() const         { return _lastElem; }

    //         key_compare getCompare() const      { return _comp; }


            
    //         reference operator*() const         { return (_node->content); }
    //         pointer operator->() const          { return (&_node->content); }

    //         map_iterator& operator++()
    //         {

    //             nodePtr previousNode = _node;
    //             if (_node == _lastElem)
    //             {
    //                 _node = _lastElem->right;
    //                 return (*this);
    //             }

    //             while (_node != _lastElem && !_comp(previousNode->content.first, _node->content.first))
    //             {

    //                 if (_node->right && (_node->right == _lastElem || 
    //                         _comp(previousNode->content.first, _node->right->content.first)))

    //                 {
    //                     _node = _node->right;
                        
    //                     Node* tmp = 0;
    //                     if (_node != _lastElem && (tmp = searchMinNode(_node)))
    //                         _node = tmp;
    //                 }
    //                 else
    //                     _node = _node->parent;
    //             }
    //             return (*this);
    //         }

    //         map_iterator operator++(int)
    //         {

    //             map_iterator res(*this);

    //             if (_node == _lastElem)
    //             {
    //                 _node = _lastElem->right;
    //                 return (res);
    //             }
                
    //             while (_node != _lastElem && !_comp(res->first, _node->content.first))
    //             {
    //                 if (_node->right && (_node->right == _lastElem || 
    //                         _comp(res->first, _node->right->content.first)))
    //                 {
    //                     _node = _node->right;
                        
    //                     Node* tmp = 0;
    //                     if (_node != _lastElem && (tmp = searchMinNode(_node)))
    //                         _node = tmp;
    //                 }
    //                 else
    //                     _node = _node->parent;
    //             }
                
    //             return (res);
    //         }

    //         map_iterator& operator--()
    //         {
    //             nodePtr previousNode = _node;

    //             if (_node == _lastElem)
    //             {
    //                 _node = _lastElem->left;
    //                 return (*this);
    //             }

    //             while (_node != _lastElem && !_comp(_node->content.first, previousNode->content.first))
    //             {
    //                 if (_node->left && (_node->left == _lastElem || 
    //                         _comp(_node->left->content.first, previousNode->content.first)))
    //                 {
    //                     _node = _node->left;
                        
    //                     Node* tmp = 0;
    //                     if (_node != _lastElem && (tmp = searchMaxNode(_node)))
    //                         _node = tmp;
    //                 }
    //                 else
    //                     _node = _node->parent;
    //             }

    //             return (*this);
    //         }

    //         map_iterator operator--(int)
    //         {
    //             map_iterator res(*this);

    //             if (_node == _lastElem)
    //             {
    //                 _node = _lastElem->left;
    //                 return (res);
    //             }
                
    //             while (_node != _lastElem && !_comp(_node->content.first, res->first))
    //             {
    //                 if (_node->left && (_node->left == _lastElem || 
    //                         _comp(_node->left->content.first, res->first)))
    //                 {
    //                     _node = _node->left;
                        
    //                     Node* tmp = 0;
    //                     if (_node != _lastElem && (tmp = searchMaxNode(_node)))
    //                         _node = tmp;
    //                 }
    //                 else
    //                     _node = _node->parent;
    //             }
                
    //             return (res);
    //         }

    //         bool operator==(const map_iterator& it) const   { return (it._node == _node); }
    //         bool operator!=(const map_iterator& it) const   { return (it._node != _node); }

    //     private:

    //         Node* searchMaxNode(Node *root)
    //         {
    //             if (root && root != _lastElem && root->right && root->right != _lastElem)
    //                 return searchMaxNode(root->right);
    //             return root;
    //         }

    //         Node* searchMinNode(Node *root)
    //         {
    //             if (root && root != _lastElem && root->left && root->left != _lastElem)
    //                 return searchMinNode(root->left);
    //             return root;
    //         }
            
    // };

}

#endif