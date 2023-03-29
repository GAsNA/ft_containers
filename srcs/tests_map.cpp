#include "map/map.hpp"

#include <map>
#include <string>

int main()
{
	/*********************************************************/
	/*						CONSTRUCTORS					 */
	/*********************************************************/
	{
		/* Default */	
		ft::map<int, int> v;

		/* With value */
		ft::map<int, int> v2;
		v2.insert(ft::make_pair(0, 7));
		v2.insert(ft::make_pair(1, 7));
		
		/* By iterators */
		ft::map<int, int> test;
		test.insert(ft::make_pair(0, 4));
		test.insert(ft::make_pair(9, 7));
		ft::map<int, int> v3(test.begin(), test.end());
		
		/* By copy */
		ft::map<int, int> v4(v2);
	}

	/*********************************************************/
	/*						OPERATORS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       OPERATORS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;
		
		ft::map<std::string, std::string> v1;
		v1.insert((ft::make_pair("0", "Hello")));
		v1.insert((ft::make_pair("1", "Hello")));
		v1.insert((ft::make_pair("2", "Hello")));
		v1.insert((ft::make_pair("3", "Hello")));

		ft::map<char, int> vint;
		vint.insert(ft::make_pair('a', 1));
		vint.insert(ft::make_pair('b', 2));
		vint.insert(ft::make_pair('c', 3));
		ft::map<char, int> vint1;
		vint1.insert(ft::make_pair('a', 2));
		vint1.insert(ft::make_pair('b', 3));
		vint1.insert(ft::make_pair('c', 4));
		ft::map<char, int> vint2 = vint;
		
		/* = */
		ft::map<std::string, std::string> test;
		test.insert(ft::make_pair("0", "Hello"));
		test.insert(ft::make_pair("1", "World"));
		test.insert(ft::make_pair("2", "!"));
		ft::map<std::string, std::string> v = test;

		std::cout << std::endl;

		/* [] */
		std::cout << "test:\t\t\t";
		std::cout << test["0"] << " ";
		std::cout << test["1"] << " ";
		std::cout << test["2"] << " ";
		std::cout << std::endl;
		std::cout << "v:\t\t\t";
		std::cout << v["0"] << " ";
		std::cout << v["1"] << " ";
		std::cout << v["2"] << " ";
		std::cout << std::endl;
		std::cout << "v1:\t\t\t";
		std::cout << v1["0"] << " ";
		std::cout << v1["1"] << " ";
		std::cout << v1["2"] << " ";
		std::cout << v1["3"] << " ";
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
		for (char i = 'a'; i <= 'c'; i++)
			std::cout << " " << vint[i];
		std::cout << std::endl;
		std::cout << "Content of vint1:";
		for (char i = 'a'; i <= 'c'; i++)
			std::cout << " " << vint1[i];
		std::cout << std::endl;
		std::cout << "Content of vint2:";
		for (char i = 'a'; i <= 'c'; i++)
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
	/*						CAPACITY						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       CAPACITY                        */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::map<std::string, int> empty;
		ft::map<int, char> v;
		v.insert(ft::make_pair(0, '7'));
		v.insert(ft::make_pair(1, '7'));
		v.insert(ft::make_pair(2, '7'));
		v.insert(ft::make_pair(3, '7'));
		v.insert(ft::make_pair(4, '7'));
		v.insert(ft::make_pair(5, '7'));
		v.insert(ft::make_pair(6, '7'));
		v.insert(ft::make_pair(7, '7'));
		v.insert(ft::make_pair(8, '7'));
		
		/* empty */
		std::cout << "empty is empty: " << empty.empty() << std::endl;
		std::cout << "v is empty: " << v.empty() << std::endl;

		std::cout << std::endl;

		/* size */
		std::cout << "Size of empty: " << empty.size() << std::endl;
		std::cout << "Size of v: " << v.size() << std::endl;

		std::cout << std::endl;

		/* max_size */
		std::cout << "Max size of v: " << v.max_size() << std::endl;

		std::cout << std::endl;
	}

	/*********************************************************/
	/*						MODIFIERS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       MODIFIERS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::map<int, int> v;
		v.insert(ft::make_pair(0, 7));
		v.insert(ft::make_pair(1, 7));
		v.insert(ft::make_pair(2, 7));
		ft::map<int, int> v1;
		v1.insert(ft::make_pair(0, 1));
		v1.insert(ft::make_pair(1, 2));
		v1.insert(ft::make_pair(2, 3));
		ft::map<int, int>::iterator it_begin = v1.begin();
		ft::map<int, int>::iterator it_end = v1.end();
		ft::map<int, int> v2;
		v2.insert(ft::make_pair(0, 1));
		v2.insert(ft::make_pair(1, 2));
		v2.insert(ft::make_pair(2, 3));
		ft::map<int, std::string> vs;
		vs.insert(ft::make_pair(0, "abc"));

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
		std::cout << "// insert vs.begin() 1,test" << std::endl;
		vs.insert(vs.begin(), ft::make_pair(1, "test"));
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;

		ft::map<int, std::string> vs1;
		vs1.insert(ft::make_pair(2, "last1"));
		vs1.insert(ft::make_pair(3, "last2"));
		vs1.insert(ft::make_pair(4, "last3"));
		std::cout << "// insert vs1.begin() vs1.end()" << std::endl;
		vs.insert(vs1.begin(), vs1.end());
		std::cout << "Content of vs:";
		for (size_t i = 0; i < vs.size(); i++)
			std::cout << " " << vs[i];
		std::cout << std::endl;
		
		/* erase */
		std::cout << "Content of v2:";
		ft::map<int, int>::iterator	it = v2.begin();
		ft::map<int, int>::iterator	ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "// erase 1|2" << std::endl;
		v2.erase(++v2.begin());
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		v2.insert(ft::make_pair(3, 4));
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		std::cout << "// erase begin() begin() + 2" << std::endl;
		v2.erase(v2.begin(), ++(++v2.begin()));
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		std::cout << "// erase 666" << std::endl;
		v2.erase(666);
		std::cout << "// erase 3" << std::endl;
		v2.erase(3);
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		std::cout << std::endl;

		/* swap */
		v2.insert(ft::make_pair(3, 4));
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "// swap v1 with v2" << std::endl;
		v1.swap(v2);
		std::cout << "Content of v1:";
		it = v1.begin();
		ite = v1.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "// swap v2 with v1" << std::endl;
		v2.swap(v1);
		std::cout << "Content of v1:";
		it = v1.begin();
		ite = v1.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		std::cout << std::endl;
		
		/* swap (ext) */
		std::cout << "// swap v1/v2" << std::endl;
		ft::swap(v1, v2);
		std::cout << "Content of v1:";
		it = v1.begin();
		ite = v1.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;
		std::cout << "Content of v2:";
		it = v2.begin();
		ite = v2.end();
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
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

		ft::map<int, int> empty;
		ft::map<int, int>::iterator empty_it = empty.begin();
		ft::map<int, int>::iterator empty_ite = empty.end();

		ft::map<int, int> v;
		v.insert(ft::make_pair(0, 1));
		v.insert(ft::make_pair(1, 2));
		v.insert(ft::make_pair(2, 3));
		ft::map<int, int>::iterator it = v.begin();
		ft::map<int, int>::iterator ite = v.end();

		ft::map<int, int>::const_iterator it1 = v.begin();
		ft::map<int, int>::const_iterator ite1 = v.end();

		ft::map<int, int>::reverse_iterator itr = v.rbegin();
		ft::map<int, int>::reverse_iterator itre = v.rend();

		ft::map<int, int>::const_reverse_iterator itr1 = v.rbegin();
		ft::map<int, int>::const_reverse_iterator itre1 = v.rend();

		/* begin and end */
		std::cout << "Content of v with iterators:";
		for (; it != ite; it++)
			std::cout << " " << (*it).first << "|" << (*it).second;
		std::cout << std::endl;

		std::cout << "Is empty really empty : " << (empty_it == empty_ite) << std::endl;

		std::cout << std::endl;

		/* begin and end const */
		std::cout << "Content of v with const iterators:";
		for (; it1 != ite1; it1++)
			std::cout << " " << (*it1).first << "|" << (*it1).second;
		std::cout << std::endl;

		std::cout << std::endl;

		/* rbegin and rend */
		std::cout << "Content of v with reverse iterators:";
		for (; itr != itre; itr++)
			std::cout << " " << (*itr).first << "|" << (*itr).second;
		std::cout << std::endl;

		std::cout << std::endl;

		/* rbegin and rend const */
		std::cout << "Content of v with const reverse iterators:";
		for (; itr1 != itre1; itr1++)
			std::cout << " " << (*itr1).first << "|" << (*itr1).second;
		std::cout << std::endl;

	}

	/*********************************************************/
	/*						LOOKUP							 */
	/*********************************************************/
	{}


	/*********************************************************/
	/*						OBSERVERS						 */
	/*********************************************************/
	{}
}
