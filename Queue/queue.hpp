/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:56:25 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/25 08:43:24 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/list.hpp"

namespace ft
{
	template <class T, class Container = ft::list<T> > class queue
	{
		public:
			typedef T			value_type;
			typedef Container	container_type;
			typedef size_t		size_type;

		private:
			container_type		_c;
			queue(const queue &other);

		public:
			explicit queue(const container_type &cntr = container_type()) :
				_c(cntr)
			{
			}
			~queue(void)
			{
			}
			queue		&operator=(const queue &rhs)
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
			value_type	&back(void)
			{
				return (this->_c.back());
			}
			const value_type	&back(void) const
			{
				return (this->_c.back());
			}
			value_type	&front(void)
			{
				return (this->_c.front());
			}
			const value_type	&front(void) const
			{
				return (this->_c.front());
			}
			void		push(const value_type &val)
			{
				this->_c.push_back(val);
			}
			void		pop(void)
			{
				this->_c.pop_front();
			}
	};
	template <class T, class Container>
	bool operator==(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c == rhs._c);
	}
	template <class T, class Container>
	bool operator!=(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c != rhs._c);
	}
	template <class T, class Container>
	bool operator<(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c < rhs._c);
	}
	template <class T, class Container>
	bool operator<=(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c <= rhs._c);
	}
	template <class T, class Container>
	bool operator>(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c > rhs._c);
	}
	template <class T, class Container>
	bool operator>=(const ft::queue<T, Container> &lhs, const ft::queue<T, Container> &rhs)
	{
		return (lhs._c >= rhs._c);
	}
};
#endif
