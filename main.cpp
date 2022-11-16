# include <iostream>
# include "map.hpp"
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
	ft::map <int, int> tmp;

	std::map<int, int>::iterator it = tmp.begin();
	std::cout << it->first << std::endl;
}