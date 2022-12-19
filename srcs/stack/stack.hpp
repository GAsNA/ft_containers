/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rleseur <rleseur@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 15:42:02 by rleseur           #+#    #+#             */
/*   Updated: 2022/12/19 17:08:36 by rleseur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include <iostream>
# include <string>
# include <memory>
# include <stdexcept>
# include <iterator>

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
			friend bool operator==(const stack& lhs, const stack& rhs);
			friend bool operator!=(const stack& lhs, const stack& rhs);
			friend bool operator<(const stack& lhs, const stack& rhs);
			friend bool operator<=(const stack& lhs, const stack& rhs);
			friend bool operator>(const stack& lhs, const stack& rhs);
			friend bool operator>=(const stack& lhs, const stack& rhs);

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
}

# include "constructors.tpp"
# include "operators.tpp"
# include "access.tpp"
# include "capacity.tpp"
# include "modifiers.tpp"

#endif
