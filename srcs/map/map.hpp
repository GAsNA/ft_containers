/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2023/03/10 16:49:28 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>

# include "../utils/utils.hpp"
# include "../iterators/reverse_iterator.hpp"
# include "../iterators/iterator_rbt.hpp"
# include "../utils/RedBlackTree.hpp"

namespace ft
{
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
		public:
			typedef Key																	key_type;
			typedef T																	mapped_type;
			typedef ft::pair<const Key, T>												value_type;
			typedef std::size_t															size_type;
			typedef std::ptrdiff_t														difference_type;
			typedef Compare																key_compare;
			typedef Allocator															allocator_type;
			typedef typename Allocator::reference										reference;
			typedef typename Allocator::const_reference									const_reference;
			typedef typename Allocator::pointer											pointer;
			typedef typename Allocator::const_pointer									const_pointer;
			typedef typename ft::RBT<value_type, key_type, key_compare, allocator_type>	RBT;
			typedef typename RBT::iterator												iterator;
			typedef typename RBT::const_iterator										const_iterator;
			typedef typename ft::reverse_iterator<iterator>								reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			class value_compare: public std::binary_function<value_type, value_type, bool> {
				friend class map;
				protected:
					Compare comp;
					value_compare(Compare c) : comp(c) {}

				public:
					bool operator()(const value_type& x, const value_type& y) const { return comp(x.first, y.first); }
			};

			/* CONSTRUCTORS */
			explicit map(const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			template <class InputIt>
			map(InputIt first, InputIt last, const Compare &comp = Compare(), const Allocator &alloc = Allocator());
			map(const map &other);
			~map();

			/* OPERATORS */
			map&	operator=(const map& other);
			T&		operator[](const Key& key);

			/* ACCESS */
			T&				at(const Key &key);			// TODO
			const T&		at(const Key &key) const;	// TODO
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
			void					swap(map& map);

			/* LOOKUP */
			size_type									count(const Key &key) const;
			iterator									find(const Key &key);
			const_iterator								find(const Key &key) const;
			ft::pair<iterator, iterator>				equal_range(const Key& key);
			ft::pair<const_iterator, const_iterator>	equal_range(const Key& key) const;
			iterator									lower_bound(const Key& key);
			const_iterator								lower_bound(const Key& key) const;
			iterator									upper_bound(const Key& key);
			const_iterator								upper_bound(const Key& key) const;

			/* OBSERVERS */
			key_compare	key_comp() const;
			value_compare	value_comp() const;

			// TODO NON_MEMBER FUNCTIONS

		private:
			RBT	_tree;
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
