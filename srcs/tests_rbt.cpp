#include "utils/RedBlackTree.hpp"

#include <iostream>

int main()
{
	ft::RBT<int> bst;

	std::cout << "Insertion 55, 40, 65, 60, 75, 57: " << std::endl;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(55);
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

	std::cout << "NB nodes (should be 4): " << bst.size() << std::endl;

	/*std::cout << "Supp 40: " << std::endl;
	bst.deleteNode(40);
	bst.printTree();
	std::cout << "Supp 60: " << std::endl;
	bst.deleteNode(60);
	bst.printTree();*/
}
