#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class random_access
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T*>::value_type			value_type;
            typedef typename ft::iterator_traits<T*>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T*>::pointer         	pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef typename ft::iterator_traits<T*>::iterator_category  iterator_category;

            random_access() : _current(NULL){};

			explicit random_access(pointer it) : _current(it){};
            
			explicit random_access(T it) : _current(it.get_current() + 1){};


			template <class iter>
			random_access (const random_access<iter> & it) : _current(it.get_current()){};

			~random_access(){};
			
			operator random_access<const T>() const{
				return (random_access<T const>(this->_current));
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

			random_access operator+ (difference_type n) const{
				random_access tmp = *this;
				tmp._current += n;
				return tmp;
			};

			random_access& operator++(){
				_current++;
				return *this;
			};
            
			random_access  operator++(int){
				random_access tmp = *this;
				++_current;
				return tmp;
			};
            
			random_access& operator+= (difference_type n){
				_current += n;
				return (*this);
			};

			random_access& operator-= (difference_type n){
				_current -= n;
				return (*this);
			};

			random_access operator- (difference_type n) const{
				random_access tmp = *this;
				tmp._current -= n;
				return tmp;
			};

			random_access& operator--(){
				_current--;
				return *this;
			};

			random_access  operator--(int){
				random_access tmp = *this;
				--_current;
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
			inline bool operator==(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() == rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator!=(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() != rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator<(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() < rhs.get_current());
			}

			template <class _Tp, class __Tp>
			 inline bool operator<=(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() <= rhs.get_current());
			};
            
			template <class _Tp, class __Tp>
			 inline bool operator>(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() > rhs.get_current());
			};

			template <class _Tp, class __Tp>
			 inline bool operator>=(const random_access<_Tp> &lhs, const random_access<__Tp> &rhs){
				return (lhs.get_current() >= rhs.get_current());
			};

			template <class _Tp>
			 random_access<_Tp> operator- (typename random_access<_Tp>::difference_type n, const random_access<_Tp>& rev_it){
				return rev_it - n;
			};

			template <class _Tp>
			 random_access<_Tp> operator+ (typename random_access<_Tp>::difference_type n, const random_access<_Tp>& rev_it){
				return rev_it + n;
			};
            
			template <class _Tp, class __Tp>
			 typename random_access<_Tp>::difference_type operator- (const random_access<_Tp>&lhs, const random_access<__Tp>&rhs){
				return (lhs.get_current()) - (rhs.get_current());
			};
            
			template <class _Tp, class __Tp>
			 typename random_access<_Tp>::difference_type operator+ (const random_access<_Tp>&lhs, const random_access<__Tp>&rhs){
				return (lhs.base() + rhs.base());
			};
};

#endif