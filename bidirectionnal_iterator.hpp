#ifndef BIDIRECTIONNAL_HPP
# define BIDIRECTIONNAL_HPP

# include "iterator_traits.hpp"
# include "bidirectionnal_iterator.hpp"

namespace ft
{
    template<typename T>
    class bidirectionnal{

        public:
			typedef T													iterator_type;
		    typedef typename ft::iterator_traits<T*>::value_type			value_type;
            typedef typename ft::iterator_traits<T*>::difference_type 	difference_type;
            typedef typename ft::iterator_traits<T*>::pointer         	pointer;
			typedef typename ft::iterator_traits<T*>::reference			reference;
			typedef typename ft::iterator_traits<T*>::iterator_category  iterator_category;

        protected:
            pointer _current;

        public:
        //Constructors/Destructor/Assignation
            bidirectionnal() : _current(NULL){;};
			
			operator bidirectionnal<const T>() const{
				return (bidirectionnal<T const>(this->_current));
			};

			bidirectionnal(pointer it) : _current(it){;};
            
			bidirectionnal(T it) : _current(it.get_current()){;};

			~bidirectionnal(){};

        //

			pointer get_current() const{
				return _current;
			}

			template <class iter>
			bidirectionnal (const bidirectionnal<iter> & it) : _current(it.get_current()){};


			reference operator*() const{
				return (reference)*_current;
			};

			pointer operator->() const{
				return &(operator*());
			};

			// template <class value>
			// bidirectionnal& operator= (value tmp){
			// 	_current->second = tmp;
			// }

            bidirectionnal& operator++(){
				_current = _current->increment(_current);
				return *this;
			};
            
			bidirectionnal  operator++(int){
				bidirectionnal tmp = *this;
				_current = _current->increment(_current);
				return tmp;
			};

			bidirectionnal& operator--(){
				_current = _current->decrement(_current);
				return *this;
			};

			bidirectionnal  operator--(int){
				bidirectionnal tmp = *this;
				_current = _current->decrement(_current);
				return tmp;
			};

			bool operator<(const bidirectionnal<T> &rhs) const{
				return this->_current < rhs->_current;
			}
    };

        template <class _Tp, class __Tp>
        inline bool operator==(const bidirectionnal<_Tp> &lhs, const bidirectionnal<__Tp> &rhs){
            return (lhs.get_current() == rhs.get_current());
        };

        template <class _Tp, class __Tp>
            inline bool operator!=(const bidirectionnal<_Tp> &lhs, const bidirectionnal<__Tp> &rhs){
            return (lhs.get_current() != rhs.get_current());
        };

		template <class _Tp, class __Tp>
		inline bool operator<(const bidirectionnal<_Tp> &lhs, const bidirectionnal<__Tp> &rhs){
			return (rhs.get_current() < lhs.get_current());
		};


};


#endif