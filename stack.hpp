#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
# include "vector.hpp"
# include "iterator_traits.hpp"
# include "random_access.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

namespace ft 
{
    template <class T, class Container = vector<T> >
    class stack{
        public:
            typedef Container container_type;
            typedef T   value_type;
            typedef typename std::size_t size_type;



        protected:
            container_type c;

        public:

        //Construtors/Destructor/Operator
            explicit stack (const container_type& ctnr = container_type()) : c(ctnr){};

            stack( const stack& other) : c(other.c){

            };

            ~stack(){};

            stack& operator=( const stack& other) {
                c = other.c;
            };

        //Member functions
            bool empty() const {
                if (c.size() == 0)
                    return true;
                return false;
            };

            size_type size() const {
                return c.size();
            };

            value_type& top() {
                return c.back();
            };
            
            const value_type& top() const{
                return c.back();
            };

            void push (const value_type& val) {
                c.push_back(val);
            };

            void pop() {
                c.pop_back();
            };

        //Non member functions
            friend bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c == rhs.c;};
            friend bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c != rhs.c;};
            friend bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c < rhs.c;};
            friend bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c <= rhs.c;};
            friend bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c > rhs.c;};
            friend bool operator>=(  const stack<T,Container>& lhs, const stack<T,Container>& rhs){return lhs.c >= rhs.c;};
    };
};


#endif