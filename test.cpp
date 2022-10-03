#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"

int main (void){
    ft::vector<int> vectorTest;
    //std::vector<int> vectorTest;

    std::cout << vectorTest.size() << std::endl;
    std::cout << vectorTest.max_size() << std::endl;
    vectorTest.resize(10);
    std::cout << vectorTest.capacity() << std::endl;
    std::cout << vectorTest.empty() << std::endl;
    std::cout << vectorTest[1] << std::endl;
    vectorTest.reserve(5);
    return (0);
}