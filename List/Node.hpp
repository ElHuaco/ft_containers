/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:49:35 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/05 13:36:16 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	template <class T> class Node
	{
		public:
			typedef T					value_type;
			typedef Node<value_type>	m_node;

		private:
			value_type		_data;
			m_node			*_next;
			m_node			*_prev;
	
		public:
			/* COPLIEN */
			explicit Node(const value_type &data = value_type()) : _data(data),
				_next(nullptr), _prev(nullptr)
			{
			}
			Node(const Node &other)
			{
				*this = other;
			}
			~Node(void)
			{
			}
			Node	&operator=(const Node &rhs)
			{
				if (this == &rhs)
					return (*this);
				this->_data = rhs._data;
				this->_next = rhs._next;
				this->_prev = rhs._prev;
				return (*this);
			}
			/* SET(GET)ERS */
			m_node		*next(void) const
			{
				return (this->_next);
			}
			m_node		*prev(void) const
			{
				return (this->_prev);
			}
			value_type	getData(void) const
			{
				return (this->_data);
			}
			void		setNext(m_node *ptr)
			{
				this->_next = ptr;
			}
			void		setPrev(m_node *ptr)
			{
				this->_prev = ptr;
			}
			void		setData(value_type data)
			{
				this->_data = data;
			}
			/* METHODS FOR INSERT */
			void		insertBefore(m_node *ptr)
			{
				ptr->_prev = this->_prev;
				if (this->_prev)
					this->_prev->_next = ptr;
				this->_prev = ptr;
				ptr->_next = this;
			}
			void		insertAfter(m_node *ptr)
			{
				ptr->_next = this->_next;
				if (this->_next)
					this->_next->_prev = ptr;
				this->_next = ptr;
				ptr->_prev = this;
			}
	};
}
#endif
