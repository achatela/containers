#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
// à remplacer par les .hpp perso
# include <iterator>
// # include "iterator_traits.hpp"

namespace ft{
    template <class T, class Alloc = std::allocator<T>> class vector
    {
        public:
      //  typedef vector<T, Alloc>
            typedef Alloc allocator_type;

            typedef T   value_type;
            //typedef typename vector::allocator_type allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename std::iterator_traits<T>::iterator iterator;
            //typedef typename vector::const_iterator const_iterator;
            //typedef typename vector::reverse_iterator reverse_iterator;
            //typedef typename vector::const_reverse_iterator const_reverse_iterator;
            //typedef typename vector::difference_type difference_type;
            //typedef typename vector::size_type size_type;
    };
}

#endif
