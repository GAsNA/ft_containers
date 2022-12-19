#include "utils/utils.hpp"

#include <string>
#include <iostream>

int main()
{
	ft::pair<int, std::string> p = ft::make_pair(7, "Hello");
	std::cout << "p.first = " << p.first << std::endl;
	std::cout << "p.second = " << p.second << std::endl;
}
