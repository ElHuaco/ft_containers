/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:39:40 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/17 11:53:17 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../List/list.hpp"

namespace ft
{
	typename <class T, class Container = ft::list<T> > class stack
	{
		public:
			typename T			value_type;
			typename Container	container_type;
			typename size_t		size_type;

		private:
			container_type		_c;
			stack(const stack &other);

		public:
			explicit stack(const container_type &cntr = container_type()) :
				_c(cntr)
			{
			}
			~stack(void)
			{
			}
			stack		&operator=(const stack &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_c = rhs._c;
				return (*this);
			}
			bool		empty(void) const
			{
				return (this->_c.empty());
			}
			size_type	size(void) const
			{
				return (this->_c.size());
			}
			value_type	&top(void)
			{
				return (this->_c.back());
			}
			const value_type	&top(void) const
			{
				return (this->_c.back());
			}
			void		push(const value_type &val)
			{
				this->_c.push_back(val);
			}
			void		pop(void)
			{
				this->_c.pop_back();
			}
	};
	template <class T, class Container>
	bool operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c == rhs._c);
	}
	template <class T, class Container>
	bool operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c != rhs._c);
	}
	template <class T, class Container>
	bool operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c < rhs._c);
	}
	template <class T, class Container>
	bool operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c <= rhs._c);
	}
	template <class T, class Container>
	bool operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c > rhs._c);
	}
	template <class T, class Container>
	bool operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs._c >= rhs._c);
	}
};
#endif
