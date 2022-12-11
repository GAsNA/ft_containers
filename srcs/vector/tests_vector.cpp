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
			std::cout << test[i] << " ";
		std::cout << std::endl;
		std::cout << "v:\t\t\t";
		for (int i = 0; i < 3; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "v1:\t\t\t";
		for (int i = 0; i < 4; i++)
			std::cout << v1[i] << " ";
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

	/*********************************************************/
	/*						ACCESS							 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                         ACCESS                        */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;
		
		ft::vector<int> data(6);
		data[0] = 1;
		data[1] = 2;
		data[2] = 4;
		data[3] = 5;
		data[4] = 5;
		data[5] = 6;

		/* at */
		data.at(1) = 88;
		std::cout << "Element at index 2 has value " << data.at(2) << '\n';
		std::cout << "data size = " << data.size() << '\n';

		try {
        	data.at(6) = 666;
		} catch (std::out_of_range const& exc) {
			std::cout << exc.what() << '\n';
		}
 
		std::cout << "data:";
		for (int i = 0; i < data.size(); i++)
			std::cout << " " << data[i];
		std::cout << std::endl;

		/* front */
		std::cout << "Front element of data: " << data.front() << std::endl;

		/* back */
		std::cout << "Back element of data: " << data.back() << std::endl;

		/* data */
		int *d = data.data();
		std::cout << "Pointer d for datas in data:";
		for (int i = 0; i < data.size(); i++)
			std::cout << " " << d[i];
		std::cout << std::endl;
	}
}
