#include "utils/RedBlackTree.hpp"

#include <iostream>

int main() {

	/*ft::Node<int>	node(7);
	std::cout << "color: " << node.color << std::endl;
	std::cout << "value: " << node.value << std::endl;*/

	ft::RBT<int> bst;
	bst.insert(55);
	bst.insert(40);
	bst.insert(65);
	bst.insert(60);
	bst.insert(55);
	bst.insert(75);
	bst.insert(57);

	std::cout << "NB nodes (should be 7): " << bst.size() << std::endl;

	std::cout << std::endl;

	std::cout << "Search node 55: " << (bst.search(55) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 60: " << (bst.search(60) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 57: " << (bst.search(57) != NULL ? "OK" : "KO") << std::endl;
	std::cout << "Search node 45: " << (bst.search(45) != NULL ? "OK" : "KO") << std::endl;

	std::cout << std::endl;

	bst.printTree();
	/*std::cout << std::endl << "After deleting" << std::endl;
	bst.deleteNode(40);
	bst.printTree();*/
}
