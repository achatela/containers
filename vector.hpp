#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <iterator>
//# include <bits/stl_deque.h>
# include "iterator_traits.hpp"
# include "random_access.hpp"
# include "reverse_iterator.hpp"
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
            typedef typename ft::Iterator<pointer> iterator;
            typedef typename ft::iterator_traits<vector*> const_iterator;
            typedef typename ft::reverseIterator<pointer> reverse_iterator;
            typedef typename std::reverse_iterator<const_iterator> const_reverse_iterator;
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
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(n + (n / 2)){
                _vector = _alloc.allocate(_capacity);
                size_type index = -1;
                while (++index != n){
                    push_back(val);
                }
            };

            // Used instead of the above constructor by default 
            // template <class InputIterator>
            // vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){
            //     (void)first;
            //     (void)last;
            //     (void)alloc;
            // };

            vector (const vector& x){
                (void)x;
            };


            ~vector(){
                _alloc.deallocate(_vector, _capacity);
            };

            vector& operator=(const vector& x){
                this->assign(x.begin(), x.end());
                return *this;
            };


        // Iterators

            iterator begin(){
                return iterator(this->_vector);
            };

            const_iterator begin() const{
                return const_iterator(_vector);
            };

            iterator end(){
                return iterator(&_vector[_size]);
            };

            const_iterator end() const {
                return const_iterator(&_vector[_size]);
            };

            reverse_iterator rbegin(){
                return reverse_iterator(&_vector[_size - 1]);
            };

            const_reverse_iterator rbegin() const{
                return const_reverse_iterator(&_vector[_size - 1]);
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
                if (n > this->max_size())
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
                return *(this->_vector + n);
            };
            
            const_reference operator[] (size_type n) const{
                return *(this->_vector + n);
            };

            reference at (size_type n){
                if (n >= this->size()){
                    throw std::out_of_range("out of range");
                }
                return (*this)[n];
            };
            
            const_reference at (size_type n) const{
                if (n >= this->size()){
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
            void assign (InputIterator first, InputIterator last){
                (void)first, last;
            };
            
            void assign (size_type n, const value_type& val){
                (void)n, val;
            };

            void push_back (const value_type& val){
                // A VERIF
                if (_size + 1 > _capacity)
                    reserve(_capacity + (_capacity / 2));
                _vector[_size++] = val;
            };
    
            void pop_back(){

                //gérer segfault quand _size == 0
                _alloc.destroy(_vector + _size);
                _size--;
            };

            iterator insert (iterator position, const value_type& val){
                (void)position, val;
            };

            void insert (iterator position, size_type n, const value_type& val){
                (void)n, position, val;
            };

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last){
                (void)position, first, last;
            };

            iterator erase (iterator position){
                (void)position;
            };
            
            iterator erase (iterator first, iterator last){
                (void)first, last;
            };

            void swap (vector& x){
                (void)x;
                //vector tmp(x);
                //x = *this;
                //*this = tmp;
            };

            void clear(){
                while (_size != 0)
                    pop_back();
            };
    };
}

#endif
