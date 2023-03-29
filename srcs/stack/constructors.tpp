template <class T, class Cont>
ft::stack<T, Cont>::stack(const container_type& cont) : c(cont)
{}

template <class T, class Cont>
ft::stack<T, Cont>::stack(const stack& other) : c(other.c)
{}

template <class T, class Cont>
ft::stack<T, Cont>::~stack()
{}
