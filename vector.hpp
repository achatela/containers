#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
//# include <bits/stl_deque.h>
# include "utils/iterator_traits.hpp"
# include "utils/random_access.hpp"
# include "utils/reverse_iterator.hpp"
# include "utils/enable_if.hpp"
# include "utils/is_integral.hpp"
//#include <bits/stl_iterator_base_funcs.h>
//#include <bits/functexcept.h>
//#include <bits/concept_check.h>



namespace ft{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T   value_type;
            typedef Alloc allocator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;
            typedef typename ft::Iterator<T> iterator;
            typedef typename ft::Iterator<const T> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator; // ou <iterator> et enlever * dans reverse_iterator.hpp
            typedef typename ft::reverse_iterator<const iterator> const_reverse_iterator; // ou <iterator> et enlever * dans reverse_iterator.hpp
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;

        private:
            allocator_type   _alloc;
            pointer     _vector;
            size_type  _size;
            size_type  _capacity;

        public:

        // Constructors/destructor/assignement
            explicit vector (const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(0) {
                _vector = _alloc.allocate(_capacity);
            };


            explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(n * 2){
                _vector = _alloc.allocate(_capacity);
                size_type index = -1;
                while (++index != n){
                    push_back(val);
                }
            };
            
            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                 typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL):
                 _alloc(alloc), _size(0), _capacity(1){
                while (first != last){
                    push_back(*first);
                    first++;
                }
            };

            vector (const vector& x): _alloc(x._alloc), _size(0), _capacity(x._capacity){
                _vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i != x._size; i++){
                    value_type val = x._vector[i];
					push_back(val);
                }
            };


            ~vector(){
                _alloc.deallocate(_vector, _capacity);
            };

            vector& operator=(const vector& x){
                if (_size != 0){
                    for (size_type i = 0; i != _size; i++){
                        _alloc.destroy(_vector + i);
                    }
                }
                else
                    _alloc.destroy(_vector);
                _size = 0;
                _vector = _alloc.allocate(x._capacity);
                for (size_type i = 0; i != x._size; i++){
                    value_type val = x._vector[i];
					push_back(val);
                }
                return *this;
            };


        // Iterators // Const iterator ??

            iterator begin(){
                return iterator(_vector);
            };

            const_iterator begin() const{
                return const_iterator(_vector);
            };

            iterator end(){
                return iterator(_vector + _size);
            };

            const_iterator end() const {
                return const_iterator(_vector + _size);
            };

            reverse_iterator rbegin(){
                return reverse_iterator(_vector + (_size - 1));
            };

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(_vector + (_size - 1));
            };

            reverse_iterator rend(){
                return reverse_iterator(_vector - 1);
            };

            const_reverse_iterator rend() const{
                return const_reverse_iterator(_vector - 1);
            };

        // Capacity: Done ! (manque tests)
            size_type size() const{
                return _size;
            };

            size_type max_size() const{
                return _alloc.max_size();
            };

            void resize (size_type n, value_type val = value_type()){
                while (n < _size)
                    pop_back();
                if (n > _size)
                    reserve(n);
                while (n > _size)
                    push_back(val);
            };

            size_type capacity() const{
                return _capacity;
            };
            
            bool empty() const{
                if (_size == 0)
                    return true;
                else
                    return false;
            };

            void reserve (size_type n){
                if (n > max_size())
                    throw std::length_error("allocator<T>::allocate(size_t n) 'n' exceeds maximum supported size");
                if (n <= _capacity)
                    return ;
                pointer _new;
                _new = _alloc.allocate(n);
                for (size_t i = 0; i < _size; i++){
                    _new[i] = _vector[i];
                }
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
                _capacity = n;
            };

            // Element access: Done !

            /* Operator[] out of the range is not defined
            */

            reference operator[] (size_type n){
                return *(_vector + n);
            };
            
            const_reference operator[] (size_type n) const{
                return *(_vector + n);
            };

            reference at (size_type n){
                if (n >= size()){
                    throw std::out_of_range("out of range");
                }
                return (*this)[n];
            };
            
            const_reference at (size_type n) const{
                if (n >= size()){
                    throw std::out_of_range("out of range");
                }
                return (*this)[n];
            };

            /*Calling front on empty container is undefined
            */
           
            reference front(){
                return (*this)[0];
            };
            
            const_reference front() const{
                return (*this)[0];
            };

            /*Calling back on empty container is undefined
            */

            reference back(){
                return (*this)[_size - 1];
            };
            
            const_reference back() const{
                return (*this)[_size - 1];
            };

            // Modifiers

            template <class InputIterator> 
            void assign (InputIterator first, InputIterator last,
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                while (first != last){
                    push_back(*first);
                    first++;
                }
            };
            
            void assign (size_type n, const value_type& val){
                for (size_type i = 0; i != _size; i++){
                    _alloc.destroy(_vector + i);
                }
                _size = 0;
                for (size_type i = 0; i != n; i++){
                    push_back(val);
                }
            };

            void push_back (const value_type& val){
                if (_size + 1 > _capacity)
                    reserve((_capacity + 1) * 2);
                _vector[_size++] = val;
            };
    
            void pop_back(){
                // if (_size == 0)
                //     return ;
                _alloc.destroy(_vector + _size);
                _size--;
            };

            iterator insert (iterator position, const value_type& val){
                // check que position est dans la range
                iterator it = begin();
                size_type ret = 0;
                pointer _new;
                size_type j = 0;

                _new = _alloc.allocate(_capacity + 1);
                for (size_type i = 0; i != _size; i++){
                    if (it == position){
                        ret = j;
                        _new[j++] = val;
                        while (i != _size)
                            _new[j++] = _vector[i++];
                        break;
                    }
                    _new[j++] = _vector[i];
                    it++;
                }
                _size++;
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
                return iterator(_vector + ret);
            };

            void insert (iterator position, size_type n, const value_type& val){
                iterator it = begin();
                pointer _new;
                size_type j = 0;

                _new = _alloc.allocate(_capacity + n);
                for (size_type i = 0; i != _size; i++){
                    if (it == position){
                        for (size_type k = 0; k != n; k++){
                            _new[j++] = val;
                        }
                        while (i != _size)
                            _new[j++] = _vector[i++];
                        break;
                    }
                    _new[j++] = _vector[i];
                    it++;
                }
                _size += n;
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
            };

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                (void)position;
                (void)first;
                (void)last;
            };

            // erase == desastre
            iterator erase (iterator position){ // tester std::vector avec un iterator hors range
                if (position == end() - 1)
                {
                    pop_back();
                    return (end());
                }
                return position;
            };
            
            iterator erase (iterator first, iterator last){
                (void)first;
                (void)last;
                // while (first != last){
                //     _alloc.destroy(_vector + first);
                //     first++;
                // }
                // return last;
                return (last);
            };

            void swap (vector& x){
                vector tmp(x);
                
                x = *this;
                *this = tmp;
            };

            void clear(){
                while (_size != 0)
                    pop_back();
            };
    };
}

#endif
