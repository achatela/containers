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
                
                Node* increment(Node* x) {
                    if (x->first == Key() && x->second == T()){ // ??
                        while (1)
                            ;
                    }
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

                const Node* increment(const Node* x) const{
                    if (x->first == Key() && x->second == T()){ // ??
                        while (1)
                            ;
                    }
                    const Node * y = x;

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
                        const Node * tmp = x->parent;

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
            typedef typename ft::bidirectionnal<Node>                 iterator;
            typedef typename ft::bidirectionnal<const Node>           const_iterator;
            typedef typename std::allocator<Node>                     allocator;
            // typedef Node                                       node;

        private:

            typedef Node                                                 *nodePtr;

            allocator       _alloc;
            nodePtr         _root;
            nodePtr         _TNULL;
            key_compare     _compare;

        public:
        //# include "map_display.hpp"

            nodePtr getRoot(){
                return _root;
            }

            RBTree(const key_compare& comp = key_compare()) : _compare(comp){
               _TNULL = _alloc.allocate(1);

               _TNULL->color = BLACK;
               _TNULL->data = make_pair(key_type(), mapped_type());
               _TNULL->first = key_type();
               _TNULL->second = mapped_type();
               _TNULL->leftChild = NULL;
               _TNULL->rightChild = NULL;
               _TNULL->parent = NULL;
               _root = _TNULL;
            };

            ~RBTree(){
                recursiveDelete(_root);
                _alloc.deallocate(_TNULL, 1);
            }
            

            void recursiveDelete(nodePtr node){
                if (node->leftChild == NULL && node->rightChild == NULL)
                    return ;
                if (node->rightChild != NULL)
                    recursiveDelete(node->rightChild);
                if (node->leftChild != NULL)
                    recursiveDelete(node->leftChild);
                _alloc.deallocate(node, 1);
            }

            nodePtr minimum(nodePtr node){
                while (node->leftChild != _TNULL)
                    node = node->leftChild;
                return node;
            }

            nodePtr maximum(nodePtr node){
                while (node->rightChild != _TNULL)
                    node = node->rightChild;
                return node;
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

            void transplant(nodePtr left, nodePtr right){
                if (left->parent == NULL)
                    _root = right;
                else if (left == left->parent->leftChild)
                    left->parent->leftChild = right;
                else
                    left->parent->rightChild = right;
                right->parent = left->parent;
            }

            void deleteBalance(nodePtr x){
                nodePtr s;
                while (x != _root && x->color == 0) {
                    if (x == x->parent->leftChild) {
                        s = x->parent->rightChild;
                        if (s->color == 1) {
                            s->color = 0;
                            x->parent->color = 1;
                            leftRotate(x->parent);
                            s = x->parent->rightChild;
                        }

                        if (s->leftChild->color == 0 && s->rightChild->color == 0) {
                            s->color = 1;
                            x = x->parent;
                        } else {
                            if (s->rightChild->color == 0) {
                                    s->leftChild->color = 0;
                                    s->color = 1;
                                    rightRotate(s);
                                    s = x->parent->rightChild;
                            }

                            s->color = x->parent->color;
                            x->parent->color = 0;
                            s->rightChild->color = 0;
                            leftRotate(x->parent);
                            x = _root;
                        }
                    }
                    
                    else {
                            s = x->parent->leftChild;
                            if (s->color == 1) {
                                s->color = 0;
                                x->parent->color = 1;
                                rightRotate(x->parent);
                                s = x->parent->leftChild;
                            }

                            if (s->rightChild->color == 0 && s->leftChild->color == 0) {
                                s->color = 1;
                                x = x->parent;
                            } else {
                                if (s->leftChild->color == 0) {
                                        s->rightChild->color = 0;
                                        s->color = 1;
                                        leftRotate(s);
                                        s = x->parent->leftChild;
                                }

                                s->color = x->parent->color;
                                x->parent->color = 0;
                                s->leftChild->color = 0;
                                rightRotate(x->parent);
                                x = _root;
                            }
                    }
                }
                x->color = 0;
            }

            void erase(key_type k){



                nodePtr node = _root;
                nodePtr toDelete = _TNULL;

                while (node != _TNULL){
                    if (node->first == k)
                        toDelete = node;
                    if (node->first <= k)
                        node = node->rightChild;
                    else
                        node = node->leftChild;
                }

                if (toDelete == _TNULL)
                    return ;





                nodePtr x;
                nodePtr y = toDelete;
                int tmpColor = y->color;
                if (toDelete->leftChild == _TNULL){
                    x = toDelete->rightChild;
                    transplant(toDelete, toDelete->rightChild);
                }
                else if (toDelete->rightChild == _TNULL){
                    x = toDelete->leftChild;
                    transplant(toDelete, toDelete->leftChild);
                }
                else{
                    y = minimum(toDelete->rightChild);
                    tmpColor = y->color;
                    x = y->rightChild;
                    if (y->parent == toDelete)
                        x->parent = y;
                    else{
                        transplant(y, y->rightChild);
                        y->rightChild = toDelete->rightChild;
                        y->rightChild->parent = y;
                    }
                    transplant(toDelete, y);
                    y->leftChild = toDelete->leftChild;
                    y->leftChild->parent = y;
                    y->color = tmpColor;
                }
                _alloc.deallocate(toDelete, 1); // change with std allocator
                if (tmpColor == BLACK)
                    deleteBalance(x);


            }

            iterator insert(ft::pair<const key_type, mapped_type> key){
                nodePtr node = _alloc.allocate(1);
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
                    return (iterator)node;
                }
                if (node->parent->parent == NULL){
                    return (iterator)node;
                }
                balanceTree(node);
                return (iterator)node;
            };

            iterator begin(){
                if (_root == _TNULL)
                    return (iterator)_TNULL;
                nodePtr x = _root;

                while (x->leftChild != _TNULL)
                    x = x->leftChild;
                return (iterator)x;
            }

            const_iterator begin() const{
                if (_root == _TNULL)
                    return (const_iterator)_TNULL;
                nodePtr x = _root;

                while (x->leftChild != _TNULL)
                    x = x->leftChild;
                return (const_iterator)x;
            }

            iterator end(){
                return (iterator)_TNULL;
            }

            const_iterator end() const{
                return (const_iterator)_TNULL;
            }

            allocator getAlloc() const{
                return _alloc;
            }
    };

};
#endif