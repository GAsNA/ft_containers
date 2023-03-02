#include "utils/RedBlackTree.hpp"

#include <iostream>

int main()
{
	ft::RBT<int> bst;

	std::cout << "Insertion 55, 40, 65, 60, 55 (do not add), 75, 57: " << std::endl;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(55); // twice same value (do not add)
	bst.insert(75);
	bst.insert(57);

	std::cout << std::endl;

	std::cout << "NB nodes (should be 6): " << bst.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Search node 55: " << (bst.search(55) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 60: " << (bst.search(60) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 57: " << (bst.search(57) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 45: " << (bst.search(45) != NULL ? "OK" : "KO") << std::endl;

	std::cout << std::endl;

	bst.printTree();

	std::cout << std::endl;
	
	std::cout << "Supp 65: " << std::endl;
	bst.deleteNode(65);
	bst.printTree();
	
	std::cout << std::endl;
	
	std::cout << "Supp 55: " << std::endl;
	bst.deleteNode(55);
	bst.printTree();
	
	std::cout << std::endl;

	std::cout << "Add 65: " << std::endl;
	bst.insert(65);
	bst.printTree();
	
	std::cout << std::endl;

	std::cout << "NB nodes (should be 5): " << bst.size() << std::endl;

	std::cout << std::endl;

	std::cout << "ITERATORS TESTS" << std::endl;

	ft::RBT<int>::iterator	it = bst.begin();
	ft::RBT<int>::iterator	end = bst.end();
	for (; it < end; it++) { std::cout << *it << std::endl; }
}
