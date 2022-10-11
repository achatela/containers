#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "random_access.hpp"

namespace ft
{
    template<typename T>
    class reverse_iterator : public std::iterator<std::random_access_iterator_tag, T>
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T>::value_type			value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
            reverse_iterator() : _current(NULL){};

        protected:
            pointer _current;
		
		public:

			operator reverse_iterator<const T>() const{
				reverse_iterator<const T> citer(_current);
				return citer;
			}

			explicit reverse_iterator(pointer it) : _current(it){};
            
			template <class iter>
			reverse_iterator (const reverse_iterator<iter> & it) : _current(it.base()){};

			~reverse_iterator(){};

			reference operator*() const{
				return *_current;
			};

			iterator_type base() const{
				return _current;
			};

			reverse_iterator operator+ (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp._current += n;
				return tmp;
			};

			reverse_iterator& operator++(){
				--_current;
				return *this;
			};
            
			reverse_iterator  operator++(int){
				reverse_iterator tmp = *this;

				--_current;
				return tmp;
			};
            
			reverse_iterator& operator+= (difference_type n){
				_current += n;
				return (*this);
			};

			reverse_iterator& operator-= (difference_type n){
				_current -= n;
				return (*this);
			};

			reverse_iterator operator- (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp._current -= n;
				return tmp;
			};

			reverse_iterator& operator--(){
				++_current;
				return *this;
			};

			reverse_iterator  operator--(int){
				reverse_iterator tmp = *this;
				++_current;
				return tmp;
			};

			pointer operator->() const{
				return &(operator*());
			};

			reference operator[] (difference_type n) const{
				return *(_current + n);
			};

			// template <class _Tp, class __Tp>
			// friend bool operator==(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current == rhs._current);
			// };

			// template <class _Tp, class __Tp>
			// friend bool operator!=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current != rhs._current);
			// };

			// template <class _Tp, class __Tp>
			// friend bool operator<(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current < rhs._current);
			// };

			// template <class _Tp, class __Tp>
			// friend bool operator<=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current <= rhs._current);
			// };
            
			// template <class _Tp, class __Tp>
			// friend bool operator>(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current > rhs._current);
			// };

			// template <class _Tp, class __Tp>
			// friend bool operator>=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
			// 	return (lhs._current >= rhs._current);
			// };

			// template <class _Tp>
			// friend reverse_iterator<_Tp> operator+ (typename reverse_iterator<_Tp>::difference_type n, const reverse_iterator<_Tp>& rev_it){
			// 	return rev_it + n;
			// };
            
			// template <class _Tp, class __Tp>
			// friend typename reverse_iterator<_Tp>::difference_type operator- (const reverse_iterator<_Tp>& lhs, const reverse_iterator<__Tp>& rhs){
			// 	return lhs._current - rhs._current;
			// };

    };
};

#endif