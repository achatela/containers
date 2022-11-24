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
# include "RBreverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

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
            typedef typename ft::RBreverse_iterator<iterator>                 reverse_iterator;       
            typedef typename ft::RBreverse_iterator<const_iterator>           const_reverse_iterator; 
            typedef std::ptrdiff_t                                          difference_type;
            typedef std::size_t                                             size_type;

        private:
            allocator_type  _alloc;
            size_type       _size;
            key_compare     _comparator;
            tree            _root;

        public:

        // //Constructors/destructor

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _comparator(comp), _root(){
            };

            template <class InputIterator> 
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL): _alloc(alloc), _size(0), _comparator(comp), _root(){

                while (first != last && (int)_size++ != -1){
                    // check if the value is already inside (create member function in RBTree)
                    _root.insert(ft::make_pair(first->first, first->second));
                }
            };

            map (const map& x): _alloc(x._alloc), _size(x._size), _comparator(x._comparator), _root() {
            const_iterator it = x.begin();

                while (it != x.end()){
                    _root.insert(it->data);
                    it++;
                }
            };

            map& operator= (const map& x) { //voir si ça leak quand il existe déjà
            const_iterator it = x.begin();

                if (_size != 0)
                    clear();
                // if (_size != 0){
                //     _root.~RBTree();
                // }
                // _root = RBTree<key_type, mapped_type>();
                // _root.RBTree(1);
                // Erase RBTree jusqu'à size == 0
                _alloc = x._alloc;
                _size = x._size;
                _comparator = x._comparator;

                while (it != x.end()){
                    _root.insert(it->data);
                    it++;
                }
                return *this;
            };

            ~map(){
            };


        // // ITERATORS

            iterator begin(){
                return iterator(_root.begin());
            };

            const_iterator begin() const{
                return const_iterator(_root.begin());
            };

            iterator end(){
                return iterator(_root.end());
            };

            const_iterator end() const {
                return const_iterator(_root.end());
            };

            reverse_iterator rbegin(){
                return reverse_iterator(_root.rbegin());
            };

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(_root.rbegin());
            };

            reverse_iterator rend(){
                return reverse_iterator(_root.rend());
            };

            const_reverse_iterator rend() const{
                return const_reverse_iterator(_root.rend());
            };

        // // CAPACITY

            bool empty() const{
                if (_size == 0)
                    return true;
                return false;
            };

            size_type size() const{
                return _size;
            };

            size_type max_size() const{
                return _root.getAlloc().max_size(); // * 2 ?
            };

        // // ELEMENT ACCESS

            mapped_type& operator[] (const key_type& k){
                iterator it = begin();

                while (it != end()){// opti avec && _comparator(it->first, k)){
                    if (it->first == k)
                        break;
                    it++;
                }

                if (it == end()){
                    insert(ft::make_pair(k, mapped_type()));
                }
                else
                    return (it->second);
                it = begin();
                while (it != end()){
                    if (it->first == k)
                        break;
                    it++;
                }
                return it->second;
            };


            mapped_type& at (const key_type& k){
                iterator it = begin();

                while (it != end()){
                    if (it->first == k)
                        break;
                    it++;
                }
                if (it == end())
                    throw std::out_of_range("out of range");
                return (it->second);
            };

            const mapped_type& at (const key_type& k) const{
                iterator it = begin();

                while (it != end()){
                    if (it->first == k)
                        break;
                    it++;
                }
                if (it == end())
                    throw std::out_of_range("out of range");
                return (it->second);
            };


        // // MODIFIERS

            pair<iterator,bool>
            insert (const value_type& val){
                if (_size == 0){
                    _size++;
                    return ft::make_pair(_root.insert(val), true);
                }
                iterator it = begin();

                //Check if its already in the tree
                while (it != end()){
                    if (it->first == val.first)
                        break;
                    it++;
                }
                if (it == end()){
                    it = _root.insert(val);
                    _size++;
                    return (ft::make_pair(it, true));
                }
                return (ft::make_pair(it, false));
            };

            iterator insert (iterator position, const value_type& val){
                (void)position;
                if (_size == 0){
                    _size++;
                    return _root.insert(val);
                }
                iterator it = begin();

                while (it != end()){
                    if (it->first == val.first)
                        break;
                    it++;
                }
                if (it == end()){
                    it = _root.insert(val);
                    _size++;
                }
                return it;
            };

            template <class InputIterator>
            void insert (InputIterator first, InputIterator last,
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                
                if (_size == 0){
                    _root.insert(first->data);
                    first++;
                    _size++;
                }

                while (first != last){
                    //check duplicates TO FIX
                    _root.insert(first->data);
                    first++;
                    _size++;
                }
            };

            size_type erase (const key_type& k){
                if (_size == 0)
                    return 1;
                _root.erase(k);
                _size--;
                return 1;
            };

            void erase (iterator position){
                if (_size == 0)
                    return ;
                _root.erase(position->first);
                _size--;
            };

            void erase (iterator first, iterator last){
                iterator tmpfirst = first;
                iterator tmplast = last;
                size_type i = 0;

                while (tmpfirst != tmplast){
                    i++;
                    tmpfirst++;
                }

                key_type value[i];
                size_type j = 0;
                while (first != last){
                    value[j] = first->first;
                    j++;
                    first++;
                }

                j = 0;
                while (j < i){
                    _root.erase(value[j]);
                    _size--;
                    std::cout << "size = " << _size << std::endl;
                    j++;
                }
                // if (_size == 0)
                //     return ;
                // while (first != last && _size > 0){
                //     _root.erase(first->first);
                //     first++;
                //     _size--;
                // }
            };

            void swap (map& x){
                std::swap(this->_root, x._root);
                std::swap(this->_size, x._size);
                std::swap(this->_comparator, x._comparator);
                std::swap(this->_alloc, x._alloc);
            };

            void clear(){
                erase(begin(), end());
                _size = 0;
            };
        // // OBSERVERS

            key_compare key_comp() const{
                return _comparator;
            };

            // value_compare value_comp() const{
            // };

        // // OPERATIONS

            iterator find (const key_type& k){
                iterator it = begin();

                while (it != end()){
                    if (it->first == k)
                        break;
                    it++;
                }
                return it;
            };

            const_iterator find (const key_type& k) const{
                const_iterator it = begin();

                while (it != end()){
                    if (it->first == k) // TO FIX ? comparison object reflexively
                        break;
                    it++;
                }
                return it;
            };

            size_type count (const key_type& k) const{
                iterator it = begin();

                while (it != end()){
                    if (it->first == k)
                        return 1;
                    it++;
                }
                return 0;
            };

            iterator lower_bound (const key_type& k){
                iterator it = begin();

                while (it != end()){
                    if (_comparator(it->first, k) == false)
                        return it;
                    it++;
                }
                return it;
            };

            const_iterator lower_bound (const key_type& k)const {
                const_iterator it = begin();

                while (it != end()){
                    if (_comparator(it->first, k) == false)
                        return it;
                    it++;
                }
                return it;
            };

            iterator upper_bound (const key_type& k){
                iterator it = begin();

                while (it != end()){
                    if (_comparator(k, it->first) == true)
                        return it;
                    it++;
                }
                return it;
            };

            const_iterator upper_bound (const key_type& k)const {
                const_iterator it = begin();

                while (it != end()){
                    if (_comparator(k, it->first) == true)
                        return it;
                    it++;
                }
                return it;
            };

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            };

            pair<iterator,iterator> equal_range (const key_type& k){
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            };

            allocator_type get_allocator() const{
                return _alloc;
            };
    };
};

#endif