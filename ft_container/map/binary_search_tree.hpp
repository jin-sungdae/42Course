#ifndef __BINARY_SEARCH_TREE_HPP__
#define __BINARY_SEARCH_TREE_HPP__
#include "pair.hpp"
#include <iostream>
#include "../util/utils.hpp"
#include <string>

namespace ft {
    template<typename T>
    struct Node{
        private:
        // bool _unused;
        // #if __APPLE__ == 0
        //     int _unused_for_linux;
        // #endif
        
        public:
        T   data;
        Node *parent;
        Node *leftNode;
        Node *rightNode;
        

        Node(const T &src = T()) : data(src),  parent(NULL), leftNode(NULL), rightNode(NULL) {};
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

    template <typename Node>
    Node* findLeftNode(Node * tree){
       
        while (tree->leftNode != NULL)
            tree = tree->leftNode;
        return (tree);
    }


    template <typename Node>
    Node* findRightNode(Node* tree){
        while (tree->rightNode != NULL)
            tree = tree->rightNode;
        return (tree);
    }

    template <class node_ptr, typename Key>
    bool BST_SearchNodeBool(node_ptr tree, node_ptr endNode, Key target){
        if (tree == NULL || tree == endNode)
            return false;
        if (tree->data.first == target)
            return true;
        else if (tree->data.first >target)
            return BST_SearchNodeBool(tree->leftNode, endNode, target);
        else
            return BST_SearchNodeBool(tree->rightNode, endNode, target);
        return true;
    }

    template <class node_ptr, typename Key>
    node_ptr BST_SearchNode (node_ptr tree, node_ptr endNode, Key target)
    {
        if (tree == NULL || tree == endNode)
            return NULL;
        if (tree->data.first == target)
            return tree;
        else if (tree->data.first > target)
            return BST_SearchNode(tree->leftNode, endNode, target);
        else
            return BST_SearchNode(tree->rightNode, endNode, target);
    }

    // ================================ AVL ============================== //
    template <class node>
    int height(node temp)
    {
        int h = 0;
        if (temp != NULL)
        {
            int left = height(temp->leftNode);
            int right = height(temp->rightNode);
            int maxHeight = max(left, right);
            h = maxHeight + 1;
        }
        return h;
    }

    template <class node>
    int diff(node temp)
    {
        int left = height(temp->left);
        int right = height(temp->right);
        int factor = left - right;
        return factor;
    }

    template <class node_ptr>
    node_ptr LL_Rotation(node_ptr tree)
    {
        node_ptr temp;
        temp = tree->left;
        tree->left = temp->right;
        temp->right = tree;
        return temp;
    }

    template <class node_ptr>
    node_ptr LR_Rotation(node_ptr tree)
    {
        node_ptr temp;
        temp = tree->left;
        tree->left = RR_Rotation(temp);
        return LL_Rotation(tree);
    }

    template <class node_ptr>
    node_ptr RR_Rotation(node_ptr tree)
    {
        node_ptr temp;
        temp = tree->right;
        tree->right = temp->left;
        temp->left = tree;
        return temp;
    }

    template <class node_ptr>
    node_ptr RL_Rotation(node_ptr tree)
    {
        node_ptr temp;
        temp = tree->right;
        tree->right = LL_Rotation(temp);
        return RR_Rotation(tree);
    }

    template <class node_ptr>
    node_ptr Balance(node_ptr temp)
    {
        int factor = diff(temp);
        if (factor > 1)
        {
            if (diff(temp->left) > 0)
            {
                temp = LL_Rotation(temp);
            }
            else
            {
                temp = LR_Rotation(temp);
            }
        }
        else if (factor < -1)
        {
            if (diff(temp->right) > 0)
            {
                temp = RL_Rotation(temp);
            }
            else
            {
                temp = RR_Rotation(temp);
            }
        }
        return temp;
    }

    template <typename pair_t, typename key_compare>
    void BST_InsertNode (Node<pair_t> **tree, Node<pair_t> * node, Node<pair_t> *endNode, size_t _size)
    {
        key_compare     k_comp; 
        node->rightNode = 0;
        node->leftNode = 0;

        if (_size == 0){
            *tree = node;
            endNode->parent = (*tree);
            (*tree)->rightNode = endNode;
            return ;
        }
        if (node->data.first != (*tree)->data.first)
            node->parent = (*tree);
        if (k_comp(node->data.first, (*tree)->data.first))
        {
            if ((*tree)->leftNode == NULL){
                (*tree)->leftNode = node;
                return ;
            }
            else 
            {
                BST_InsertNode<pair_t, key_compare>(&(*tree)->leftNode, node, endNode, _size);
            }
        }
        else if (!k_comp(node->data.first, (*tree)->data.first))
        {
            if ((*tree)->rightNode == endNode)
            {
                node->parent = (*tree);
                (*tree)->rightNode = node;
                node->rightNode = endNode;
                endNode->parent = (node);
                return ;
            }
            else if ((*tree)->rightNode == NULL)
            {
                node->parent = (*tree);
                (*tree)->rightNode = node;
            }
            else 
            {
                BST_InsertNode<pair_t, key_compare>(&(*tree)->rightNode, node, endNode, _size);
            }
        }
    }
    template <typename pair_t, typename alloc_T>
	void Null_deallocate(Node<pair_t>* tree, alloc_T &_allocNode)
	{
		_allocNode.deallocate(tree, 1);
		tree = NULL;
	}

    template <typename node_ptr, typename alloc_t>
    void BST_RemoveNode(node_ptr *deleteNode, node_ptr *node, alloc_t allocNode) {
        node_ptr temp = NULL;
        node_ptr *deleteTemp = node;

        if ((*deleteNode)->parent)
            deleteTemp = ((*deleteNode)->parent->leftNode == (*deleteNode) ? &(*deleteNode)->parent->leftNode : &(*deleteNode)->parent->rightNode);
        if ((*deleteNode)->leftNode == NULL && (*deleteNode)->rightNode == NULL)
            ;
        else if ((*deleteNode)->leftNode == NULL)
            temp = (*deleteNode)->rightNode;
        else
        {
            temp = findRightNode((*deleteNode)->leftNode);
            if (temp != (*deleteNode)->leftNode)
                if ((temp->parent->rightNode = temp->leftNode))
                    temp->leftNode->parent = temp->parent;
        }
        if (temp)
        {
            temp->parent = (*deleteNode)->parent;
            if ((*deleteNode)->leftNode && (*deleteNode)->leftNode != temp)
            {
                temp->leftNode = (*deleteNode)->leftNode;
                temp->leftNode->parent = temp;
            }
            if ((*deleteNode)->rightNode && (*deleteNode)->rightNode != temp)
            {
                temp->rightNode = (*deleteNode)->rightNode;
                temp->rightNode->parent = temp;
            }
        }
        *deleteTemp = temp;
        allocNode.deallocate((*deleteNode), 1);
    }   
}

#endif