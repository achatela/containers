#include <stack>
#include <vector>
#include <map>
#include <iostream>
#include <string>

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

		std::cout << "Stck.empty: " << stck.empty() << std::endl;
		std::cout << "Stck.size:" << stck.size() << std::endl;
		stck.push(10);
		std::cout << "Stck.size:" << stck.size() << std::endl;
		std::cout << "Stck.top:" << stck.top() << std::endl;
		std::cout << "Stck.empty: " << stck.empty() << std::endl;
		stck.push(12345);
		std::cout << "Stck.top:" << stck.top() << std::endl;
		stck.pop();
		std::cout << "Stck.top:" << stck.top() << std::endl;
		std::cout << "Stck.size:" << stck.size() << std::endl;
		for (int i = 0; i < 1000; i++){
			stck.push(i * 10);
		}
		std::cout << "Stck.size:" << stck.size() << std::endl;
		for (int i = 0; i < 500; i++){
			stck.pop();
		}
		std::cout << "Stck.top:" << stck.top() << std::endl;
		std::cout << "Stck.size:" << stck.size() << std::endl;
		std::cout << "Stck.empty: " << stck.empty() << std::endl;
		for (; stck.size() != 0;){
			stck.pop();
		}
		std::cout << "Stck.size:" << stck.size() << std::endl;
		std::cout << "Stck.empty: " << stck.empty() << std::endl;
		stck.push(-123);
		std::cout << "Stck.top:" << stck.top() << std::endl;
		std::cout << "Stck.size:" << stck.size() << std::endl;
		std::cout << "Stck.empty: " << stck.empty() << std::endl;
	}

	//Map tests

	{
		std::map<std::string, int> map_default;

		std::cout << "Map_default empty: " << map_default.empty() << std::endl;
		std::cout << "Map_default size: " << map_default.size() << std::endl;
		try{
			std::cout << "Shouldn't be printed" << map_default.at("wrong key");
		}
		catch (std::exception &e){
			e.what();
		}
		map_default.insert(std::pair<std::string, int>("Coucou", 123));
		map_default.insert(std::pair<std::string, int>("123", 123));
		map_default.insert(std::pair<std::string, int>("Test", 543));
		map_default.insert(std::pair<std::string, int>("FOO", 987));
		map_default.insert(std::pair<std::string, int>("BAR", 1230989));

		std::cout << "Map_default empty: " << map_default.empty() << std::endl;
		std::cout << "Map_default size: " << map_default.size() << std::endl;

		std::map<std::string, int> map_insert;
		std::map<std::string, int> map_cpy(map_default);
		std::map<std::string, int> map_assign = map_cpy;
		map_insert.insert(map_default.begin(), map_default.end());

		std::cout << "Print map_cpy, map_default, map_assign and map_insert by iterator" << std::endl;

		std::map<std::string, int>::iterator it = map_cpy.begin();
		std::map<std::string, int>::iterator it1 = map_default.begin();
		std::map<std::string, int>::iterator it3 = map_assign.begin();
		for (std::map<std::string, int>::iterator it2 = map_insert.begin(); it2 != map_insert.end(); it2++){
			std::cout << "In map_default: first = " << it1->first << " second = " << it1->second << std::endl;
			std::cout << "In map_insert: first = " << it2->first << " second = " << it2->second << std::endl;
			std::cout << "In map_cpy: first = " << it->first << " second = " << it->second << std::endl;
			std::cout << "In map_assign: first = " << it3->first << " second = " << it3->second << std::endl;
			it++;
			it1++;
			it3++;
		}

		std::cout << "Print map_cpy, map_default, map_assign and map_insert by const_reverse_iterator" << std::endl;

		std::map<std::string, int>::const_reverse_iterator rit = map_cpy.rbegin();
		std::map<std::string, int>::const_reverse_iterator rit1 = map_default.rbegin();
		std::map<std::string, int>::const_reverse_iterator rit3 = map_assign.rbegin();
		for (std::map<std::string, int>::iterator rit2 = map_insert.begin(); rit2 != map_insert.end(); rit2++){
			std::cout << "In map_default: first = " << rit1->first << " second = " << rit1->second << std::endl;
			std::cout << "In map_insert: first = " << rit2->first << " second = " << rit2->second << std::endl;
			std::cout << "In map_cpy: first = " << rit->first << " second = " << rit->second << std::endl;
			std::cout << "In map_assign: first = " << rit3->first << " second = " << rit3->second << std::endl;
			rit++;
			rit1++;
			rit3++;
		}

		std::cout << "Access to [\"wrong key2\"]" << std::endl;
		std::cout << map_default["wrong key2"] << std::endl;
		std::cout << map_default["wrong key2"] << std::endl;
		std::cout << "Access at(\"Coucou\")" << std::endl;
		std::cout << map_default.at("Coucou") << std::endl;

		std::cout << "map_cpy.empty:" << map_cpy.empty() << std::endl;
		map_cpy.clear();
		map_cpy.swap(map_default);
		std::cout << "map_cpy.empty:" << map_cpy.empty() << std::endl;
		for (std::map<std::string, int>::const_iterator cit = map_cpy.begin(); cit != map_cpy.end(); cit++){
			std::cout << "In map_cpy after clear/swap: first = " << cit->first << " second = " << cit->second << std::endl;
		}

		std::cout << "map_cpy.find(\"Coucou\") = " << map_cpy.find("Coucou")->second << std::endl;
		std::cout << "map_cpy.find(\"FOO\") = " << map_cpy.find("FOO")->second << std::endl;
		std::cout << "map_cpy.find(\"Test\") = " << map_cpy.find("Test")->second << std::endl;

		std::cout << "map_cpy.upper_bound(\"Coucou\") = " << map_cpy.upper_bound("Coucou")->second << std::endl;
		std::cout << "map_cpy.upper_bound(\"FOO\") = " << map_cpy.upper_bound("FOO")->second << std::endl;
		std::cout << "map_cpy.upper_bound(\"Test\") = " << map_cpy.upper_bound("Test")->second << std::endl;
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