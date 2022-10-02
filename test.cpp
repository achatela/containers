#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"

int main (void){
    ft::vector<int> vectorTest(std::allocator<int>);
    //std::vector<int> vectorTest;

    std::cout << vectorTest->get_start() << std::endl;
    return (0);
}