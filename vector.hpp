#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
//# include <bits/stl_deque.h>
# include "iterator_traits.hpp"
# include "random_access.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
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
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator; // ou <iterator> et enlever * dans reverse_iterator.hpp
            typedef std::ptrdiff_t difference_type;
            typedef std::size_t size_type;

        private:
            allocator_type   _alloc;
            pointer     _vector;
            size_type  _size;
            size_type  _capacity;

        public:

        // Constructors/destructor/assignement
            explicit vector (const allocator_type& alloc = allocator_type()) :_alloc(alloc), _size(0), _capacity(1) {
                _vector = _alloc.allocate(_capacity);
            };

            explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity((n + 1) * 2){
                _vector = _alloc.allocate(_capacity);
                size_type index = 0;
                try{
                    if ((value_type)0 != val){
                        while (index != n){
                            push_back(val);
                            index++;
                        }
                    }
                }
                catch (std::exception &e){
                    index = 0;
                    while (index != n){
                        _alloc.construct(_vector + index, val);
                        index++;
                    }
                    _size += n;
                    return ;
                }
                if (index == 0){
                    while (index != n){
                        push_back(val);
                        index++;
                    }
                }
            };

            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
                 typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL):
                 _alloc(alloc), _size(0), _capacity(1){
                _vector = _alloc.allocate(_capacity);
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
                _alloc.deallocate(_vector, _capacity);
                _size = 0;
                _vector = _alloc.allocate(x._capacity);
                for (size_type i = 0; i != x._size; i++){
                    value_type val = x._vector[i];
					push_back(val);
                }
                return *this;
            };


        // Iterators

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
                return *_vector;
            };
            
            const_reference front() const{
                return *_vector;
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
                for (size_type i = 0; i != _size; i++){
                    _alloc.destroy(_vector + i);
                }
                _size = 0;
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
                _alloc.construct(_vector + _size, val);
                _size++;
            };
    
            void pop_back(){
                // if (_size == 0)
                //     return ;
                _size--;
                _alloc.destroy(_vector + _size);
            };

            iterator insert (iterator position, const value_type& val){
                // check que position est dans la range
                iterator it = begin();
                size_type ret = 0;
                pointer _new;
                size_type j = 0;

                _new = _alloc.allocate(_capacity + 1);
                for (size_type i = 0; i != _size + 1; i++){
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
                _capacity = (_capacity + 1) * 2;
                return iterator(_vector + ret);
            };

            void insert (iterator position, size_type n, const value_type& val){
                iterator it = begin();
                pointer _new;
                size_type j = 0;

                _new = _alloc.allocate((_capacity + n) * 2);
                for (size_type i = 0; i != _size + 1; i++){
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
                _capacity = (_capacity + 1) * 2;
                _vector = _new;
            };

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                iterator it = begin();
                pointer _new;
                size_type j = 0;
                size_type old_size = _size;

                _new = _alloc.allocate((_capacity + 2) * 2);
                for (size_type i = 0; i != old_size + 1; i++){
                    if (it == position){
                        for (; first != last; _size++){
                            _new[j++] = *first;
                            first++;
                         }
                        while (i != old_size)
                            _new[j++] = _vector[i++];
                        break;
                    }
                    _new[j++] = _vector[i];
                    it++;
                }
                _alloc.deallocate(_vector, _capacity);
                _capacity = (_capacity + 2) * 2;
                _vector = _new;
            };

            // erase == desastre
            iterator erase (iterator position){ // tester std::vector avec un iterator hors range
                if (position == end() - 1)
                {
                    pop_back();
                    return (end());
                }
                iterator it = begin();
                size_type i = 0;
                while (it != end() - 1)
                {
                    if (it == position){
                        it++;
                        while (it != end()){
                            _alloc.destroy(_vector + i);
                            _alloc.construct(_vector + i, _vector[i + 1]);
                            i++;
                            it++;
                        }
                        _size -= 1;
                        return position;
                    }
                    else{
                        it++;
                        i++;
                    }
                }
                _size -= 1;
                return position;
                // size_type k = -1;
                // pointer _new;
                // size_type i = 0;
                // _new = _alloc.allocate(_capacity);
                // iterator it = begin();
                // while (i != _size - 1){
                //     if (it == position){
                //         k = i;
                //         it++;
                //     }
                //     _new[i++] = *it;
                //     it++;
                // }
                // _alloc.deallocate(_vector, _capacity);
                // _vector = _new;
                // _size -= 1;
                // return (begin() + k);
            };

            iterator erase (iterator first, iterator last){

                iterator it = begin();
                size_type i = 0;
                size_type k = 0;
                while (it != end())
                {
                    if (it == first){
                        while (first != last && first != end()){
                            it++;
                            first++;
                            k++;
                        }
                        while (it != end()){
                            _alloc.destroy(_vector + i);
                            _alloc.construct(_vector + i, _vector[i + k]);
                            it++;
                            i++;
                        }
                        _size -= k;
                        return first - k;
                    }
                    else{
                        it++;
                        i++;
                    }
                }
                return (last);
            };

            void swap (vector& x){
                pointer tmp = this->_vector;
                size_type tmp_size = this->_size;
                size_type tmp_capacity = this->_capacity;

                this->_vector = x._vector;
                this->_size = x._size;
                this->_capacity = x._capacity;
                x._vector = tmp;
                x._size = tmp_size;
                x._capacity = tmp_capacity;
            };

            void clear(){
                while (_size != 0)
                    pop_back();
            };

    };

            // Swap non member
                //template <class T, class Alloc>  void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);


            // Operator overload
            template <class T, class Alloc>
            bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                if (lhs.size() != rhs.size())
                    return false;
                else{
                    size_t index = 0;

                    while (index != lhs.size() && index != rhs.size()){
                        if ((lhs[index]) != (rhs[index]))
                            return false;
                        index++;
                    }
                    return true;
                }
                return true;
            };  

            template <class T, class Alloc>
            bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
                return !(lhs == rhs);
            };   



            // A REMPLACER PAR UN LEXICOGRAPHICAL COMPARE 
            template <class T, class Alloc>
            bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                
                return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
                // size_t index = 0;

                // while (index != lhs.size() && index != rhs.size()){
                //     if (lhs[index] != rhs[index]){
                //         if (lhs[index] < rhs[index]){
                //             return true;
                //         }
                //         else{
                //             return false;
                //         }
                //     }
                //     index++;
                // }
                // if (index == lhs.size() && index == rhs.size())
                //     return false;
                // else if (index == lhs.size())
                //     return true;
                // else
                //     return false;
            };  




            template <class T, class Alloc>
            bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return !(rhs < lhs);
            };  

            template <class T, class Alloc>
            bool operator> (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return (rhs < lhs);
            };    

            template <class T, class Alloc>
            bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs){
                return !(lhs < rhs);
            };            
};

#endif
