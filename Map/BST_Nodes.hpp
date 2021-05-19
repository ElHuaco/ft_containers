/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BST_Nodes.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 09:46:29 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/19 09:22:25 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_NODES_HPP
# define BST_NODES_HPP

namespace ft
{
	template <class T> class BSTNode
	{
		public:
			typedef T									value_type;
//			typedef typename value_type::first_type		key_type;
//			typedef typename value_type::second_type	mapped_type;
			typedef BSTNode<value_type>					m_node;
			
		private:
			value_type		_data;
			m_node			*_left;
			m_node			*_right;
			m_node			*_parent;

		public:
			/* COPLIEN */
			explicit Node(const value_type &data = value_type()) : _data(data),
				_left(nullptr), _right(nullptr), _parent(nullptr)
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
				this->_left = rhs._left;
				this->_right = rhs._right;
				this->_parent = rhs._parent;
				return (*this);
			}
			/* SET(GET)TERS */
			m_node		*left(void)
			{
				return (this->_left);
			}
			m_node		*right(void)
			{
				return (this->_right);
			}
			m_node		*parent(void)
			{
				return (this->_parent);
			}
			m_node const *left(void) const
			{
				return (this->_left);
			}
			m_node const *right(void) const
			{
				return (this->_right);
			}
			m_node const *parent(void) const
			{
				return (this->_parent);
			}
			value_type	&getData(void)
			{
				return (this->_data);
			}
			const value_type &getData(void) const
			{
				return (this->_data);
			}	
	};
}
#endif
