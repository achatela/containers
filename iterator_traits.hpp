#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>

namespace ft{
    template<class T>
    struct iterator_traits{
        typedef typename T::iterator::value_type            value_type;
        typedef typename T::iterator::difference_type       difference_type;
        typedef typename T::iterator::iterator_category     iterator_category;
        typedef typename T::iterator::pointer               pointer;
        typedef typename T::iterator::reference             reference;
    };
    template<typename T>
    struct iterator_traits<T*>
    {
      typedef std::random_access_iterator_tag iterator_category;
      typedef T                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef T*                        pointer;
      typedef T&                        reference;
    };
    template<typename T>
    struct iterator_traits<const T*>
    {
      typedef std::random_access_iterator_tag iterator_category;
      typedef T                         value_type;
      typedef ptrdiff_t                   difference_type;
      typedef T*                        pointer;
      typedef T&                        reference;
    };
}


#endif