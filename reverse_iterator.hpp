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
            reverse_iterator() : current(NULL){};

        protected:
            pointer current;
		
		public:
			explicit reverse_iterator(pointer it) : current(it){};
            
			template <class iter>
			reverse_iterator (const reverse_iterator<iter> & it) : current(it.base()){};

			~reverse_iterator(){};

			reference operator*() const{
				return *current;
			};

			iterator_type base() const{
				return current;
			};

			reverse_iterator operator+ (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp.current += n;
				return tmp;
			};

			reverse_iterator& operator++(){
				--current;
				return *this;
			};
            
			reverse_iterator  operator++(int){
				reverse_iterator tmp = *this;

				--current;
				return tmp;
			};
            
			reverse_iterator& operator+= (difference_type n){
				current += n;
				return (*this);
			};

			reverse_iterator& operator-= (difference_type n){
				current -= n;
				return (*this);
			};

			reverse_iterator operator- (difference_type n) const{
				reverse_iterator tmp = *this;
				tmp.current -= n;
				return tmp;
			};

			reverse_iterator& operator--(){
				++current;
				return *this;
			};

			reverse_iterator  operator--(int){
				reverse_iterator tmp = *this;
				++current;
				return tmp;
			};

			pointer operator->() const{
				return &(operator*());
			};

			reference operator[] (difference_type n) const{
				return *(current + n);
			};

			template <class _Tp, class __Tp>
			friend bool operator==(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current == rhs.current);
			};

			template <class _Tp, class __Tp>
			friend bool operator!=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current != rhs.current);
			};

			template <class _Tp, class __Tp>
			friend bool operator<(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current < rhs.current);
			};

			template <class _Tp, class __Tp>
			friend bool operator<=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current <= rhs.current);
			};
            
			template <class _Tp, class __Tp>
			friend bool operator>(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current > rhs.current);
			};

			template <class _Tp, class __Tp>
			friend bool operator>=(const reverse_iterator<_Tp> &lhs, const reverse_iterator<__Tp> &rhs){
				return (lhs.current >= rhs.current);
			};

			template <class _Tp>
			friend reverse_iterator<_Tp> operator+ (typename reverse_iterator<_Tp>::difference_type n, const reverse_iterator<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			friend typename reverse_iterator<_Tp>::difference_type operator- (const reverse_iterator<_Tp>& lhs, const reverse_iterator<__Tp>& rhs){
				return lhs.current - rhs.current;
			};

    };
};

#endif