#include "stack/stack.hpp"

#include <stack>
#include <string>

int main()
{
	/*********************************************************/
	/*						CONSTRUCTORS					 */
	/*********************************************************/
	{
		/* Default */	
		ft::stack<int> v;

		/* By copy */
		ft::stack<int> v1(v);
	}

	/*********************************************************/
	/*						OPERATORS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       OPERATORS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;
		
		ft::stack<std::string> v1;

		ft::stack<int> vint;
		vint.push(1);
		vint.push(2);
		vint.push(3);
		ft::stack<int> vint1;
		vint1.push(2);
		vint1.push(3);
		vint1.push(4);
		ft::stack<int> vint2 = vint;
		
		/* = */
		ft::stack<std::string> test;
		test.push("Hello");
		test.push("World");
		test.push("!");
		ft::stack<std::string> v = test;

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

		std::cout << "Content of vint:";
		while (vint.size() > 0)
		{
			std::cout << " " << vint.top();
			vint.pop();
		}
		std::cout << std::endl;
		std::cout << "Content of vint1:";
		while (vint1.size() > 0)
		{
			std::cout << " " << vint1.top();
			vint1.pop();
		}
		std::cout << std::endl;
		std::cout << "Content of vint2:";
		while (vint2.size() > 0)
		{
			std::cout << " " << vint2.top();
			vint2.pop();
		}
		std::cout << std::endl;

		std::cout << std::endl;
	}

	/*********************************************************/
	/*						ACCESS							 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                         ACCESS                        */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;
		
		ft::stack<int> data;
		data.push(1);
		data.push(2);
		data.push(4);
		data.push(5);
		data.push(5);
		data.push(6);

		/* top */
		std::cout << "Top element of data: " << data.top() << std::endl;

		std::cout << std::endl;
	}
	
	/*********************************************************/
	/*						CAPACITY						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       CAPACITY                        */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::stack<int> empty;
		ft::stack<int> v;
		v.push(1);
		v.push(2);
		v.push(4);
		v.push(5);
		v.push(5);
		v.push(6);
		
		/* empty */
		std::cout << "empty is empty: " << empty.empty() << std::endl;
		std::cout << "v is empty: " << v.empty() << std::endl;

		std::cout << std::endl;

		/* size */
		std::cout << "Size of empty: " << empty.size() << std::endl;
		std::cout << "Size of v: " << v.size() << std::endl;

		std::cout << std::endl;
	}

	/*********************************************************/
	/*						MODIFIERS						 */
	/*********************************************************/
	{
		std::cout << "/*********************************************************/" << std::endl;
		std::cout << "/*                       MODIFIERS                       */" << std::endl;
		std::cout << "/*********************************************************/" << std::endl;

		ft::stack<std::string> vs;
		vs.push("abc");

		/* push */
		std::cout << "// push def" << std::endl;
		vs.push("def");
		std::cout << "Content of vs:";
		while (vs.size() > 0)
		{
			std::cout << " " << vs.top();
			vs.pop();
		}
		std::cout << std::endl;

		std::cout << std::endl;

		/* pop */
		vs.push("abc");
		vs.push("def");
		std::cout << "// pop" << std::endl;
		vs.pop();
		std::cout << "Content of vs:";
		while (vs.size() > 0)
		{
			std::cout << " " << vs.top();
			vs.pop();
		}
		std::cout << std::endl;

		std::cout << std::endl;
	}
}
