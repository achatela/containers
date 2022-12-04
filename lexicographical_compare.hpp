#ifndef LEXICOGRAPHICAL_HPP
# define LEXICOGRAPHICAL_HPP

namespace ft{

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2){
        while (first1!=last1)
        {
            if (first2==last2 || *first2<*first1)
                return false;
            else if (*first1<*first2)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);     
    };

    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, Compare comp){
            while (first1!=last1)
            {
                if (first2==last2 || comp(*first2, *first1) == true)
                    return false;
                else if (comp(*first1, *first2) == true)
                    return true;
                ++first1; ++first2;
            }
            return (first2!=last2);   
        };

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare_map (InputIterator1 first1, InputIterator1 last1,InputIterator2 first2, InputIterator2 last2){
        while (first1!=last1)
        {
            if (first2==last2 || first2->second < first1->second)
                return false;
            else if (first1->second < first2->second)
                return true;
            ++first1; ++first2;
        }
        return (first2!=last2);     
    };


    template <class InputIterator1, class InputIterator2, class Compare>
    bool lexicographical_compare_map (InputIterator1 first1, InputIterator1 last1,
        InputIterator2 first2, InputIterator2 last2, Compare comp){
            while (first1!=last1)
            {
                if (first2==last2 || comp(first2->second, first1->second) == true)
                    return false;
                else if (comp(first2->second, first1->second) == true)
                    return true;
                ++first1; ++first2;
            }
            return (first2!=last2);   
        };
}


#endif