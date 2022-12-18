#include "vector.hpp"
#include <list>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &deq, bool print_content = 1)
{
	std::cout << "size: " << deq.size() << std::endl;
	std::cout << "max_size: " << deq.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = deq.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = deq.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	std::list<TESTED_TYPE> lst;
	std::list<TESTED_TYPE>::iterator lst_it;
	for (int i = 1; i < 5; ++i)
		lst.push_back(i * 3);

	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(lst.begin(), lst.end());
	printSize(vct);

	lst_it = lst.begin();
	for (int i = 1; lst_it != lst.end(); ++i)
		*lst_it++ = i * 5;
	vct.assign(lst.begin(), lst.end());
	printSize(vct);

	vct.insert(vct.end(), lst.rbegin(), lst.rend());
	printSize(vct);
	return (0);
}
