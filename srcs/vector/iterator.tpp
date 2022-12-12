/* CONSTRUCTORS */
ft::IteratorVector() {}

ft::IteratorVector(pointer ptr) : _pointer(ptr) {}

ft::IteratorVector(const IteratorVector &x) : _pointer(x.pointer()) {}

ft::~IteratorVector() {};

/* OPERATORS */
IteratorVector	&ft::IteratorVector::operator=(const IteratorVector &rhs)
{
	if (this == &rhs) {return *this;}

	this->_pointer = rhs.pointer();
	return *this;
}

IteratorVector	&ft::IteratorVector::operator++()
{
	this->_pointer++;
	return *this;
}

IteratorVector	ft::IteratorVector::operator++(int)
{
	IteratorVector iv(*this);
	operator++();
	return iv;
}

IteratorVector	&ft::IteratorVector::operator--()
{
	this->_pointer--;
	return *this;
}

IteratorVector	ft::IteratorVector::operator--()
{
	IteratorVector iv(*this);
	operator--();
	return iv;
}

/* ACCESS  */
typename ft::IteratorVector::pointer	ft::IteratorVector::pointer()
{
	return this->_pointer;
}
