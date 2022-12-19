/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/19 18:53:04 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>
# include <vector>

# include "../utils/utils.hpp"
# include "../vector/vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container									container_type;
			typedef typename container_type::value_type			value_type;
			typedef typename container_type::size_type			size_type;
			typedef typename container_type::reference			reference;
			typedef typename container_type::const_reference	const_reference;

			/* CONSTRUCTORS */
			explicit stack(const container_type& cont = container_type());
			stack(const stack& other);
			~stack();

			/* OPERATORS */
			stack&	operator=(const stack& other);
			template <class T2, class Container2>
			friend bool operator==(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
			template <class T2, class Container2>
			friend bool operator!=(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
			template <class T2, class Container2>
			friend bool operator<(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
			template <class T2, class Container2>
			friend bool operator<=(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
			template <class T2, class Container2>
			friend bool operator>(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);
			template <class T2, class Container2>
			friend bool operator>=(const stack<T2, Container2>& lhs, const stack<T2, Container2>& rhs);

			/* ACCESS */
			reference		top();
			const_reference	top() const;

			/* CAPACITY */
			bool		empty() const;
			size_type	size() const;

			/* MODIFIERS */
			void	push(const value_type &value);
			void	pop();

		protected:
			container_type _cont;
	};

	# include "operators.tpp"
	# include "constructors.tpp"
	# include "access.tpp"
	# include "capacity.tpp"
	# include "modifiers.tpp"
}

#endif
