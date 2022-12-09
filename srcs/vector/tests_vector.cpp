#include "vector.hpp"
#include <vector>

int main()
{
	ft::vector<int> v;
	/******/
	ft::vector<int> v2(2);
	ft::vector<int> v3(2, 7);
	/*****/
	std::vector<int> test(2,7);
	//std::vector::iterator it_begin = test.begin();
	//std::vector::iterator it_end = test.end();
	ft::vector<int> v4(test.begin(), test.end());
	/*****/
	ft::vector<int> v5(v3);
}
