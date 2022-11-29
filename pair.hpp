#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{

    template <class T1, class T2>
    struct pair{

        private:
            typedef T1  first_type;
            typedef T2  second_type;
            
        public:
            first_type  first;
            second_type second;

        public:
            pair (): first(T1()), second(T2()){};

            template<class U, class V>
            pair (const pair<U,V>& pr) : first(U(pr.first)), second(V(pr.second)){;};

            pair (const first_type& a, const second_type& b) : first(T1(a)), second(T2(b)){;};

            ~pair (){return ;};

            pair& operator= (const pair& pr){
                this->first = pr.first;
                this->second = pr.second;

                return *this;
            };

            template <class U, class V>
            friend bool operator== (const pair<U,V>&, const pair<U,V>&);

            template <class U, class V>
            friend bool operator!= (const pair<U,V>&, const pair<U,V>&);

            template <class U, class V>
            friend bool operator< (const pair<U,V>&, const pair<U,V>&);

            template <class U, class V>
            friend bool operator<= (const pair<U,V>&, const pair<U,V>&);

            template <class U, class V>
            friend bool operator> (const pair<U,V>&, const pair<U,V>&);

            template <class U, class V>
            friend bool operator>= (const pair<U,V>&, const pair<U,V>&);
    };


        template <class T1, class T2>
        bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return lhs.first == rhs.first && lhs.second == rhs.second;
        };

        template <class T1, class T2>
        bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return !(lhs == rhs);
        };

        template <class T1, class T2>
        bool operator< (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second);
        };

        template <class T1, class T2>
        bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return !(rhs < lhs);
        };

        template <class T1, class T2>
        bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return rhs < lhs;
        };

        template <class T1, class T2>
        bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs){
            return !(lhs < rhs);
        };
};

#endif