#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include "iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class Iterator
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T*>::value_type			value_type;
            typedef typename ft::iterator_traits<T*>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T*>::pointer         	pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef typename ft::iterator_traits<T*>::iterator_category  iterator_category;
            Iterator() : _current(NULL){};

			explicit Iterator(pointer it) : _current(it){};
            
			explicit Iterator(T it) : _current(it.get_current() + 1){};


			template <class iter>
			Iterator (const Iterator<iter> & it) : _current(it.get_current()){};

			~Iterator(){};
			
			operator Iterator<const T>() const{
				return (Iterator<T const>(this->_current));
			}

        private:
            pointer _current;

		public:

			pointer get_current() const{
				return _current;
			}	

			reference operator*() const{
				return *_current;
			};

			iterator_type base() const{
				return *_current;
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

    };
			template <class _Tp, class __Tp>
			inline bool operator==(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() == rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator!=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() != rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator<(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() < rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator<=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() <= rhs.get_current());
			};
            
			template <class _Tp, class __Tp>
			 inline bool operator>(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() > rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 inline bool operator>=(const Iterator<_Tp> &lhs, const Iterator<__Tp> &rhs){
				return (lhs.get_current() >= rhs.get_current());
			};

			template <class _Tp>
			 Iterator<_Tp> operator- (typename Iterator<_Tp>::difference_type n, const Iterator<_Tp>& rev_it){
				return rev_it - n;
			};

			template <class _Tp>
			 Iterator<_Tp> operator+ (typename Iterator<_Tp>::difference_type n, const Iterator<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			 typename Iterator<_Tp>::difference_type operator- (const Iterator<_Tp>&lhs, const Iterator<__Tp>&rhs){
				return lhs.get_current() - rhs.get_current();
			};
            
			template <class _Tp, class __Tp>
			 typename Iterator<_Tp>::difference_type operator+ (const Iterator<_Tp>&lhs, const Iterator<__Tp>&rhs){
				return (lhs.base() + rhs.base());
			};
};

#endif