#ifndef SET_HPP
# define SET_HPP

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
    template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
    class set{

        public:
            typedef T                                                       key_type;
            typedef T                                                       value_type;
            typedef Compare                                                 key_compare;
            typedef Compare                                                 value_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename RBTree<T, T, Compare>::iterator                                 iterator;
            typedef typename RBTree<T, T, Compare>::const_iterator                           const_iterator;
            typedef typename ft::RBreverse_iterator<iterator>               reverse_iterator;       
            typedef typename ft::RBreverse_iterator<const_iterator>         const_reverse_iterator; 
            typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
            typedef std::size_t                                             size_type;

        private:
            typedef typename RBTree<T, T, Compare>                                   tree;
            tree            _root;
            size_type       _size;
            allocator_type  _alloc;
            key_compare     _key_comparator;
            value_compare   _value_comparator;

        public:

        //CONSTRUCTORS/DESTRUCTORS

            explicit set (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _root(comp), _size(0){
                ;
            };

            template <class InputIterator>
            set (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL) : _root(comp), _size(0){

                if (first != last){
                    if (find(first->first) == end()){
                        _root.insert(first->first);
                        _size++;
                    }
                    first++;
                }
                
                while (first != last){
                    if (find(first->first) == end()){
                        _root.insert(first->first);
                        _size++;
                    }
                    first++;
                }
            };

        //ITERATORS

            iterator begin(){
                return (_root.begin());
            };

            const_iterator begin() const{
                return (_root.begin());
            };

            iterator end(){
                return (_root.end());
            };

            const_iterator end() const {
                return (_root.end());
            };

            reverse_iterator rbegin(){
                return (_root.rbegin());
            };

            const_reverse_iterator rbegin() const{
                return (_root.rbegin());
            };

            reverse_iterator rend(){
                return (_root.rend());
            };

            const_reverse_iterator rend() const{
                return (_root.rend());
            };

        //CAPACITY
            bool empty() const{
                if (_size == 0)
                    return true;
                return false;
            };

            size_type size() const{
                return _size;
            };

            size_type max_size() const{
                return _root.getAlloc().max_size();
            };

        //MODIFIERS

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

        //     iterator insert (iterator position, const value_type& val){
        //         (void)position;
        //         if (_size == 0){
        //             _size++;
        //             return _root.insert(val);
        //         }
        //         iterator it = begin();

        //         while (it != end()){
        //             if (it->first == val.first)
        //                 break;
        //             it++;
        //         }
        //         if (it == end()){
        //             it = _root.insert(val);
        //             _size++;
        //         }
        //         return it;
        //     };

        //     template <class InputIterator>
        //     void insert (InputIterator first, InputIterator last,
        //         typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                
        //         if (_size == 0 && first != last){
        //             _root.insert(*first);
        //             first++;
        //             _size++;
        //         }

        //         while (first != last){
        //             if (find(first->first) == end())
        //             {
        //                 _root.insert(*first);
        //                 _size++;
        //             }
        //             first++;
        //         }
        //     };

        //OBSERVERS

        //OPERATIONS
            iterator find (const value_type& val) const{
                iterator it = begin();

                while (it != end()){
                    if (it->first == k)
                        break;
                    it++;
                }
                return it;
            };


            iterator lower_bound (const key_type& k)const {
                iterator it = begin();

                while (it != end()){
                    if (_key_comparator(it->first, k) == false)
                        return it;
                    it++;
                }
                return it;
            };

            iterator upper_bound (const key_type& k)const {
                iterator it = begin();

                while (it != end()){
                    if (_key_comparator(k, it->first) == true)
                        return it;
                    it++;
                }
                return it;
            };

            pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
                return (ft::make_pair(lower_bound(k), upper_bound(k)));
            };
    };

    template< class T, class Compare, class Alloc >
        bool operator==( const set<T,Compare,Alloc>& lhs,
                    const set<T,Compare,Alloc>& rhs ){
            if (lhs.size() != rhs.size())
                return false;
            else{
                typename ft::set<T>::const_iterator it = lhs.begin();
                typename ft::set<T>::const_iterator it2 = rhs.begin();

                while (it != lhs.end() && it2 != rhs.end()){
                    if (it->first != it2->first)
                        return false;
                    it++;
                    it2++;
                
                return true;
            }
            return true;
            };
        };

        template< class T, class Compare, class Alloc >
        bool operator!=( const set<T,Compare,Alloc>& lhs,
                 const set<T,Compare,Alloc>& rhs ){
            return !(lhs == rhs);
        };

        template< class T, class Compare, class Alloc >
        bool operator< (const set<T,Compare,Alloc>& lhs,
                 const set<T,Compare,Alloc>& rhs ){
            return ft::lexicographical_compare_map(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
        }

        template<  class T, class Compare, class Alloc >
        bool operator<=( const set<T,Compare,Alloc>& lhs,
                 const set<T,Compare,Alloc>& rhs ){
            return !(rhs < lhs);
        };

        template<  class T, class Compare, class Alloc >
        bool operator>( const set<T,Compare,Alloc>& lhs,
                const set<T,Compare,Alloc>& rhs ){
            return (rhs < lhs);
        };

        template< class T, class Compare, class Alloc >
        bool operator>=( const set<T,Compare,Alloc>& lhs,
                 const set<T,Compare,Alloc>& rhs){
            return !(lhs < rhs);
        };

        template<class T, class Compare, class Alloc >
        void swap( ft::set<T,Compare,Alloc>& lhs,
                ft::set<T,Compare,Alloc>& rhs ){
                    lhs.swap(rhs);
        };
};


#endif