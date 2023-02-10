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

	bst.printTree();
	/*std::cout << std::endl << "After deleting" << std::endl;
	bst.deleteNode(40);
	bst.printTree();*/
}
