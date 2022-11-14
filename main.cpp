# include "map.hpp"
# include <iostream>
# include <stdexcept>
# include <iterator>
# include <utility>
# include "pair.hpp"
# include "make_pair.hpp"
# include "iterator_traits.hpp"
# include "bidirectionnal_iterator.hpp"
# include "reverse_iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"
# include <map>


int main (void){
	ft::pair <int, int> tmp;
	ft::pair tmp2(tmp);
	ft::map <int, int> tmpp;

	try{
		std::cout << tmpp.at(0) << std::endl;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	tmp = ft::make_pair(10,20);
	std::cout << tmpp.size() << std::endl;
	std::cout << tmpp.max_size() << std::endl;
	return (0);
}