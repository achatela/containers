#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
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
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(n), _capacity(n + (n / 2)){
                _vector = _alloc.allocate(_capacity);
                (void)val;
            };

            ~vector(){
                //?
            };

            vector& operator=(const vector& x){
                this->assign(x.begin(), x.end());
                return *this;
            };


        // Iterators

            iterator begin(){
                return iterator(this->)
            };
            
            const_iterator begin() const{

            };


        // Capacity
            size_type size() const{
                return _size; // should be iterator start - iterator end
            };

            size_type max_size() const{
                return _capacity;
            };

            void resize (size_type n, value_type val = value_type()){
                if (_size < n){
                    (void)n; // use insert function
                }
                else if (_size > n){
                    (void)n; // erase the elements higher than n
                }
                (void)val;
            };

            size_type capacity() const{
                return _capacity;
            };
            
            bool empty() const{
                // temporaire
                if (_size == 0)
                    return true;
                else
                    return false;
                //return (begin() == end());
            };

            void reserve (size_type n){
                if (n > capacity()){
                    if (n > max_size())
                        ;   //throw error
                    ;
                    //allocator_type& a = this->_alloc();
                    /*        __split_buffer<value_type, allocator_type&> __v(__n, size(), __a);
                                __swap_out_circular_buffer(__v); ? ? ?
                    */
                }
            };

            // Element access

            /* Operator[] out of the range is not defined
            */

            reference operator[] (size_type n){
                return *(/*iterator begin*/this->_vector + n);
            };
            
            const_reference operator[] (size_type n) const{
                // need to throw exception
                return *(/*iterator begin*/this->_vector + n);
            };

            reference at (size_type n){
                if (n >= this->size()){
                    std::cout << "Range check exception" << std::endl;
                }
                return (*this)[n];
            };
            
            const_reference at (size_type n) const{
                if (n >= this->size()){
                    std::cout << "Range check exception" << std::endl;
                }
                return (*this)[n];
            };

            /*Calling front on empty container is undefined
            */
           
            reference front(){
                //When iterators are working
                // return *begin();
                return (*this)[0];
            };
            
            const_reference front() const{
                //When iterators are working
                // return *begin();
                return (*this)[0];
            };

            /*Calling back on empty container is undefined
            */

            reference back(){
                //When iterators are working
                // return *(end() - 1);
                return (*this)[_size - 1];
            };
            
            const_reference back() const{
                //When iterators are working
                // return *(end() - 1);
                return (*this)[_size - 1];
            };

            /*value_type* data() _GLIBCXX_NOEXCEPT{;
              //return std::__addressof(front());
            }

            A VOIR MAIS PAS C++98 ASKIP

            const value_type* data() _GLIBCXX_NOEXCEPT{
              //return std::__addressof(front());
            };*/

            // Modifiers

            template <class InputIterator> 
            void assign (InputIterator first, InputIterator last){
                (void)first, last;
            };
            void assign (size_type n, const value_type& val){
                (void)n, val;
            };

            void push_back (const value_type& val){
                (void)val;
            };

            void pop_back(){

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
            };

            void clear(){
                ;
            };
    };
}

#endif
