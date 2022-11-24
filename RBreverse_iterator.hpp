#ifndef RBreverse_iterator_HPP
# define RBreverse_iterator_HPP

# include "bidirectionnal_iterator.hpp"
# include "iterator_traits.hpp"

namespace ft
{
    template<typename T>
    class RBreverse_iterator
    {
        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T>::value_type			value_type;
            typedef typename ft::iterator_traits<T>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T>::pointer         	pointer;
			typedef typename ft::iterator_traits<T>::reference			reference;
			typedef typename ft::iterator_traits<T>::iterator_category  iterator_category;
		protected:
			pointer _current;

		public:
            RBreverse_iterator() : _current(NULL){};


			operator RBreverse_iterator<const T>() const{
				return (RBreverse_iterator<T const>(this->_current));
			}


			RBreverse_iterator(T it) : _current(it.get_current()){};

			explicit RBreverse_iterator(pointer it) : _current(it){};
			
			~RBreverse_iterator(){};
		
		public:

			pointer get_current() const{
				return _current;
			}

            
			template <class iter>
			RBreverse_iterator (const RBreverse_iterator<iter> & it) : _current(it.get_current()){};


			reference operator*() const{
				return *_current;
			};

			// pointer operator->()const{}

			iterator_type base() const{
				RBreverse_iterator tmp = *this;

				++tmp._current;
				return (iterator_type)tmp._current;
			};

			RBreverse_iterator operator+ (difference_type n) const{
				RBreverse_iterator tmp = *this;
				tmp._current -= n;
				return tmp;
			};

			RBreverse_iterator& operator++(){
				--_current;
				return *this;
			};
            
			RBreverse_iterator  operator++(int){
				RBreverse_iterator tmp = *this;

				--_current;
				return tmp;
			};
            
			RBreverse_iterator& operator+= (difference_type n){
				_current -= n;
				return (*this);
			};

			RBreverse_iterator& operator-= (difference_type n){
				_current += n;
				return (*this);
			};

			RBreverse_iterator operator- (difference_type n) const{
				RBreverse_iterator tmp = *this;
				tmp._current += n;
				return tmp;
			};

			RBreverse_iterator& operator--(){
				++_current;
				return *this;
			};

			RBreverse_iterator  operator--(int){
				RBreverse_iterator tmp = *this;
				++_current;
				return tmp;
			};

			pointer operator->() const{
				return &(operator*());
			};

			reference operator[] (difference_type n) const{
				return *(_current - n);
			};
    };

			template <class _Tp, class __Tp>
			inline bool operator==(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return (lhs.get_current() == rhs.get_current());
			};

			template <class _Tp, class __Tp>
			inline bool operator!=(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return (lhs.get_current() != rhs.get_current());
			};

			template <class _Tp, class __Tp>
			inline bool operator<(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return (rhs.get_current() < lhs.get_current());
			};

			template <class _Tp, class __Tp>
			inline bool operator<=(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return !(rhs < lhs);
			};
            
			template <class _Tp, class __Tp>
			inline bool operator>(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return (rhs < lhs);
			};

			template <class _Tp, class __Tp>
			inline bool operator>=(const RBreverse_iterator<_Tp> &lhs, const RBreverse_iterator<__Tp> &rhs){
				return !(lhs < rhs);
			};
			
			template <class _Tp>
			 RBreverse_iterator<_Tp> operator+ (typename RBreverse_iterator<_Tp>::difference_type n, const RBreverse_iterator<_Tp>& rev_it){
				return rev_it + n;
			};
			
			template <class _Tp> // ??
			 RBreverse_iterator<_Tp> operator- (typename RBreverse_iterator<_Tp>::difference_type n, const RBreverse_iterator<_Tp>& rev_it){
				return rev_it - n;
			};
            
			template <class _Tp, class __Tp>
			 typename RBreverse_iterator<_Tp>::difference_type operator- (const RBreverse_iterator<_Tp>& lhs, const RBreverse_iterator<__Tp>& rhs){
				return rhs.get_current() - lhs.get_current();
			};

			template <class _Tp, class __Tp> // ??
			 typename RBreverse_iterator<_Tp>::difference_type operator+ (const RBreverse_iterator<_Tp>& lhs, const RBreverse_iterator<__Tp>& rhs){
				return lhs.get_current() + rhs.get_current();
			};
};

#endif