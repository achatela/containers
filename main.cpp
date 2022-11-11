#include "pair.hpp"
#include "make_pair.hpp"
#include "map.hpp"
#include <iostream>
#include <ostream>
#include <utility>

int main (void){
	ft::pair <int, int> tmp;
	ft::pair tmp2(tmp);
	ft::map <int, int> tmpp;

	tmp = ft::make_pair(10,20);
	std::cout << tmp.first << std::endl;
	std::cout << tmp2.first << std::endl;
	return (0);
}