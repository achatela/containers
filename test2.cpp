#include <iostream>
#include <memory>
#include <vector>
#include "utils/iterator_traits.hpp"
#include "vector.hpp"
#include "utils/random_access.hpp"
#include "utils/reverse_iterator.hpp"

int main(){

    ft::vector<int> V1(10, 10);
    ft::vector<int> V2(5, 5);
    ft::vector<int>::iterator it = V1.begin();
    ft::vector<int>::iterator it2 = V2.begin();

    std::cout << it - it2 << std::endl;
    return (0);
}