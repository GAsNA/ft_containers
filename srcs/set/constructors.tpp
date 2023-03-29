template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::set(const Compare &comp, const Allocator &alloc): _tree()
{
	static_cast<void>(comp);
	static_cast<void>(alloc);
}

template <class Key, class Compare, class Allocator>
template <class InputIt>
ft::set<Key, Compare, Allocator>::set(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc) : _tree()
{
	static_cast<void>(comp);
	static_cast<void>(alloc);
	insert(first, last);
}

template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::set(const set<Key, Compare, Allocator> &other)
{
	insert(other.begin(), other.end());
}

template <class Key, class Compare, class Allocator>
ft::set<Key, Compare, Allocator>::~set() {}
