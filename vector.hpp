#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <map>

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

//based on https://cplusplus.com/reference/stack/stack/?kw=stack

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
            typedef typename ft::random_access<T> iterator;
            typedef typename ft::random_access<const T> const_iterator;
            typedef typename ft::reverse_iterator<iterator> reverse_iterator;
            typedef typename ft::reverse_iterator<const_iterator> const_reverse_iterator;
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
               // _vector = _alloc.allocate(1);
               _vector = NULL;
            };

            explicit vector (size_type n, const value_type& val = value_type(),
                const allocator_type& alloc = allocator_type()) : _alloc(alloc), _size(0), _capacity(n){
                _vector = _alloc.allocate(_capacity);
                size_type index = 0;
                // try{
                //     if ((value_type)0 != val){
                //         while (index != n){
                //             push_back(val);
                //             index++;
                //         }
                //         //return;
                //     }
                // }
                // catch (std::exception &e){
                //     index = 0;
                //     while (index != n){
                //         push_back(val);//_alloc.construct(_vector + index, val);
                //         index++;
                //     }
                //     //_size += n;
                //     return ;
                // }
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

                size_type tmp = 0;
                InputIterator first2 = first;
                InputIterator last2 = last;

                while (first2 != last2){
                    tmp++;
                    first2++;
                }
                _capacity = tmp;
                _vector = _alloc.allocate(_capacity);
                while (first != last){
                    push_back(*first);
                    first++;
                }
            };

            vector (const vector& x):_size(0), _capacity(x._size){
                _alloc = x._alloc;
                _vector = _alloc.allocate(_capacity);
				for (size_type i = 0; i != x._size; i++){
                    value_type val = x._vector[i];
					push_back(val);
                }
            };


            ~vector(){
                size_type tmp = 0;

                while (tmp < _size){
                    _alloc.destroy(_vector + tmp);
                    tmp++;
                }
                _alloc.deallocate(_vector, _capacity);
            };

            vector& operator=(const vector& x){
                size_type tmp = 0;

                
                while (tmp < _size){
                    _alloc.destroy(_vector + tmp);
                    tmp++;
                }
                _alloc.deallocate(_vector, _capacity);
                _alloc = x._alloc;
                _size = 0;
                _vector = _alloc.allocate(x._capacity);
                if (_capacity < x._capacity)
                    _capacity = x._capacity;
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
                if (n > _size){
                    try{
                        if (_capacity * 2 < n)
                            reserve(n);
                        else
                            reserve(_capacity * 2);
                    }
                    catch(std::exception &e) {
                        std::cout << e.what() << std::endl;
                    }
                }
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
                if (n >= max_size())
                    throw std::length_error("vector::reserve");
                if (n <= _capacity)
                    return ;
                pointer _new ;
                _new = _alloc.allocate(n);
                // if (n == 1){
                //     _vector = _new;
                //     _capacity = n;
                //     return ;
                // }
                size_t i = 0;
                for (; i < _size; i++){
                    _alloc.construct(_new + i, _vector[i]);
                    _alloc.destroy(_vector + i);
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
                if (_size == _capacity)
                {
                    if (_capacity == 0){
                        try{
                            reserve(1);
                        }
                        catch(std::exception &e) {
                            std::cout << e.what() << std::endl;
                        }
                    }
                    else{
                        try{
                            reserve((_capacity * 2));
                        }
                        catch(std::exception &e) {
                            std::cout << e.what() << std::endl;
                        }
                    }
                }
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
                
                if (position == end()){
                    push_back(val);
                    return iterator(_vector + _size - 1);
                }
                if (_capacity > _size + 1)
                    _new = _alloc.allocate(_capacity);
                else
                    _new = _alloc.allocate(_size * 2);
                for (size_type i = 0; i <= _size; i++){
                    if (it == position){
                        ret = j;
                        _alloc.construct(_new + j++, val);//_new[j++] = val;
                        while (i < _size)
                            _alloc.construct(_new + j++, _vector[i++]);//_new[j++] = _vector[i++];
                        break;
                    }
                    _alloc.construct(_new + j++, _vector[i]);//_new[j++] = _vector[i];
                    it++;
                }
                // if (it == position){
                //         ret = j;
                //         _alloc.construct(_new + j++, val);
                // }
                size_type tmp = 0;

                while (tmp < _size){
                    _alloc.destroy(_vector + tmp);
                    tmp++;
                }
                _size++;
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
                if (_capacity > _size + 1){
                    ;
                }
                else
                    _capacity = (_size - 1) * 2;
                return iterator(_vector + ret);
            };

            void insert (iterator position, size_type n, const value_type& val){
                iterator it = begin();
                pointer _new;
                size_type j = 0;
                size_type old_size = _size;

                if (n == 0)
                    return ;
                if (_capacity > _size + n)
                    _new = _alloc.allocate(_capacity);
                else if (_size * 2 >= _size + n)
                    _new = _alloc.allocate((_size * 2));
                else
                    _new = _alloc.allocate(_size + n);
                for (size_type i = 0; i <= _size; i++){
                    if (it == position){
                        for (size_type k = 0; k != n; k++){
                            _alloc.construct(_new + j++, val);//_new[j++] = val;
                        }
                        while (i < _size)
                            _alloc.construct(_new + j++, _vector[i++]);//_new[j++] = _vector[i++];
                        break;
                    }
                    _alloc.construct(_new + j++, _vector[i]);//_new[j++] = _vector[i];
                    it++;
                }
                // if (it == position){
                //     for (size_type k = 0; k != n; k++){
                //         _alloc.construct(_new + j++, val);//_new[j++] = val;
                //     }
                // }
                size_type tmp = 0;

                while (tmp < _size){
                    _alloc.destroy(_vector + tmp);
                    tmp++;
                }
                _size += n;
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
                if (_capacity > old_size + n)
                    ;
                else if (old_size * 2 >= old_size + n)
                    _capacity = old_size * 2;
                else
                    _capacity = old_size + n;
            };

            template <class InputIterator>
            void insert (iterator position, InputIterator first, InputIterator last,
                typename enable_if<!ft::is_integral<InputIterator>::value>::type * = NULL){
                iterator it = begin();
                pointer _new;
                size_type j = 0;
                size_type old_size = _size;
                size_type i = 0;
                size_type tmp = 0;
                InputIterator first2 = first;
                InputIterator last2 = last;

                while (first2 != last2){
                    tmp++;
                    first2++;
                }
                if (_capacity > _size + tmp)
                    _new = _alloc.allocate(_capacity);
                else if (_size * 2 >= _size + tmp)
                    _new = _alloc.allocate((_size * 2));
                else
                    _new = _alloc.allocate(_size + tmp);
                for (; i <= old_size; i++){
                    if (it == position){
                        for (; first != last; _size++){
                            _alloc.construct(_new + j++, *first);//_new[j++] = *first;
                            first++;
                         }
                        while (i < old_size){
                            _alloc.construct(_new + j++, _vector[i++]);//_new[j++] = _vector[i++];
                        }
                        break;
                    }
                    _alloc.construct(_new + j++, _vector[i]);//_new[j++] = _vector[i];
                    it++;
                }
                // if (it == position && first != last){
                //     for (; first != last; _size++){
                //         _alloc.construct(_new + j++, *first);//_new[j++] = *first;
                //         first++;
                //     }
                //     while (i < old_size)
                //             _alloc.construct(_new + j++, _vector[i++]);
                // }
                size_type tmp2 = 0;

                while (tmp2 < old_size){
                    _alloc.destroy(_vector + tmp2);
                    tmp2++;
                }
                _alloc.deallocate(_vector, _capacity);
                _vector = _new;
                if (_capacity > old_size + tmp)
                    ;
                else if (old_size * 2 >= old_size + tmp)
                    _capacity = old_size * 2;
                else
                    _capacity = old_size + tmp;
            };

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
                        _alloc.destroy(_vector + i);
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
                iterator old_first = first;
                iterator old_last = last;

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
                        while (old_first != old_last && old_first != end()){
                            _alloc.destroy(_vector + i++);
                            old_first++;
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
                std::swap(this->_vector, x._vector);
                std::swap(this->_size, x._size);
                std::swap(this->_capacity, x._capacity);
                // pointer tmp = this->_vector;
                // size_type tmp_size = this->_size;
                // size_type tmp_capacity = this->_capacity;
                // //allocator_type tmp_alloc = this->_alloc;

                // //this->_alloc = x._alloc;
                // this->_vector = x._vector;
                // this->_size = x._size;
                // this->_capacity = x._capacity;
                // //x._alloc = tmp_alloc;
                // x._vector = tmp;
                // x._size = tmp_size;
                // x._capacity = tmp_capacity;
            };

            void clear(){
                while (_size != 0)
                    pop_back();
            };
            
            void swap (vector<T,Alloc>& x, vector<T,Alloc>& y);
    };

        // Swap non member
        template <class T, class Alloc>
        void swap (vector<T,Alloc>& x, vector<T,Alloc>& y){
            // size_t tmp_size = y->_size;
            // size_t tmp_capacity = y->_capacity;
            x.swap(y);
            // y->_vector = x._vector;
            // y->_size = x._size;
            // y->_capacity = x._capacity;
            // x._vector = tmp;
            // x._size = tmp_size;
            // x._capacity = tmp_capacity;
            //std::swap(x, y);
            // std::swap(y._vector, x._vector);
            // std::swap(y._size, x._size);
            // std::swap(y._capacity, x._capacity);
        };


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
