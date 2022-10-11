#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class Iterator// : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T>::value_type			value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
            Iterator() : _current(NULL){};

			explicit Iterator(pointer it) : _current(it){};
            
			template <class iter>
			Iterator (const Iterator<iter> & it) : _current(it.base()){};

			~Iterator(){};

        private:
            pointer _current;

		public:

			operator Iterator<const T>() const{
				Iterator<const T> citer(_current);
				return citer;
			}

			reference operator*() const{
				return *_current;
			};

			value_type base() const{
				return _current;
			};

			Iterator operator+ (difference_type n) const{
				Iterator tmp = *this;
				tmp._current += n;
				return tmp;
			};

			Iterator& operator++(){
				_current++;
				return *this;
			};
            
			Iterator  operator++(int){
				Iterator tmp = *this;
				++(*this);
				return tmp;
			};
            
			Iterator& operator+= (difference_type n){
				_current += n;
				return (*this);
			};

			Iterator& operator-= (difference_type n){
				_current -= n;
				return (*this);
			};

			Iterator operator- (difference_type n) const{
				Iterator tmp = *this;
				tmp._current -= n;
				return tmp;
			};

			Iterator& operator--(){
				_current--;
				return *this;
			};

			Iterator  operator--(int){
				Iterator tmp = *this;
				--(*this);
				return tmp;
			};

			pointer operator->() const{
				return &(operator*());
			};

			reference operator[] (difference_type n) const{
				return *(_current + n);
			};

			template <class _Tp, class __Tp>
			friend bool operator==(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current == rhs._current);
			}

			template <class _Tp, class __Tp>
			friend bool operator!=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current != rhs._current);
			}

			template <class _Tp, class __Tp>
			friend bool operator<(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current < rhs._current);
			}

			template <class _Tp, class __Tp>
			friend bool operator<=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current <= rhs._current);
			};
            
			template <class _Tp, class __Tp>
			friend bool operator>(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current > rhs._current);
			};

			template <class _Tp, class __Tp>
			friend bool operator>=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs._current >= rhs._current);
			};

			template <class _Tp>
			friend Iterator<_Tp> operator+ (typename Iterator<_Tp>::difference_type n, const Iterator<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			friend typename Iterator<_Tp>::difference_type operator- (const Iterator<_Tp>& lhs, const Iterator<__Tp>& rhs){
				return lhs._current - rhs._current;
			};
    };
};

#endif