/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/16 12:10:41 by rleseur          ###   ########.fr       */
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

# include "iterators/IteratorVector.hpp"
# include "iterators/ReverseIteratorVector.hpp"

namespace ft
{
	template <class T, class Allocator = std::allocator<T>>
	class vector
	{
		public:
			typedef Allocator									allocator_type;
			typedef typename allocator_type::value_type			value_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename ft::IteratorVector<T>				iterator;
			typedef typename ft::IteratorVector<const T>		const_iterator;
			typedef typename ft::ReverseIteratorVector<T>		reverse_iterator;
			typedef typename ft::ReverseIteratorVector<const T>	const_reverse_iterator;
			
			class InvalidIndexException : public std::exception
			{
				public:
					virtual const char* what() const throw() {return "Invalid index!";}
			};

			// TODO 
				// std::distance !!!!!!!!!!!!!!!!!!!!!!!!!!
				// insert
				// erase

			/* CONSTRUCTORS */
			explicit vector (const allocator_type& alloc = allocator_type());
			explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
			template <class InputIterator>
			vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(), typename std::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL);
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
			void		assign(InputIt first, InputIt last, typename std::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type* = NULL);
			void		clear();
			iterator	insert(iterator position, const value_type& val);
			void		insert(iterator position, size_type n, const value_type& val);
			template <class InputIt>
			void		insert(iterator position, InputIt first, InputIt last);
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

	template <class T, class Alloc>
	void swap(vector<T,Alloc>& lhs, vector<T,Alloc>& rhs);
	
/*	template <class T, class Alloc>
	bool	operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
	template <class T, class Alloc>
	bool	operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs);
*/
}

# include "vector.tpp"

#endif
