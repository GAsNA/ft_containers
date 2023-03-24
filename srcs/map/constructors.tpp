template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const Compare &comp, const Allocator &alloc): _tree()
{
	static_cast<void>(comp);
	static_cast<void>(alloc);
}

template <class Key, class T, class Compare, class Allocator>
template <class InputIt>
ft::map<Key, T, Compare, Allocator>::map(InputIt first, InputIt last, const Compare &comp, const Allocator &alloc) : _tree()
{
	static_cast<void>(comp);
	static_cast<void>(alloc);
	insert(first, last);
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::map(const map<Key, T, Compare, Allocator> &other)
{
	insert(other.begin(), other.end());
}

template <class Key, class T, class Compare, class Allocator>
ft::map<Key, T, Compare, Allocator>::~map() {}
