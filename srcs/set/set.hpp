/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2023/03/22 10:47:00 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SET_HPP
# define SET_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>

# include "../utils/utils.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/iterator_rbt.hpp"
# include "../utils/RedBlackTree_set.hpp"

namespace ft
{
	template <class Key, class Compare = std::less<Key>, class Allocator = std::allocator<Key> >
	class set
	{
		public:
			typedef Key																	key_type;
			typedef Key																	value_type;
			typedef std::size_t															size_type;
			typedef std::ptrdiff_t														difference_type;
			typedef Compare																key_compare;
			typedef	Compare																value_compare;
			typedef Allocator															allocator_type;
			typedef typename Allocator::reference										reference;
			typedef typename Allocator::const_reference									const_reference;
			typedef typename Allocator::pointer											pointer;
			typedef typename Allocator::const_pointer									const_pointer;
			typedef typename ft::RBT_set<value_type, key_type, key_compare, allocator_type>	rbt;
			typedef typename rbt::iterator												iterator;
			typedef typename rbt::const_iterator										const_iterator;
			typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			/* CONSTRUCTORS */
			explicit set(const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			template <class InputIt>
			set(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			set(const set<Key, Compare, Allocator> &other);
			~set();

			/* OPERATORS */
			set&			operator=(const set<Key, Compare, Allocator>& other);
			value_type&		operator[](const key_type& key);

			/* ACCESS */
			allocator_type	get_allocator() const;

			/* ITERATORS */
			iterator				begin();
			const_iterator			begin() const;
			iterator				end();
			const_iterator			end() const;
			reverse_iterator		rbegin();
			const_reverse_iterator	rbegin() const;
			reverse_iterator		rend();
			const_reverse_iterator	rend() const;

			/* CAPACITY */
			bool		empty() const;
			size_type	size() const;
			size_type	max_size() const;

			/* MODIFIERS */
			void					clear();
			pair<iterator, bool>	insert(const value_type& x);
			iterator				insert(iterator pos, const value_type& x);
			template <class InputIterator>
			void					insert(InputIterator first, InputIterator last);
			void					erase(iterator position);
			size_type				erase(const key_type& x);
			void					erase(iterator first, iterator last);
			void					swap(set<Key, Compare, Allocator>& set);

			/* LOOKUP */
			size_type									count(const key_type &key) const;
			iterator									find(const key_type &key);
			const_iterator								find(const key_type &key) const;
			pair<iterator, iterator>					equal_range(const key_type& key);
			pair<const_iterator, const_iterator>		equal_range(const key_type& key) const;
			iterator									lower_bound(const key_type& key);
			const_iterator								lower_bound(const key_type& key) const;
			iterator									upper_bound(const key_type& key);
			const_iterator								upper_bound(const key_type& key) const;

			/* OBSERVERS */
			key_compare		key_comp() const;
			value_compare	value_comp() const;

		private:
			rbt	_tree;
	};

	# include "constructors.tpp"
	# include "operators.tpp"
	# include "access.tpp"
	# include "iterators.tpp"
	# include "capacity.tpp"
	# include "modifiers.tpp"
	# include "lookup.tpp"
	# include "observers.tpp"
}

#endif
