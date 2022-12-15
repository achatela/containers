#include "stack.hpp"
#include "vector.hpp"
#include "map.hpp"


int main(void){

	// VECTOR TESTS
	std::cout << "Vector tests:" << std::endl << std::endl;
	ft::vector<int> vct;
	ft::vector<int> vct2(100, 100);
	ft::vector<int> vct3;
	ft::vector<int> vct4;
	ft::vector<int> vct5(vct2);

	for (int i = 0; i < 100; i++){
		vct.push_back(i);
	}
	vct3.assign(vct.begin(), vct.end());
	vct4.assign(50, 123);
	std::cout << "vct values from push_back:" << std::endl;
	for (int i = 0; i < 100; i++){
		std::cout << "i: " << vct[i] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "vct2 fill constructor:" << std::endl;
	for (int i = 0; i < 100; i++){
		std::cout << "i: " << vct2[i] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "vct3 assign with iterators:" << std::endl;
	for (int i = 0; i < 100; i++){
		std::cout << "i: " << vct3[i] << " ";
	}
	std::cout << std::endl << std::endl;
	std::cout << "vct4 assign with iterators:" << std::endl;
	
	return (0);
}