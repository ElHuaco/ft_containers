/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:49:35 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/06 17:17:29 by alejandro        ###   ########.fr       */
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
			/* SET(GET)TERS */
			m_node		*&next(void)
			{
				return (this->_next);
			}
			m_node		*&prev(void)
			{
				return (this->_prev);
			}
			value_type	&getData(void)
			{
				return (this->_data);
			}
			const value_type &getData(void) const
			{
				return (this->_data);
			}	
			/* METHODS FOR INSERT */
			void		insertBefore(m_node *ptr)
			{
				if (ptr == nullptr)
					return ;
				ptr->_prev = this->_prev;
				if (this->_prev != nullptr)
					this->_prev->_next = ptr;
				this->_prev = ptr;
				ptr->_next = this;
				return ;
			}
			void		insertAfter(m_node *ptr)
			{
				if (ptr == nullptr)
					return ;
				ptr->_next = this->_next;
				if (this->_next != nullptr)
					this->_next->_prev = ptr;
				this->_next = ptr;
				ptr->_prev = this;
				return ;
			}
			/* METHODS FOR SWAP  */
			void		swap(m_node *ptr)
			{
				if (ptr == nullptr)
					return ;
				if (this->prev() != nullptr)
					this->prev()->next() = ptr;
				if (ptr->prev() != nullptr)
					ptr->prev()->next() = this;
				m_node *tmp = this->prev();
				this->prev() = ptr->prev();
				ptr->prev() = tmp;
				if (this->next() != nullptr)
					this->next()->prev() = ptr;
				if (ptr->next() != nullptr)
					ptr->next()->prev() = this;
				tmp = this->next();
				this->next() = ptr->next();
				ptr->next() = tmp;
				return ;
			}
	};
}
#endif
