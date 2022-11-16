#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "pair.hpp"
# include "make_pair.hpp"
# include <functional>

# define BLACK 0
# define RED 1

namespace ft{

    template <class Key, class T>//, class Alloc = std::allocator<ft::pair<const Key, T>>
    class RBTree{

        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef std::less<key_type>                                     key_compare;

        private:

            struct Node
            {
                int color;
                ft::pair<key_type, mapped_type> data;
                Node * leftChild;
                Node * rightChild;
                Node * parent;
            };

            typedef Node                                                 *nodePtr;

            nodePtr         _root;
            nodePtr         _TNULL;
            key_compare     _compare;

        public:

            RBTree(const key_compare& comp = key_compare()) : _compare(comp){
               _TNULL = new Node;

               _TNULL->color = BLACK;
               _TNULL->data = make_pair(key_type(), mapped_type());
               _TNULL->leftChild = NULL;
               _TNULL->rightChild = NULL;
               _root = _TNULL;
            };

            void balanceTree(nodePtr k){
                nodePtr u;

                while (k->parent->color == RED){
                    if (k->parent == k->parent->parent->rightChild){
                        u = k->parent->parent->leftChild;
                        if (u->color == RED){
                            u->color = BLACK;
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            k = k->parent->parent;
                        }
                        else{
                            if (k == k->parent->leftChild){
                                k = k->parent;
                                //rightRotate;
                            }
                            k->parent->color = BLACK;
                            k->parent->parent->color = RED;
                            //leftRotate
                        }
                    }
                    else{
                        u = k->parent->parent->right;

                        if (u->color == BLACK){
                            u->color = RED;
                            k->parent->color = RED;
                            k->parent->parent->color = BLACK;
                            k = k->parent->parent;
                        }
                        else{
                            if (k == k->parent->right){
                                k = k->parent;
                                //leftRotate;
                            }
                            k->parent->color = RED;
                            k->parent->parent->color = BLACK;
                            //rightRotate;
                        }
                    }
                    if (k == root)
                        break;
                }
                root->color = BLACK;
            }


            void insert(ft::pair<const key_type, mapped_type> key){
                nodePtr node = new Node;
                node->parent = NULL;
                node->data = key;
                node->leftChild = _TNULL;
                node->rightChild = _TNULL;
                node->color = RED;

                nodePtr y = NULL;
                nodePtr x = _root;

                while (x != _TNULL){
                    y = x;
                    if (_compare(node->data->first, x->data->first) == true)
                        x = x->leftChild;
                    else
                        x = x->rightChild;
                }
                node->parent = y;
                if (y == NULL)
                    _root = node;
                else if (_compare(node->data->first, y->data->first) == true)
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
    };

};
#endif