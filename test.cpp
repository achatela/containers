#include <iostream>
#include <memory>
#include <vector>
#include "iterator_traits.hpp"
#include "vector.hpp"
#include "random_access.hpp"
#include "reverse_iterator.hpp"

 int main (void){
    //std::vector<int> vectorTest2(3, 4);
    //std::vector<int> vectorTest;
    ft::vector<int> vectorTest2(20, 4);
    vectorTest2.push_back(100);
    ft::vector<int>::iterator ite = vectorTest2.end();
    ft::vector<int>::iterator it = vectorTest2.begin();
    //std::vector<int>::iterator it;
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


    while (it != ite){
        std::cout << *it << " ";
        it++;
    }
    it--;
    std::cout << std::endl << "returned iterator = " << *vectorTest2.insert(it, 1) << std::endl;
    it = vectorTest2.begin();
    ite = vectorTest2.end();
    while (it != ite){
        std::cout << *it << " ";
        it++;
    }
    std::cout << std::endl;
    vectorTest2.assign(10, 20);
    ft::vector<int>::reverse_iterator rit = vectorTest2.rbegin();
    ft::vector<int>::reverse_iterator rite = vectorTest2.rend();
    while (rit != rite){
        std::cout << *rit << " ";
        rit++;
    }
    // for (int i = 0; i < 200; i++)
    //     vectorTest2.pop_back();
    std::cout << std::endl;
    std::cout << vectorTest2.size() << std::endl;
    std::cout << vectorTest2.capacity() << std::endl;
    std::cout << vectorTest2[0] << std::endl;
    std::cout << vectorTest2[1] << std::endl;
    std::cout << vectorTest2[2] << std::endl;
    vectorTest2.push_back(100);
    std::cout << vectorTest2.back() << std::endl;
    std::cout << vectorTest2.front() << std::endl;
    vectorTest2.pop_back();
    std::cout << vectorTest2.front()   << std::endl;
    std::cout << vectorTest2.max_size() << std::endl;
    vectorTest2.reserve(200);
    std::cout << vectorTest2.front() << std::endl;
    std::cout << vectorTest2.capacity() << std::endl;
    vectorTest2.reserve(203);
    std::cout << vectorTest2.capacity() << std::endl;

    ft::vector<int> test = vectorTest2;
    std::cout << test[0] << std::endl;
    std::cout << test[1] << std::endl;
    std::cout << test[20] << std::endl;
    return (0);
}