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
# include "red_black_tree.hpp"


int main (void){
    ft::map<int, int> tmp;

    for (int i = 0; i < 1000000;i++){ //ft test
        tmp.insert(ft::make_pair(i, 32));
    }

    // for (int i = 0; i < 1000000; i++){ //std test
    //     tmp[i] = 32;
    // }

    // tmp.insert(ft::make_pair(2, 32));
    // tmp.insert(ft::make_pair(3, 32));
    // tmp.insert(ft::make_pair(4, 32));
    // tmp.insert(ft::make_pair(5, 32));
    // tmp.insert(ft::make_pair(6, 32));
    // tmp.insert(ft::make_pair(7, 32));
    // tmp.insert(ft::make_pair(8, 32));
    // tmp.insert(ft::make_pair(9, 32));
    // tmp.insert(ft::make_pair(11, 32));
    // tmp.insert(ft::make_pair(12, 32));
    // tmp.insert(ft::make_pair(13, 32));
    // tmp.insert(ft::make_pair(14, 32));
    // tmp.insert(ft::make_pair(15, 32));
    // tmp.insert(ft::make_pair(16, 32));
    // tmp.insert(ft::make_pair(17, 32));
    // tmp.insert(ft::make_pair(18, 32));
    // tmp.insert(ft::make_pair(19, 32));

    // tmp[1] = 32;
    // tmp[2] = 32;
    // tmp[3] = 32;
    // tmp[4] = 32;
    // tmp[12] = 32;
    ft::map<int, int>::iterator it = tmp.begin();
    ft::map<int, int>::iterator ite = tmp.end();

    while (it != ite){
        std::cout << it->first << std::endl;
        it++;
    }

    return (0);
}
