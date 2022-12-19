template <class T, class Cont>
ft::stack<T, Cont>::stack(const container_type& cont) : _cont(cont)
{}

template <class T, class Cont>
ft::stack<T, Cont>::stack(const stack& other) : _cont(other._cont)
{}

template <class T, class Cont>
ft::stack<T, Cont>::~stack()
{}
