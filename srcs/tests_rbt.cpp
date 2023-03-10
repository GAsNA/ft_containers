#include "utils/RedBlackTree.hpp"

#include <iostream>

int main()
{
	ft::RBT<int, int> rbt;

	std::cout << "Insertion 55, 40, 65, 60, 55 (do not add), 75, 57: " << std::endl;
	rbt.insert(55);
	rbt.insert(40);
	rbt.insert(65);
	rbt.insert(60);
	rbt.insert(55); // twice same value (do not add)
	rbt.insert(75);
	rbt.insert(57);

	std::cout << std::endl;

	std::cout << "NB nodes (should be 6): " << rbt.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Search node 55: " << (rbt.search(55) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 60: " << (rbt.search(60) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 57: " << (rbt.search(57) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 45: " << (rbt.search(45) != NULL ? "OK" : "KO") << std::endl;

	std::cout << std::endl;

	rbt.printTree();

	std::cout << std::endl;
	
	std::cout << "Supp 65: " << std::endl;
	rbt.erase(65);
	rbt.printTree();
	
	std::cout << std::endl;
	
	std::cout << "Supp 55: " << std::endl;
	rbt.erase(55);
	rbt.printTree();
	
	std::cout << std::endl;

	std::cout << "Add 65: " << std::endl;
	rbt.insert(65);
	rbt.printTree();
	
	std::cout << std::endl;

	std::cout << "NB nodes (should be 5): " << rbt.size() << std::endl;

	std::cout << std::endl;

	std::cout << "/******************************************/" << std::endl;
	std::cout << "/*             ITERATORS TESTS            */" << std::endl;
	std::cout << "/******************************************/" << std::endl;

	std::cout << std::endl;

	std::cout << "Iterator++: ";

	ft::RBT<int, int>::iterator	it_plus = rbt.begin();
	ft::RBT<int, int>::iterator	end_plus = rbt.end();
	for (; it_plus != end_plus; it_plus++) { std::cout << *it_plus << ", "; }
	std::cout << "..." << std::endl;

	std::cout << std::endl;

	std::cout << "Iterator--: ";

	ft::RBT<int, int>::iterator	it_minus = rbt.end();
	ft::RBT<int, int>::iterator	end_minus = rbt.begin();
	it_minus--;
	for (; it_minus != end_minus; it_minus--) { std::cout << *it_minus << ", "; }
	std::cout << "..." << std::endl;

	std::cout << std::endl;

	std::cout << "Reverse Iterator++: ";

	ft::RBT<int, int>::reverse_iterator	it_rev_plus = rbt.rbegin();
	ft::RBT<int, int>::reverse_iterator	end_rev_plus = rbt.rend();
	for (; it_rev_plus != end_rev_plus; it_rev_plus++) { std::cout << *it_rev_plus << ", "; }
	std::cout << "..." << std::endl;

	std::cout << std::endl;

	std::cout << "Reverse Iterator--: ";

	ft::RBT<int, int>::reverse_iterator	it_rev_minus = rbt.rend();
	ft::RBT<int, int>::reverse_iterator	end_rev_minus = rbt.rbegin();
	it_rev_minus--;
	for (; it_rev_minus != end_rev_minus; it_rev_minus--) { std::cout << *it_rev_minus << ", "; }
	std::cout << "..." << std::endl;
}
