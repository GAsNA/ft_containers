#include <iostream>
#include <iostream>
#include <memory>
#include <string>

#include "vector.hpp"

int main() {
	std::allocator<int> a1;
	int *tab = a1.allocate(5);

	tab[0] = 9;
	tab[3] = 7;

	a1.deallocate(tab, 5);



	std::allocator<std::string> a;
	std::string *str = a.allocate(3);

	a.construct(str, "Hello ");
	a.construct(&str[1], "World");
	a.construct(&str[2], "!");

	a.destroy(str);
	a.destroy(&str[1]);
	a.destroy(&str[2]);

	a.deallocate(str, 3);

}
