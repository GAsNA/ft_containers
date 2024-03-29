#include "vector/vector.hpp"

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

		ft::vector<int> vint(3);
		vint[0] = 1;
		vint[1] = 2;
		vint[2] = 3;
		ft::vector<int> vint1(3);
		vint1[0] = 2;
		vint1[1] = 3;
		vint1[2] = 4;
		ft::vector<int> vint2 = vint;
		
		/* = */
		ft::vector<std::string> test(3);
		test[0] = "Hello";
		test[1] = "World";
		test[2] = "!";
		ft::vector<std::string> v = test;

		std::cout << std::endl;
		
		/* [] */
		std::cout << "test:\t\t\t";
		for (size_t i = 0; i < 3; i++)
			std::cout << test[i] << " ";
		std::cout << std::endl;
		std::cout << "v:\t\t\t";
		for (size_t i = 0; i < 3; i++)
			std::cout << v[i] << " ";
		std::cout << std::endl;
		std::cout << "v1:\t\t\t";
		for (size_t i = 0; i < 4; i++)
			std::cout << v1[i] << " ";
		std::cout << std::endl;
		
		/* == */
		std::cout << "test == v:\t\t" << (test == v) << std::endl;
		std::cout << "v == v1:\t\t" << (v == v1) << std::endl;

		std::cout << std::endl;
		
		/* != */
		std::cout << "test != v:\t\t" << (test != v) << std::endl;
		std::cout << "v != v1:\t\t" << (v != v1) << std::endl;

		std::cout << std::endl;

		/* < */
		std::cout << "Content of vint:";
		for (size_t i = 0; i < vint.size(); i++)
			std::cout << " " << vint[i];
		std::cout << std::endl;
		std::cout << "Content of vint1:";
		for (size_t i = 0; i < vint1.size(); i++)
			std::cout << " " << vint1[i];
		std::cout << std::endl;
		std::cout << "Content of vint2:";
		for (size_t i = 0; i < vint2.size(); i++)
			std::cout << " " << vint2[i];
		std::cout << std::endl;

		std::cout << "Is vint < vint1: " << (vint < vint1) << std::endl;
		std::cout << "Is vint < vint2: " << (vint < vint2) << std::endl;

		std::cout << std::endl;

		/* <= */
		std::cout << "Is vint <= vint1: " << (vint <= vint1) << std::endl;
		std::cout << "Is vint <= vint2: " << (vint <= vint2) << std::endl;

		std::cout << std::endl;

		/* > */
		std::cout << "Is vint > vint1: " << (vint > vint1) << std::endl;
		std::cout << "Is vint > vint2: " << (vint > vint2) << std::endl;

		std::cout << std::endl;
		
		/* >= */
		std::cout << "Is vint >= vint1: " << (vint >= vint1) << std::endl;
		std::cout << "Is vint >= vint2: " << (vint >= vint2) << std::endl;

		std::cout << std::endl;
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
		for (size_t i = 0; i < data.size(); i++)
			std::cout << " " << data[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* front */
		std::cout << "Front element of data: " << data.front() << std::endl;

		std::cout << std::endl;

		/* back */
		std::cout << "Back element of data: " << data.back() << std::endl;

		std::cout << std::endl;

		/* data */
		int *d = data.data();
		std::cout << "Pointer d for datas in data:";
		for (size_t i = 0; i < data.size(); i++)
			std::cout << " " << d[i];
		std::cout << std::endl;

		std::cout << std::endl;
	}
	
	/*********************************************************/
	/*						CAPACITY						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       CAPACITY                        */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::vector<int> empty;
		ft::vector<int> test(7);
		ft::vector<int> v(7, 9);
		
		/* empty */
		std::cout << "empty is empty: " << empty.empty() << std::endl;
		std::cout << "test is empty: " << test.empty() << std::endl;
		std::cout << "v is empty: " << v.empty() << std::endl;

		std::cout << std::endl;

		/* size */
		std::cout << "Size of empty: " << empty.size() << std::endl;
		std::cout << "Size of test: " << test.size() << std::endl;
		std::cout << "Size of v: " << v.size() << std::endl;

		std::cout << std::endl;

		/* max_size */
		std::cout << "Max size of v: " << v.max_size() << std::endl;

		std::cout << std::endl;

		/* reserve and capacity */
		std::cout << "Capacity of v: " << v.capacity() << std::endl;
		std::cout << "Content of v: ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << " " << v[i];
		std::cout << std::endl;
		std::cout << "// Reserve on 4" << std::endl;
		v.reserve(4);
		std::cout << "Capacity of v: " << v.capacity() << std::endl;
		std::cout << "// Reserve on 150" << std::endl;
		v.reserve(150);
		std::cout << "Capacity of v: " << v.capacity() << std::endl;
		std::cout << "Content of v: ";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << " " << v[i];
		std::cout << std::endl;
		
		std::cout << std::endl;
	}

	/*********************************************************/
	/*						MODIFIERS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       MODIFIERS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::vector<int> v(3, 7);
		ft::vector<int> v1(3);
		v1[0] = 1;
		v1[1] = 2;
		v1[2] = 3;
		ft::vector<int>::iterator it_begin = v1.begin();
		ft::vector<int>::iterator it_end = v1.end();
		ft::vector<int> v2(3);
		v2[0] = 1;
		v2[1] = 2;
		v2[2] = 3;
		ft::vector<std::string> vs(1, "abc");

		/* assign */
		std::cout << "Content of v before assign:";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << " " << v[i];
		std::cout << std::endl;
		std::cout << "// assign 7 9" << std::endl;
		v.assign(7, 9);
		std::cout << "Content of v after assign:";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << " " << v[i];
		std::cout << std::endl;

		std::cout << "// assign with iterators" << std::endl;
		v.assign(it_begin, it_end);
		std::cout << "Content of v after assign:";
		for (size_t i = 0; i < v.size(); i++)
			std::cout << " " << v[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* clear */
		std::cout << "Size v before clear: " << v.size() << std::endl;
		v.clear();
		std::cout << "Size v after clear: " << v.size() << std::endl;

		std::cout << std::endl;

		/* insert */
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;
		std::cout << "// insert vs.begin() test" << std::endl;
		vs.insert(vs.begin(), "test");
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;

		std::cout << "// insert vs.begin() 3 third" << std::endl;
		vs.insert(vs.begin(), 3, "third");
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;

		std::vector<std::string> vs1(3);
		vs1[0] = "last1";
		vs1[1] = "last2";
		vs1[2] = "last3";
		std::cout << "// insert vs.begin() vs1.begin() vs1.end()" << std::endl;
		vs.insert(vs.begin(), vs1.begin(), vs1.end());
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;
		
		/* erase */
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;
		std::cout << "// erase 2" << std::endl;
		v2.erase(v2.begin() + 1);
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;

		v2.push_back(4);
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;

		std::cout << "// erase begin() begin() + 2" << std::endl;
		v2.erase(v2.begin(), v2.begin() + 2);
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* push_back */
		std::cout << "// push_back def" << std::endl;
		vs.push_back("def");
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* pop_back */
		std::cout << "// pop_back" << std::endl;
		vs.pop_back();
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* resize */
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "// resize 5" << std::endl;
		v1.resize(5);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "// resize 2" << std::endl;
		v1.resize(2);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "// resize 6 (initializer = 4)" << std::endl;
		v1.resize(6, 4);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;

		std::cout << std::endl;

		/* swap */
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;
		std::cout << "// swap v1 with v2" << std::endl;
		v1.swap(v2);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;
		std::cout << "// swap v2 with v1" << std::endl;
		v2.swap(v1);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;

		std::cout << std::endl;
		
		/* swap (ext) */
		std::cout << "// swap v1/v2" << std::endl;
		ft::swap(v1, v2);
		std::cout << "Content of v1:";
		for (size_t i = 0; i < v1.size(); i++)
			std::cout << " " << v1[i];
		std::cout << std::endl;
		std::cout << "Content of v2:";
		for (size_t i = 0; i < v2.size(); i++)
			std::cout << " " << v2[i];
		std::cout << std::endl;

		std::cout << std::endl;
	}

	/*********************************************************/
	/*						ITERATORS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                        ITERATORS                      */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::vector<int> empty;
		ft::vector<int>::iterator empty_it_begin = empty.begin();
		ft::vector<int>::iterator empty_it_end = empty.end();

		ft::vector<int> v(3);
		v[0] = 1;
		v[1] = 2;
		v[2] = 3;
		ft::vector<int>::iterator it_begin = v.begin();
		ft::vector<int>::iterator it_end = v.end();

		ft::vector<int>::const_iterator it_begin1 = v.begin();
		ft::vector<int>::const_iterator it_end1 = v.end();

		ft::vector<int>::reverse_iterator it_rbegin = v.rbegin();
		ft::vector<int>::reverse_iterator it_rend = v.rend();

		ft::vector<int>::const_reverse_iterator it_rbegin1 = v.rbegin();
		ft::vector<int>::const_reverse_iterator it_rend1 = v.rend();

		/* begin and end */
		std::cout << "Content of v with iterators:";
		for (; it_begin < it_end; it_begin++)
			std::cout << " " << *it_begin;
		std::cout << std::endl;

		std::cout << "Is empty really empty : " << (empty_it_begin == empty_it_end) << std::endl;

		std::cout << std::endl;

		/* begin and end const */
		std::cout << "Content of v with const iterators:";
		for (; it_begin1 < it_end1; it_begin1++)
			std::cout << " " << *it_begin1;
		std::cout << std::endl;

		std::cout << std::endl;

		/* rbegin and rend */
		std::cout << "Content of v with reverse iterators:";
		for (; it_rbegin < it_rend; it_rbegin++)
			std::cout << " " << *it_rbegin;
		std::cout << std::endl;

		std::cout << std::endl;

		/* rbegin and rend const */
		std::cout << "Content of v with const reverse iterators:";
		for (; it_rbegin1 < it_rend1; it_rbegin1++)
			std::cout << " " << *it_rbegin1;
		std::cout << std::endl;

	}
}
