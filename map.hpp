#ifndef MAP_HPP
# define MAP_HPP

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

        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef typename ft::pair<const Key, T>                         value_type;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::pointer                        pointer;
            typedef typename allocator_type::const_pointer                  const_pointer;
            typedef typename ft::bidirectionnal<value_type>                          iterator;
            typedef typename ft::bidirectionnal<const value_type>                    const_iterator;
            typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;       
            typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator; 
            typedef std::ptrdiff_t                                          difference_type;
            typedef std::size_t                                             size_type;

        private:
            allocator_type  _alloc;
            pointer         _map;
            size_type       _size;
            size_type       _capacity;
            key_compare     _comparator;

        public:

        //Constructors/destructor
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(1), _comparator(comp){
                _map = _alloc.allocate(_capacity);
                //_map = NULL;
            };

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL): _alloc(alloc), _size(0), _capacity(1) , _comparator(comp){
                (void)comp;

                size_type tmp = 0;
                InputIterator first2 = first;
                InputIterator last2 = last;

                while (first2 != last2){
                    tmp++;
                    first2++;
                }
                _capacity = tmp;
                _map = _alloc.allocate(_capacity);
                while (first != last){
                    insert(*first);
                    first++;
                }
            };

            ~map(){
                size_type tmp = 0;

                while (tmp < _size){
                    _alloc.destroy(_map + tmp);
                }
                _alloc.deallocate(_map, _capacity);
            };


        // ITERATORS
            iterator begin(){
                return iterator(_map);
            };

            const_iterator begin() const{
                return const_iterator(_map);
            };

            iterator end(){
                return iterator(_map + _size);
            };

            const_iterator end() const {
                return const_iterator(_map + _size);
            };

            reverse_iterator rbegin(){
                return reverse_iterator(_map + (_size - 1));
            };

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(_map + (_size - 1));
            };

            reverse_iterator rend(){
                return reverse_iterator(_map - 1);
            };

            const_reverse_iterator rend() const{
                return const_reverse_iterator(_map - 1);
            };

        // CAPACITY

            bool empty() const{
                if (_size == 0)
                    return true;
                return false;
            };

            size_type size() const{
                return _size;
            };

            size_type max_size() const{
                return _alloc.max_size(); // * 2 ?
            };

        // ELEMENT ACCESS
            mapped_type& operator[] (const key_type& k){
                size_type i = 0;

                while (i < _size && (_map + i)->first != k){
                    i++;
                }
                if (i == _size){
                    std::cout << "Not found" << std::endl;
                    _alloc.construct(_map + i, value_type(k, mapped_type()));
                    return (_map + i)->second;
                }
                else{
                    std::cout << "Found" << std::endl;
                    return (_map + i)->second;
                }
            };


            mapped_type& at (const key_type& k){
                size_type i = 0;

                while (i < _size){
                    if ((_map + i)->first == k)
                        return ((_map + i)->second);
                    i++;
                }
                throw std::length_error("map::at");
            };

            const mapped_type& at (const key_type& k) const{
                size_type i = 0;

                while (i < _size){
                    if ((_map + i)->first == k)
                        return ((_map + i)->second);
                    i++;
                }
                throw std::length_error("map::at");
            };


        // MODIFIERS
            pair<iterator,bool>
            insert (const value_type& val){
                (void)val;
            //     size_t i = 0;

            //     while (i < _size){
            //         if ((_map + i)->first == val.first){
            //             pair<iterator, bool> tmp((_map + i)->first, false);
            //             return make_pair (const_iterator(_map->first), false);
            //             return tmp;
            //         }
            //         i++;
            //     }
                return (ft::make_pair(_map, true));
            };

        // OBSERVERS


        // OPERATIONS

        iterator lower_bound (const key_type& k){
            size_type i = 0;

                while (i < _size){
                    if (_comparator((_map + i)->first, k) == false)
                        return (iterator(_map + i));
                    i++;
                }
        };

        const_iterator lower_bound (const key_type& k)const {
            size_type i = 0;

                while (i < _size){
                    if (_comparator((_map + i)->first, k) == false)
                        return (const_iterator(_map + i));
                    i++;
                }
        };

        iterator upper_bound (const key_type& k){
            size_type i = 0;

                while (i < _size){
                    if (_comparator((_map + i)->first, k) == false)
                        return (iterator(_map + i + 1));
                    i++;
                }
        };

        const_iterator upper_bound (const key_type& k)const {
            size_type i = 0;

                while (i < _size){
                    if (_comparator((_map + i)->first, k) == false)
                        return (const_iterator(_map + i + 1));
                    i++;
                }
        };

        pair<const_iterator,const_iterator> equal_range (const key_type& k) const{
            (void)k;
            return make_pair (begin(), begin());
        };

        pair<iterator,iterator> equal_range (const key_type& k){
            (void)k;
            return make_pair (begin(), begin());
        };
    };
};

#endif