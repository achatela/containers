#include <stack>
#include <vector>
#include <map>
#include <iostream>

class TestClass{

	public:
		TestClass(){i = 0; c = 'a'; f = 1.02f;};
		~TestClass(){};

	private:
		int i;
		char c;
		float f;
};

int main(void){

	// VECTOR TESTS
	{
		std::cout << "Vector<int> tests: for loop done with indexes" << std::endl << std::endl;
		std::vector<int> vct_default;
		std::vector<int> vct_fill(100, 100);
		std::vector<int> vct_assign_it;
		std::vector<int> vct_assign_size;
		std::vector<int> vct_cpy(vct_fill);

		for (int i = 0; i < 100; i++){
			vct_default.push_back(i);
		}
		vct_assign_it.assign(vct_default.begin(), vct_default.end());
		vct_assign_size.assign(50, 123);
		std::cout << "vct_default values from push_back:" << std::endl;
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_default[i] << " ";
		}
		std::cout << "size: " << vct_default.size() << std::endl << std::endl;

		std::cout << "vct_fill fill constructor:" << std::endl;
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_fill[i] << " ";
		}
		std::cout << "size: " << vct_fill.size() << std::endl << std::endl;

		std::cout << "vct_assign_it assign with iterators:" << std::endl;
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_assign_it[i] << " ";
		}
		std::cout << "size: " << vct_assign_it.size() << std::endl << std::endl;

		std::cout << "vct_assign_size assign with size/value:" << std::endl;
		for (int i = 0; i < 50; i++){
			std::cout << "i: " << vct_assign_size[i] << " ";
		}
		std::cout << "size: " << vct_assign_size.size() << std::endl << std::endl;

		std::cout << "vct_cpy copy constructor with vct_fill:" << std::endl;
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_cpy[i] << " ";
		}
		std::cout << "size: " << vct_cpy.size() << std::endl << std::endl;

		std::vector<int> vct_assign_op = vct_assign_size;
		std::cout << "vct_assign_op assign with \"=\" operator:" << std::endl;
		for (int i = 0; i < 50; i++){
			std::cout << "i: " << vct_assign_op[i] << " ";
		}
		std::cout << "size: " << vct_assign_op.size() << std::endl << std::endl;

		std::vector<int> vct_range_construct(vct_default.begin(), vct_default.end());
		std::cout << "vct_range_construct from vct_default begin/end :" << std::endl;
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_range_construct[i] << " ";
		}
		std::cout << "size: " << vct_range_construct.size() << std::endl << std::endl;
	}

	{
		std::cout << "Vector<std::string> tests: for loop done with iterators" << std::endl << std::endl;
		std::vector<std::string> vct_str;
		std::vector<std::string> vct_fill_str(10, "FILL CONSTRUCTOR");
		std::vector<std::string> vct_empty;

		std::cout << "vct_fill_str iterator:" << std::endl;
		for (std::vector<std::string>::iterator it = vct_fill_str.begin(); it != vct_fill_str.end(); it++){
			std::cout << "it: " << *it << " ";
			vct_str.push_back(*it);
		}
		std::cout << "size: " << vct_fill_str.size() << std::endl << std::endl;

		std::cout << "vct_fill_str const_iterator:" << std::endl;
		for (std::vector<std::string>::const_iterator it = vct_fill_str.begin(); it != vct_fill_str.end(); it++){
			std::cout << "it: " << *it << " ";
			vct_str.push_back(*it);
		}
		std::cout << "size: " << vct_fill_str.size() << std::endl << std::endl;

		std::cout << "vct_str reverse_iterator:" << std::endl;
		for (std::vector<std::string>::reverse_iterator rit = vct_str.rbegin(); rit != vct_str.rend(); rit++){
			std::cout << "rit: " << *rit << " ";
		}
		std::cout << "size: " << vct_str.size() << std::endl << std::endl;

		std::cout << "vct_str const_reverse_iterator:" << std::endl;
		for (std::vector<std::string>::const_reverse_iterator rit = vct_str.rbegin(); rit != vct_str.rend(); rit++){
			std::cout << "rit: " << *rit << " ";
		}
		std::cout << "size: " << vct_str.size() << std::endl << std::endl;

		std::cout << "vct_empty iterator:" << std::endl;
		for (std::vector<std::string>::iterator it = vct_empty.begin(); it != vct_empty.end(); it++){
			std::cout << "shouldn't be printed" << std::endl;
		}
	}

	{
		std::cout << "Vector<TestClass> tests: Capacity functions" << std::endl << std::endl;
		std::vector<TestClass> vct_class;

		std::cout << "vct class empty: " << vct_class.empty() << ";  max_size: " << vct_class.max_size() << "; size: " << vct_class.size() << std::endl;
		vct_class.push_back(TestClass());
		std::cout << "vct class empty: " << vct_class.empty() << "; size: " << vct_class.size() << "; capacity:" << vct_class.capacity() << std::endl;
		vct_class.resize(100);
		std::cout << "vct class empty: " << vct_class.empty() << "; size: " << vct_class.size() << "; capacity:" << vct_class.capacity() << std::endl;
		vct_class.reserve(1);
		std::cout << "vct class empty: " << vct_class.empty() << "; size: " << vct_class.size() << "; capacity:" << vct_class.capacity() << std::endl;
		vct_class.reserve(1000);
		std::cout << "vct class empty: " << vct_class.empty() << "; size: " << vct_class.size() << "; capacity:" << vct_class.capacity() << std::endl;
	}

	{
		std::cout << "Vector<int> tests: Element access" << std::endl << std::endl;
		std::vector<int> vct;

		for (int i = 0; i < 1000000; i++){
			vct.push_back(i);
			if (i == 100 || i == 10000){
				std::cout << vct.back();
				std::cout << vct.front();
			}
		}
		std::cout << vct[1];
		std::cout << vct[0];
		std::cout << vct[100];
		std::cout << vct[4324];
		std::cout << vct[999999] << std::endl;
		std::cout << vct.at(1);
		std::cout << vct.at(0);
		std::cout << vct.at(100);
		std::cout << vct.at(4324);
		std::cout << vct.at(999999) << std::endl;
		try{
			vct.at(-1);
		}
		catch(std::exception &e){
			e.what();
		}
		try{
			vct.at(99999999);
		}
		catch(std::exception &e){
			e.what();
		}
	}

	{
		std::cout << "Vector<char> tests: Modifiers" << std::endl << std::endl;
		std::vector<char> vct_char(255, 42);
		std::vector<char> vct_to_assign;

		vct_to_assign.assign(255, 42);
		for (int i = 0; i < 255; i++){
			std::cout << "i: " << vct_to_assign[i] << " ";
		}
		std::cout << std::endl << std::endl;
		vct_to_assign.clear();

		vct_to_assign.assign(vct_char.begin(), vct_char.end());
		for (int i = 0; i < 255; i++){
			std::cout << "i: " << vct_to_assign[i] << " ";
		}
		std::cout << std::endl << std::endl;
		vct_to_assign.erase(vct_to_assign.begin(), vct_to_assign.begin() + 40);
		for (int i = 0; i < 100; i++){
			std::cout << "i: " << vct_to_assign[i] << " ";
		}
		vct_to_assign.clear();
		for (int i = 0; i < 255; i++){
			vct_to_assign.push_back(43);
		}
		vct_char.swap(vct_to_assign);

		for (int i = 0; i < 255; i++){
			std::cout << "i: " << vct_char[i] << " ";
		}
		std::cout << std::endl << std::endl;
		for (int i = 0; i < 255; i++){
			std::cout << "i: " << vct_to_assign[i] << " ";
		}
		std::cout << std::endl << std::endl;
	}

	{
		std::cout << "Vector<int> tests:" << std::endl;
		std::vector<int> vct(20000, 12345);
		std::vector<int> vct_cpy(vct);

		for (std::vector<int>::iterator it = vct.begin(); it != vct.end(); it++){
			std::cout << *it << " ";
		}
		std::cout << std::endl << std::endl;
		vct_cpy.clear();
		vct_cpy.assign(vct.begin(), vct.end());
		for (int i = 0; i < 10000; i++){
			vct_cpy.push_back(54321);
		}

		for (std::vector<int>::iterator it = vct_cpy.begin(); it != vct_cpy.end(); it++){
			std::cout << *it << " ";
		}
	}

	//Stack tests

	{
		std::cout << "Stack<int>" << std::endl;
		std::stack<int> stck;
	}

	// {
	// 	std::cout << "Vector<int> tests: significant performance tests" << std::endl;

	// 	std::vector<int> vct(2000000, 12345);
	// 	std::vector<int> vct_cpy(vct);


	// 	for (int i = 0; i < 100; i++){
	// 		vct_cpy.clear();
	// 		vct_cpy.assign(vct.begin(), vct.end());
	// 		for (int i = 0; i < 1000000; i++){
	// 			vct_cpy.push_back(54321);
	// 		}
	// 	}
	// }
	
	return (0);
}