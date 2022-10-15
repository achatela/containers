#ifndef IS_INTEGRAL_HPP
# define IS_INTEGRAL_HPP

namespace ft
{

	template <bool __v, typename _Tp>
	struct __ft__is_integral
	{
		static const _Tp value = __v;
	};

	template <typename T> struct is_integral 				: public __ft__is_integral<false, bool> {};
	template<> struct is_integral<bool> 					: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<char> 					: public __ft__is_integral<true, bool> {};
	// template<> struct is_integral<char16_t> 				: public __ft__is_integral<true, bool> {};
	// template<> struct is_integral<char32_t> 				: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<wchar_t> 					: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<signed char> 				: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<short int> 				: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<int> 						: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<long int> 				: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<long long int> 			: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<unsigned char> 			: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<unsigned short int> 		: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<unsigned int> 			: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<unsigned long int> 		: public __ft__is_integral<true, bool> {};
	template<> struct is_integral<unsigned long long int> 	: public __ft__is_integral<true, bool> {};
}

#endif