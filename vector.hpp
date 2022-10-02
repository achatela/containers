#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <bits/stl_deque.h>
# include "iterator_traits.hpp"
#include <bits/stl_iterator_base_funcs.h>
#include <bits/functexcept.h>
#include <bits/concept_check.h>



namespace ft{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
      //  typedef vector<T, Alloc>
            typedef typename Alloc::value_type                _Alloc_value_type;


            typedef T   value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename std::deque<T>::iterator iterator;
            typedef typename std::deque<T>::const_iterator const_iterator;
            //typedef typename ft::iterator_traits<T>::iterator iterator;
          //  typedef typename ft::iterator_traits<T>::const_iterator const_iterator;
            //typedef typename vector::reverse_iterator reverse_iterator;
            //typedef typename vector::const_reverse_iterator const_reverse_iterator;
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;

            void get_start() {
                std::cout << "Test" << std::endl;
            }

        private:
            pointer _M_start;
            pointer _M_finish;
            pointer _M_end_of_storage;

        // Constructors/destructor
            explicit vector(const allocator_type& _a) {_M_start(0); _M_finish(0); _M_end_of_storage(0); std::cout << "e" << std::endl;}
    };
}

#endif
