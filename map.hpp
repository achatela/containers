#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
# include "iterator_traits.hpp"
# include "random_access.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

//based on https://en.cppreference.com/w/cpp/container/map https://cplusplus.com/reference/map/map/?kw=map

namespace ft{
    template<class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<std::pair<const Key, T>> >
    class map{

        public:
            typedef Key                                                     key_type;
            typedef T                                                       mapped_type;
            typedef typename std::pair<const Key, T>                        value_type; // à remplacer par ft::pair;
            typedef Compare                                                 key_compare;
            typedef Alloc                                                   allocator_type;
            typedef typename allocator_type::reference                      reference;
            typedef typename allocator_type::const_reference                const_reference;
            typedef typename allocator_type::reference::pointer             pointer;
            typedef typename allocator_type::reference::const_pointer       const_pointer;
            typedef typename ft::Iterator<value_type>                       iterator;               //à changer en bidirectionnal
            typedef typename ft::Iterator<const value_type>                 const_iterator;         //à changer en bidirectionnal
            typedef typename ft::reverse_iterator<iterator>                 reverse_iterator;       //à changer en bidirectionnal
            typedef typename ft::reverse_iterator<const_iterator>           const_reverse_iterator; //à changer en bidirectionnal
            typedef std::ptrdiff_t                                          difference_type;
            typedef std::size_t                                             size_type;

        private:
            allocator_type  _alloc;
            pointer         _map;
            size_type       _size;
            size_type       _capacity;

        public:
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0){
                _map = NULL;
            };

            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type(),
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL): _alloc(alloc), _size(0), _capacity(1) {

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
                    push_back(*first);
                    first++;
                }
            };

    };
};

#endif