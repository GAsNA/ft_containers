/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/19 18:56:46 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>

# include "../utils/utils.hpp"
# include "../iterators/iterator_vector.hpp"
# include "../iterators/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T> >
	class vector
	{
		public:
			typedef Allocator											allocator_type;
			typedef typename allocator_type::value_type					value_type;
			typedef typename allocator_type::size_type					size_type;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename ft::iterator_vector<T>						iterator;
			typedef typename ft::iterator_vector<const T>				const_iterator;
			typedef typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;
			
			/* CONSTRUCTORS */
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
			vector (const vector &x);
			~vector();

			/* OPERATORS */
			vector	&operator=(const vector &rhs);
			T		&operator[](const int i) const;

			/* ACCESS */
			allocator_type	get_allocator() const;
			reference		at(size_type pos);
			const_reference	at(size_type pos) const;
			reference		front();
			const_reference	front() const;
			reference		back();
			const_reference	back() const;
			T*				data();
			const T*		data() const;

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
			void		reserve(size_type new_cap);
			size_type	capacity() const;

			/* MODIFIERS */
			void		assign(size_type count, const T& value);
			template <class InputIt>
			void		assign(InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
			void		clear();
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			template <class InputIt>
			void		insert(iterator position, InputIt first, InputIt last, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
			iterator	erase(iterator position);
			iterator	erase(iterator first, iterator last);
			void		push_back(const T& value);
			void		pop_back();
			void		resize(size_type count, T value = T());
			void		swap(vector &other);

		private:
			pointer			_datas;
			size_type		_size;
			size_type		_capacity;
			allocator_type	_alloc;
	};

	# include "constructors.tpp"
	# include "operators.tpp"
	# include "access.tpp"
	# include "capacity.tpp"
	# include "modifiers.tpp"
	# include "iterators.tpp"
}

#endif
