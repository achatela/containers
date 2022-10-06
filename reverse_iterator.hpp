#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "random_access.hpp"

namespace ft
{
    template<typename T>
    class reverseIterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
            typedef T													value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
            reverseIterator() : _ptr(NULL){};

			explicit reverseIterator(pointer it) : _ptr(it){};
            
			template <class iter>
			reverseIterator (const reverseIterator<iter> & it) : _ptr(it.base()){};

			~reverseIterator(){};

			reference operator*() const{
				return *_ptr;
			};

			value_type base() const{
				return this->_ptr;
			};

			reverseIterator operator+ (difference_type n) const{
				reverseIterator tmp = *this;
				tmp._ptr += n;
				return tmp;
			};

			reverseIterator& operator++(){
				this->_ptr--;
				return *this;
			};
            
			reverseIterator  operator++(int){
				reverseIterator tmp = *this;
				--(*this);
				return tmp;
			};
            
			reverseIterator& operator+= (difference_type n){
				this->_ptr += n;
				return (*this);
			};

			reverseIterator& operator-= (difference_type n){
				this->_ptr -= n;
				return (*this);
			};

			reverseIterator operator- (difference_type n) const{
				reverseIterator tmp = *this;
				tmp._ptr -= n;
				return tmp;
			};

			reverseIterator& operator--(){
				this->_ptr++;
				return *this;
			};

			reverseIterator  operator--(int){
				reverseIterator tmp = *this;
				++(*this);
				return tmp;
			};

			pointer operator->() const{
				return &(operator*());
			};

			reference operator[] (difference_type n) const{
				return *(_ptr + n);
			};

			template <class _Tp, class __Tp>
			friend bool operator==(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr == rhs._ptr);
			};

			template <class _Tp, class __Tp>
			friend bool operator!=(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr != rhs._ptr);
			};

			template <class _Tp, class __Tp>
			friend bool operator<(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr < rhs._ptr);
			};

			template <class _Tp, class __Tp>
			friend bool operator<=(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr <= rhs._ptr);
			};
            
			template <class _Tp, class __Tp>
			friend bool operator>(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr > rhs._ptr);
			};

			template <class _Tp, class __Tp>
			friend bool operator>=(const reverseIterator<_Tp> &lhs, const reverseIterator<__Tp> &rhs){
				return (lhs._ptr >= rhs._ptr);
			};

			template <class _Tp>
			friend reverseIterator<_Tp> operator+ (typename reverseIterator<_Tp>::difference_type n, const reverseIterator<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			friend typename reverseIterator<_Tp>::difference_type operator- (const reverseIterator<_Tp>& lhs, const reverseIterator<__Tp>& rhs){
				return lhs._ptr - rhs._ptr;
			};

        private:
            pointer _ptr;
    };
};

#endif