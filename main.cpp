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
    std::map<int, int> tmp;

    for (int i = 10; i != 0 ; i--){ //std test
        tmp.insert(std::make_pair(i, 32));
    }

//     std::map<int, int> tmp2;
//     tmp2.insert(std::make_pair(0, 12));
//     tmp2 = tmp;

//     // for (int i = 0; i < 10; i++){ //std test
//     //     tmp[i] = 32;
//     // }
//     // std::map<int, int> tmp2;

//     // tmp2[100] = 32;
//     // tmp2 = tmp;
//     // tmp[1] = 32;
//     // tmp[2] = 32;
//     // tmp[3] = 32;
//     // tmp[4] = 32;
//     // tmp[12] = 32;
    std::map<int, int>::iterator it = tmp.begin();
    std::map<int, int>::reverse_iterator it2(it);

    std::cout << "it = " << it->first << "it.base =" << it.base() << std::endl;

//     return (0);
    // std::map<int, int> tmp;

    // for (int i = 10; i != 0 ; i--){ //std test
    //     tmp.insert(std::make_pair(i, 32));
    // }

    // std::map<int, int> tmp2;

    // tmp2 = tmp;

    // std::map<int, int>::iterator it = tmp2.begin();
    // while (it != tmp2.end()){
    //     std::cout << "<" << it->first << " -> " << it->second << ">" << std::endl;
    //     it++;
    // }


    // std::cout << tmp2.at(1) << std::endl << "=======================================================" << std::endl;

    // std::map<int, int> tmp3;

    // tmp3.insert(tmp2.begin(), tmp2.end());
    // std::map<int, int>::iterator it2 = tmp3.begin();

    // for (int j = 0; j != 6; j++)
    //     it2++;
    // tmp3.erase(tmp3.begin(), it2);
    // // tmp3.swap(tmp2);
    // it2 = tmp3.begin();
    // while (it2 != tmp3.end()){
    //     std::cout << "<" << it2->first << " -> " << it2->second << ">" << std::endl;
    //     it2++;
    // }

    // tmp.clear();
    // std::cout << "tmp3 size "<< tmp.size() << std::endl;
    // return (0);



    // std::map<int, int> tmp;

    // for (int i = 10; i != 0 ; i--){ //std test
    //     tmp.insert(std::make_pair(i, 32));
    // }

    // std::map<int, int>::iterator it = tmp.begin();
    // while (it != tmp.end()){
    //     std::cout << "<" << it->first << " -> " << it->second << ">" << std::endl;
    //     it++;
    // }

    // tmp.clear();

    // return 0;



    // std::map<int, int> tmp;

    // std::map<int, int>::iterator it = tmp.begin();

    // std::cout << it->first << std::endl;
    // it++;
    // std::cout << it->first << std::endl;
    // return 0;
}