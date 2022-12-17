#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "pair.hpp"
# include "make_pair.hpp"
# include <functional>
# include "bidirectionnal_iterator.hpp"
# include "RBreverse_iterator.hpp"

# define BLACK 0
# define RED 1

namespace ft{

    template <class Key, class T, class Compare>//, class Alloc = std::allocator<ft::pair<const Key, T>>
    class RBTree{

        public:

            class Node
            {
                public:

                bool empty;
                int color;
                ft::pair<Key, T> data;
                Node * leftChild;
                Node * rightChild;
                Node * parent;

                Node * root;
                Node * end;

                Node * sentinel;

                Key first;
                T second;

                
                Node* increment(Node* x) {
                    // if (x->first == Key() && x->second == T()){ // ??
                    //     while (1)
                    //         ;
                    // }
                    // if (x == sentinel || (x->first == key_type() && x->second == mapped_type())){
                    //     x = x->root;
                    //     while (x->leftChild != sentinel)
                    //         x = x->leftChild;
                    //     return x;
                    // }
                    Node * y = x;

                    // while (y->parent != NULL)
                    //     y = y->parent;
                    y = sentinel->root;
                    while (y->rightChild != sentinel)
                        y = y->rightChild;
                    if (x->first == y->first){
                        return sentinel;
                    }
                    if (x == sentinel){// || (x->first == key_type())){// && x->second == mapped_type())){
                        y = sentinel->root;
                        while (y->leftChild != x->sentinel){
                            y = y->leftChild;
                        }
                        return y;
                    }
                    if (x->rightChild->first != Key()){

                        x = x->rightChild;

                        while (x->leftChild->first != Key()){
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
                    // if (x->first == Key() && x->second == T()){ // ??
                    //     while (1)
                    //         ;
                    // }
                    // if (x == sentinel || (x->first == key_type() && x->second == mapped_type())){
                    //     x = x->root;
                    //     while (x->leftChild != sentinel)
                    //         x = x->leftChild;
                    //     return x;
                    // }
                    const Node * y = x;


                    // while (y->parent != NULL)
                    //     y = y->parent;
                    y = sentinel->root;
                    while (y->rightChild != sentinel)
                        y = y->rightChild;
                    if (x->first == y->first)
                        return sentinel;
                    if (x == sentinel){// || (x->first == key_type())){// && x->second == mapped_type())){
                        y = sentinel->root;
                        while (y->leftChild != x->sentinel){
                            y = y->leftChild;
                        }
                        if (x == y)
                            return sentinel;
                        return y;
                    }
                    if (x->rightChild->first != Key()){

                        x = x->rightChild;

                        while (x->leftChild->first != Key()){
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

                Node* decrement(Node* x){
                    Node * y = x;

                    // while (y->parent != NULL)
                        // y = y->parent;
                    if (sentinel->empty == true)
                        return sentinel;
                    y = sentinel->root;
                    while (y->leftChild != sentinel)
                        y = y->leftChild;
                    if (x->first == y->first)
                        return sentinel;
                    if (x == sentinel){// || (x->first == key_type())){// && x->second == mapped_type())){
                        y = sentinel->root;
                        while (y->rightChild != x->sentinel){
                            y = y->rightChild;
                        }
                        if (x == y)
                            return sentinel;
                        return y;
                    }
                    if (x->leftChild->first != Key()){

                        x = x->leftChild;

                        while (x->rightChild->first != Key()){
                            x = x->rightChild;
                        }
                    }
                    else{
                        Node* tmp = x->parent;

                        while (x == tmp->leftChild){
                            x = tmp;
                            tmp = tmp->parent;
                        }

                        if (x->leftChild != tmp)
                            x = tmp;
                    }
                    return x;
                }

                const Node* decrement(const Node* x) const{
                    const Node * y = x;

                    // while (y->parent != NULL)
                    //     y = y->parent;
                    if (sentinel->empty == true)
                        return sentinel;
                    y = sentinel->root;
                    while (y->leftChild != sentinel)
                        y = y->leftChild;
                    if (x->first == y->first)
                        return sentinel;
                    if (x == sentinel){ //|| (x->first == key_type())){// && x->second == mapped_type())){
                        y = sentinel->root;
                        while (y->rightChild != x->sentinel){
                            y = y->rightChild;
                        if (x == y)
                            return sentinel;
                        }
                        return y;
                    }
                    if (x->leftChild->first != Key()){

                        x = x->leftChild;

                        while (x->rightChild->first != Key()){
                            x = x->rightChild;
                        }
                    }
                    else{
                        const Node* tmp = x->parent;

                        while (x == tmp->leftChild){
                            x = tmp;
                            tmp = tmp->parent;
                        }

                        if (x->leftChild != tmp)
                            x = tmp;
                    }
                    return x;
                }


                operator ft::pair<Key, T>(){
                        return data;
                }
            };

            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef Compare                                                 key_compare;
            typedef typename ft::bidirectionnal<Node>                 iterator;
            typedef typename ft::bidirectionnal<const Node>           const_iterator;
            typedef typename ft::RBreverse_iterator<iterator>               reverse_iterator;       
            typedef typename ft::RBreverse_iterator<const_iterator>         const_reverse_iterator; 
            typedef typename std::allocator<Node>                     allocator;
            // typedef Node                                       node;

        private:

            typedef Node                                                 *nodePtr;

            allocator       _alloc;
            nodePtr         _root;
            nodePtr         _TNULL;
            key_compare     _compare;
            std::allocator<mapped_type> _alloc_mapped;
            std::allocator<key_type>    _alloc_key;
            std::allocator<ft::pair<key_type, mapped_type> >    _alloc_pair;

        public:
        //# include "map_display.hpp"

            RBTree(const key_compare& comp = key_compare()) : _compare(comp){
                _TNULL = _alloc.allocate(1);

                _TNULL->color = BLACK;
                // _TNULL->data = ft::make_pair(key_type(), alloc_mapped.construct(, val));
                // _alloc_pair.construct(&_TNULL->data, ft::make_pair(key_type(), mapped_type()));
                _alloc_key.construct(&_TNULL->first, key_type());
                _alloc_mapped.construct(&_TNULL->second, mapped_type());
                _TNULL->leftChild = NULL;
                _TNULL->rightChild = NULL;
                _TNULL->sentinel = _TNULL;
                _TNULL->parent = NULL;
                _root = _TNULL;
                _TNULL->root = _root;
                _TNULL->empty = true;

           };
           
           nodePtr getRoot(){
                return _root;
            }

            ~RBTree(){
                recursiveDelete(_root);
                // _alloc_mapped.deallocate(&_TNULL->second, 1);
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
                _TNULL->root = _root;
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
                _TNULL->root = _root;
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
                _TNULL->root = _root;
            }

            void transplant(nodePtr left, nodePtr right){
                if (left->parent == NULL)
                    _root = right;
                else if (left == left->parent->leftChild)
                    left->parent->leftChild = right;
                else
                    left->parent->rightChild = right;
                right->parent = left->parent;
                _TNULL->root = _root;
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
                _TNULL->root = _root;
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

                if (toDelete == _TNULL){
                    _TNULL->root = _root;
                    return ;
                }

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
                _root->parent = NULL;
                _TNULL->root = _root;
            }

            iterator insert(ft::pair<const key_type, mapped_type> key){
                nodePtr node = _alloc.allocate(1);
                node->parent = NULL;
                _alloc_pair.construct(&node->data, key);
                _alloc_key.construct(&node->first, key.first);
                _alloc_mapped.construct(&node->second, key.second);
                // node->second = key.second;
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
                    _TNULL->root = _root;
                    _TNULL->empty = false;
                    return (iterator)node;
                }
                if (node->parent->parent == NULL){
                    _TNULL->root = _root;
                    _TNULL->empty = false;
                    return (iterator)node;
                }
                balanceTree(node);
                _root->parent = NULL;
                _TNULL->root = _root;
                _TNULL->empty = false;
                return (iterator)node;
            };

             iterator insert(Node tmp){
                ft::pair<Key, T> key = ft::make_pair(tmp.first, tmp.second);
                nodePtr node = _alloc.allocate(1);
                node->parent = NULL;
                // node->data = key;
                _alloc_pair.construct(&node->data, key);
                _alloc_key.construct(&node->first, key.first);
                _alloc_mapped.construct(&node->second, key.second);
                // node->second = key.second;
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
                    _TNULL->root = _root;
                    _TNULL->empty = false;
                    return (iterator)node;
                }
                if (node->parent->parent == NULL){
                    _TNULL->root = _root;
                    _TNULL->empty = false;
                    return (iterator)node;
                }
                balanceTree(node);
                _root->parent = NULL;
                _TNULL->root = _root;
                _TNULL->empty = false;
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

            reverse_iterator rbegin(){
                // if (_root == _TNULL)
                //     return (iterator)_TNULL;
                return (reverse_iterator)maximum(_root);
            }

            const_reverse_iterator rbegin()const {
                // if (_root == _TNULL)
                    // return (const_iterator)_TNULL;
                return (const_reverse_iterator)maximum(_root);
            }

            iterator end(){
                return (iterator)_TNULL;
            }

            const_iterator end() const{
                return (const_iterator)_TNULL;
            }

            reverse_iterator rend(){
                return (reverse_iterator)_TNULL;
            }

            const_reverse_iterator rend()const {
                return (const_reverse_iterator)_TNULL;
            }

            allocator getAlloc() const{
                return _alloc;
            }

            void swap(RBTree & x){
                std::swap(_alloc, x._alloc);
                std::swap(_compare, x._compare);
                std::swap(_root, x._root);
                std::swap(_TNULL, x._TNULL);
                std::swap(_alloc_mapped, x._alloc_mapped);
                std::swap(_alloc_key, x._alloc_key);
                std::swap(_alloc_pair, x._alloc_pair);
            }
    };


};
#endif