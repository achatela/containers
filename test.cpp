#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"

 int main (void){
    //std::vector<int> vectorTest2(3, 4);
//     ft::vector<int> vectorTest;
    ft::vector<int> vectorTest2(3, 4);
    //ft::vector<int>::iterator it;
    //std::vector<int> vectorTest;

    // std::cout << vectorTest.size() << std::endl;
    // std::cout << vectorTest.max_size() << std::endl;
    // vectorTest.resize(10);
    // std::cout << vectorTest.capacity() << std::endl;
    // std::cout << vectorTest.empty() << std::endl;
    // vectorTest.push_back(100);
    // std::cout << vectorTest.empty() << std::endl;
    // std::cout << vectorTest[0] << std::endl;
    // vectorTest.push_back(10000);
    // std::cout << vectorTest[1] << std::endl;
    // vectorTest.pop_back();
    // std::cout << vectorTest[1] << std::endl;



    std::cout << vectorTest2.size() << std::endl;
    std::cout << vectorTest2[0] << std::endl;
    std::cout << vectorTest2[1] << std::endl;
    std::cout << vectorTest2[2] << std::endl;
    vectorTest2.push_back(100);
    std::cout << vectorTest2.back() << std::endl;
    std::cout << vectorTest2.front() << std::endl;
    vectorTest2.pop_back();
    std::cout << vectorTest2.front() << std::endl;
    std::cout << vectorTest2.max_size() << std::endl;
    vectorTest2.reserve(200);
    std::cout << vectorTest2.front() << std::endl;
    std::cout << vectorTest2.capacity() << std::endl;
    vectorTest2.reserve(203);
    std::cout << vectorTest2.capacity() << std::endl;
    return (0);
}