#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

# include <iterator>

namespace ft{
    template<class T>
    struct iterator_traits{
        typedef typename T::iterator::difference_type       difference_type;
        typedef typename T::iterator::value_type            value_type;
        typedef typename T::iterator::pointer               pointer;
        typedef typename T::iterator::reference             reference;
        typedef typename T::iterator::iterator_category     iterator_category;
    };
    template<typename T>
    struct iterator_traits<T*>
    {
      typedef ptrdiff_t                 difference_type;
      typedef T                         value_type;
      typedef T*                        pointer;
      typedef T&                        reference;
      typedef std::random_access_iterator_tag iterator_category;
    };
    template<typename T>
    struct iterator_traits<const T*>
    {
      typedef ptrdiff_t                 difference_type;
      typedef T                         value_type;
      typedef T*                        pointer;
      typedef T&                        reference;
      typedef std::random_access_iterator_tag iterator_category;
    };
}


#endif