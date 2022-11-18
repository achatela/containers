#ifndef BIDIRECTIONNAL_HPP
# define BIDIRECTIONNAL_HPP

# include "iterator_traits.hpp"
# include "red_black_tree.hpp"
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

        private:
            pointer _current;

        public:
        //Constructors/Destructor/Assignation
            bidirectionnal() : _current(NULL){};

			explicit bidirectionnal(pointer it) : _current(it){};
            
			template <class iter>
			bidirectionnal (const bidirectionnal<iter> & it) : _current(it.get_current()){};


			// explicit bidirectionnal(T it) : _current(it){};

			~bidirectionnal(){};
			
			operator bidirectionnal<const T>() const{
				return (bidirectionnal<T const>(this->_current));
			};

        //

			pointer get_current() const{
				return _current;
			}	

			reference operator*() const{
				return *_current;
			};

			pointer operator->() const{
				return &(operator*());
			};

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
				_current--;
				return *this;
			};

			bidirectionnal  operator--(int){
				bidirectionnal tmp = *this;
				--_current;
				return tmp;
			};
    };

        template <class _Tp, class __Tp>
        inline bool operator==(const bidirectionnal<_Tp> &lhs, const bidirectionnal<__Tp> &rhs){
            return (lhs.get_current() == rhs.get_current());
        };

        template <class _Tp, class __Tp>
            inline bool operator!=(const bidirectionnal<_Tp> &lhs, const bidirectionnal<__Tp> &rhs){
            return (lhs.get_current() != rhs.get_current());
        };

};


#endif