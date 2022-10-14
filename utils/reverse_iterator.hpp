#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "random_access.hpp"
# include "iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class reverse_iterator
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T>::value_type			value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
            reverse_iterator() : _current(NULL){};


			operator reverse_iterator<const T>() const{
				return (reverse_iterator<T const>(this->_current));
			}

			~reverse_iterator(){};

			explicit reverse_iterator(T it) : _current(it.get_current() - 1){};


			explicit reverse_iterator(pointer it) : _current(it){};
			
		protected:
			pointer _current;
		
		public:

			pointer get_current() const{
				return _current;
			}

            
			template <class iter>
			reverse_iterator (const reverse_iterator<iter> & it) : _current(it.get_current()){};


			reference operator*() const{
				return *_current;
			};

			// pointer operator->()const{}

			iterator_type base() const{
				reverse_iterator tmp = *this;

				++tmp._current;
				return (iterator_type)tmp._current;
			};

			reverse_iterator operator+ (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp._current -= n;
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
				_current -= n;
				return (*this);
			};

			reverse_iterator& operator-= (difference_type n){
				_current += n;
				return (*this);
			};

			reverse_iterator operator- (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp._current += n;
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
    };

			template <class _Tp, class __Tp>
			 bool operator==(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() == rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 bool operator!=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() != rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 bool operator<(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() < rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 bool operator<=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() <= rhs.get_current());
			};
            
			template <class _Tp, class __Tp>
			 bool operator>(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() > rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 bool operator>=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.get_current() >= rhs.get_current());
			};

			template <class _Tp>
			 reverse_iterator<_Tp> operator+ (typename reverse_iterator<_Tp>::difference_type n, const reverse_iterator<_Tp>& rev_it){
				return rev_it - n;
			};
			
			template <class _Tp> // ??
			 reverse_iterator<_Tp> operator- (typename reverse_iterator<_Tp>::difference_type n, const reverse_iterator<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			 typename reverse_iterator<_Tp>::difference_type operator- (const reverse_iterator<_Tp>& lhs, const reverse_iterator<__Tp>& rhs){
				return lhs.get_current() + rhs.get_current();
			};

			template <class _Tp, class __Tp> // ??
			 typename reverse_iterator<_Tp>::difference_type operator+ (const reverse_iterator<_Tp>& lhs, const reverse_iterator<__Tp>& rhs){
				return lhs.get_current() - rhs.get_current();
			};
};

#endif