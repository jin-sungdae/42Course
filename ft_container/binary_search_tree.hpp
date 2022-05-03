#ifndef BINARY_SEARCH_TREE_HPP
#define BINARY_SEARCH_TREE_HPP
#include "pair.hpp"

namespace ft {
    template<typename T>
    struct Node{
        private:

        public:
        Node *parent;
        Node *leftNode;
        Node *rightNode;
        T   data;

        Node(const pair_t &src = pair_t()) : data(src),  parent(NULL), leftNOde(NULL), rightNode(NULL) {};
		template <typename pair_t>
		    Node& operator= (const Node<pair_t>& x);
    };
    
    template<typename T>
    template<typename pair_t>
    Node<T>& Node<T>::operator= (const Node<pair_t>& x){
        data.first = x.first;
		data.second = x.second;
		data.parent = x.parent;
		data.leftChild = x.leftChild;
		data.rightChild = x.rightChild;
    }

}

#endif