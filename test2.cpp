#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"
#include "random_access.hpp"
#include "reverse_iterator.hpp"

int main(){

    std::vector<int> V1(10, 10);
    std::vector<int> V2(5, 5);
    std::vector<int>::const_iterator it = V1.begin();
    
    V1.swap(V2);
    std::vector<int>::const_iterator it2 = V1.begin();
    std::cout << *it << std::endl;
    std::cout << *it2 << std::endl;
    return (0);
}