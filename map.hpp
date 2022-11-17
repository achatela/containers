#ifndef MAP_HPP
# define MAP_HPP

# include "red_black_tree.hpp"
# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
# include "pair.hpp"
# include "make_pair.hpp"
# include "iterator_traits.hpp"
# include "bidirectionnal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

//based on https://en.cppreference.com/w/cpp/container/map https://cplusplus.com/reference/map/map/?kw=map

namespace ft{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
    class map{

        class Node;

        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef RBTree<key_type, mapped_type>                           tree;
            typedef typename ft::pair<const Key, T>                         value_type;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename tree::iterator                iterator;
            typedef typename tree::const_iterator            const_iterator;
            typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;       
            typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator; 
            typedef std::ptrdiff_t                                          difference_type;
            typedef std::size_t                                             size_type;

        private:
            tree            _root;
            allocator_type  _alloc;
            size_type       _size;
            key_compare     _comparator;

        public:

        // //Constructors/destructor

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _comparator(comp), _root(){
            };

            ~map(){
            };


        // // ITERATORS

            iterator begin(){
                return _root.begin();
            };

            // const_iterator begin() const{
            //     return const_iterator(_parent);
            // };

            iterator end(){
                return _root.end();
            };

            // const_iterator end() const {
            //     return const_iterator(_parent + _size);
            // };

            // reverse_iterator rbegin(){
            //     return reverse_iterator(_parent + (_size - 1));
            // };

            // const_reverse_iterator rbegin() const{
            //     return const_reverse_iterator(_parent + (_size - 1));
            // };

            // reverse_iterator rend(){
            //     return reverse_iterator(_parent - 1);
            // };

            // const_reverse_iterator rend() const{
            //     return const_reverse_iterator(_parent - 1);
            // };

        // // CAPACITY

        //     bool empty() const{
        //         if (_size == 0)
        //             return true;
        //         return false;
        //     };

        //     size_type size() const{
        //         return _size;
        //     };

        //     size_type max_size() const{
        //         return _alloc.max_size(); // * 2 ?
        //     };

        // // ELEMENT ACCESS

        //     mapped_type& operator[] (const key_type& k){
        //     };


        //     mapped_type& at (const key_type& k){
        //     };

        //     const mapped_type& at (const key_type& k) const{
        //     };


        // // MODIFIERS

            pair<iterator,bool>
            insert (const value_type& val){
                _root.insert(val);
                return (make_pair(iterator(), true));
            };

        // // OBSERVERS


        // // OPERATIONS

        // iterator lower_bound (const key_type& k){
        // };

        // const_iterator lower_bound (const key_type& k)const {
        // };

        // iterator upper_bound (const key_type& k){
        // };

        // const_iterator upper_bound (const key_type& k)const {
        // };

        // pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
        // };

        // pair<iterator,iterator> equal_range (const key_type& k){
        // };
    };
};

#endif