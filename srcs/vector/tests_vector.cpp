#include "vector.hpp"

#include <vector>
#include <string>

int main()
{
	/*********************************************************/
	/*						CONSTRUCTORS					 */
	/*********************************************************/
	{
		/* Default */	
		ft::vector<int> v;
		/* Without value */
		ft::vector<int> v2(2);
		/* With value */
		ft::vector<int> v3(2, 7);
		/* By iterators */
		std::vector<int> test(2, 7);
		ft::vector<int> v4(test.begin(), test.end());
		/* By copy */
		ft::vector<int> v5(v3);
	}

	/*********************************************************/
	/*						OPERATORS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       OPERATORS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;
		ft::vector<std::string> v1(4, "Hello");
		/* = */
		ft::vector<std::string> test(3);
		test[0] = "Hello";
		test[1] = "World";
		test[2] = "!";
		ft::vector<std::string> v = test;
		/* [] */
		std::cout << "test:\t\t\t";
		for (int i = 0; i < 3; i++)
			std::cout << test[i] << " - ";
		std::cout << std::endl;
		std::cout << "v:\t\t\t";
		for (int i = 0; i < 3; i++)
			std::cout << v[i] << " - ";
		std::cout << std::endl;
		std::cout << "v1:\t\t\t";
		for (int i = 0; i < 4; i++)
			std::cout << v1[i] << " - ";
		std::cout << std::endl;
		try {
			std::cout << "Invalid index for v:\t" << v[-1] << std::endl;
		} catch (std::exception &e) {std::cout << e.what() << std::endl;}
		try {
			std::cout << "Invalid index for v:\t" << v[3] << std::endl;
		} catch (std::exception &e) {std::cout << e.what() << std::endl;}
		/* == */
		std::cout << "test == v:\t\t" << (test == v) << std::endl;
		std::cout << "v == v1:\t\t" << (v == v1) << std::endl;
		/* != */
		std::cout << "test != v:\t\t" << (test != v) << std::endl;
		std::cout << "v != v1:\t\t" << (v != v1) << std::endl;
	}
}
