ft::RBT::RBT()
{
	this->TNULL = new Node;
	this->TNULL->color = 0;
	this->TNULL->left = NULL;
	this->TNULL->right = NULL;
	this->root = TNULL;
}
