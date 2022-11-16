#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "pair.hpp"
# include "make_pair.hpp"
# include <functionnal>

# define BLACK 0
# define RED 1

namespace ft{

    template <class Key, class T>//, class Alloc = std::allocator<ft::pair<const Key, T>>
    class RBTree{

        typedef Key                                                     key_type;
        typedef T                                                       mapped_type;
        typedef std::less<key_type>                                     compare_key;

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

            nodePtr _root;
            nodePtr _TNULL;
            compare_key

        public:

            RBTree(){
               _TNULL = new Node;

               _TNULL->color = BLACK;
               _TNULL->data = make_pair(key_type(), mapped_type());
               _TNULL->leftChild = NULL;
               _TNULL->rightChild = NULL;
               _root = _TNULL;
            };

            void insert(ft::pair<const key_type, mapped_type> key){
                nodePtr node = new Node;
                node->parent = NULL;
                node->data = key;
                node->leftChild = _TNULL;
                node->rightChild = _TNULL;
                node->color = RED;

                nodePtr y = NULL;
                nodePtr x = _root;

                while (x != TNULL){
                    y = x;
                    if (node->data < x->data)
                }
            }
    };

};
#endif