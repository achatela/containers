#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"
#include "random_access.hpp"
#include "reverse_iterator.hpp"

int main(){

    ft::vector<std::string> V1(10);

    (void)V1;
    std::cout << V1[0] << std::endl;
    return (0);
}