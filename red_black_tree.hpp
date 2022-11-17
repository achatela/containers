#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "pair.hpp"
# include "make_pair.hpp"
# include <functional>
# include "bidirectionnal_iterator.hpp"

# define BLACK 0
# define RED 1

namespace ft{

    template <class Key, class T>//, class Alloc = std::allocator<ft::pair<const Key, T>>
    class RBTree{

        public:

            struct Node
            {
                int color;
                ft::pair<Key, T> data;
                Node * leftChild;
                Node * rightChild;
                Node * parent;

                Node * sentinel;

                Key first;
                T second;
                
                Node* increment(Node* x){
                    Node * y = x;

                    while (y->parent != NULL)
                        y = y->parent;
                    while (y->rightChild != sentinel)
                        y = y->rightChild;
                    if (x == y)
                        return sentinel;
                    if (x->rightChild->data.first != Key()){

                        x = x->rightChild;

                        while (x->leftChild->data.first != Key()){
                            x = x->leftChild;
                        }
                    }
                    else{
                        Node* tmp = x->parent;

                        while (x == tmp->rightChild){
                            x = tmp;
                            tmp = tmp->parent;
                        }

                        if (x->rightChild != tmp)
                            x = tmp;
                    }
                    return x;
                }
            };

            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef std::less<key_type>                                     key_compare;
            typedef typename ft::bidirectionnal<Node*>                 iterator;
            typedef typename ft::bidirectionnal<const Node*>           const_iterator;
            // typedef Node                                       node;

        private:

            typedef Node                                                 *nodePtr;

            nodePtr         _root;
            nodePtr         _TNULL;
            key_compare     _compare;

        public:
        # include "map_display.hpp"

            nodePtr getRoot(){
                return _root;
            }

            RBTree(const key_compare& comp = key_compare()) : _compare(comp){
               _TNULL = new Node;

               _TNULL->color = BLACK;
               _TNULL->data = make_pair(key_type(), mapped_type());
               _TNULL->first = key_type();
               _TNULL->second = mapped_type();
               _TNULL->leftChild = NULL;
               _TNULL->rightChild = NULL;
               _root = _TNULL;
            };

            ~RBTree(){
                recursiveDelete(_root);
                delete _TNULL;
            }

            

            void recursiveDelete(nodePtr node){
                if (node->leftChild == NULL && node->rightChild == NULL)
                    return ;
                if (node->rightChild != NULL)
                    recursiveDelete(node->rightChild);
                if (node->leftChild != NULL)
                    recursiveDelete(node->leftChild);
                delete node;
            }

            void leftRotate(nodePtr node){
                nodePtr tmp = node->rightChild;

                node->rightChild = tmp->leftChild;
                if (tmp->leftChild != _TNULL)
                    tmp->leftChild->parent = node;
                tmp->parent = node->parent;
                if (node->parent == NULL)
                    _root = tmp;
                else if (node == node->parent->leftChild)
                    node->parent->leftChild= tmp;
                else
                    node->parent->rightChild = tmp;
                tmp->leftChild = node;
                node->parent = tmp;
            }

            void rightRotate(nodePtr node){
                nodePtr tmp = node->leftChild;

                node->leftChild = tmp->rightChild;
                if (tmp->rightChild != _TNULL)
                    tmp->rightChild->parent = node;
                tmp->parent = node->parent;
                if (node->parent == NULL)
                    _root = tmp;
                else if (node == node->parent->rightChild)
                    node->parent->rightChild = tmp;
                else
                    node->parent->leftChild = tmp;
                tmp->rightChild = node;
                node->parent = tmp;
            }

            void balanceTree(nodePtr node){
                nodePtr u;

                while (node->parent->color == RED){
                    if (node->parent == node->parent->parent->rightChild){
                        u = node->parent->parent->leftChild;
                        if (u->color == RED){
                            u->color = BLACK;
                            node->parent->color = BLACK;
                            node->parent->parent->color = RED;
                            node = node->parent->parent;
                        }
                        else{
                            if (node == node->parent->leftChild){
                                node = node->parent;
                                rightRotate(node);
                            }
                            node->parent->color = BLACK;
                            node->parent->parent->color = RED;
                            leftRotate(node->parent->parent);
                        }
                    }
                    else{
                        u = node->parent->parent->rightChild;

                        if (u->color == RED){
                            u->color = BLACK;
                            node->parent->color = BLACK;
                            node->parent->parent->color = RED;
                            node = node->parent->parent;
                        }
                        else{
                            if (node == node->parent->rightChild){
                                node = node->parent;
                                leftRotate(node);
                            }
                            node->parent->color = BLACK;
                            node->parent->parent->color = RED;
                            rightRotate(node->parent->parent);
                        }
                    }
                    if (node == _root)
                        break;
                }
                _root->color = BLACK;
            }


            void insert(ft::pair<const key_type, mapped_type> key){
                nodePtr node = new Node;
                node->parent = NULL;
                node->data = key;
                node->first = key.first;
                node->second = key.second;
                node->leftChild = _TNULL;
                node->rightChild = _TNULL;
                node->sentinel = _TNULL;
                node->color = RED;

                nodePtr y = NULL;
                nodePtr x = _root;

                while (x != _TNULL){
                    y = x;
                    if (_compare(node->data.first, x->data.first) == true)
                        x = x->leftChild;
                    else
                        x = x->rightChild;
                }
                node->parent = y;
                if (y == NULL)
                    _root = node;
                else if (_compare(node->data.first, y->data.first) == true)
                    y->leftChild = node;
                else
                    y->rightChild = node;
                if (node->parent == NULL){
                    node->color = BLACK;
                    return ;
                }
                if (node->parent->parent == NULL){
                    return ;
                }
                balanceTree(node);
            };

            iterator begin(){
                nodePtr x = _root;

                while (x->leftChild != _TNULL)
                    x = x->leftChild;
                return (iterator)x;
            }

            iterator end(){
                return (iterator)_TNULL;
            }
    };

};
#endif