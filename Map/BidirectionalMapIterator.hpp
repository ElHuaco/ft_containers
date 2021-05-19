/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalMapIterator.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:09:55 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/19 09:53:16 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_MAP_ITERATOR_HPP
# define BIDIRECTIONAL_MAP_ITERATOR_HPP

# include <iterator>
# include "BST_Nodes.hpp"

namespace ft
{
	template <class T> class BidirectionalMapIterator
		: public std::iterator<std::bidirectional_iterator_tag, BSTNode<T> >
	{
		public:
			typedef T			value_type;
			typedef Node		*pointer;
			typedef Node		&reference;

		private:
			pointer		_ptr;
	
		public:
			explicit BidirectionalMapIterator(pointer defptr = nullptr) :
				_ptr(defptr)
			{
			}
			BidirectionalMapIterator(const BidirectionalMapIterator &other)
			{
				_ptr = other._ptr;
			}
			virtual ~BidirectionalMapIterator(void)
			{
			}
			BidirectionalMapIterator	&operator=(const pointer newNode)
			{
				_ptr = newNode;
				return (*this);
			}
			BidirectionalMapIterator	&operator=(const BidirectionalMapIterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				_ptr = rhs._ptr;
				return (*this);
			}
			T&			operator*(void) const
			{
				return (_ptr->getData());
			}
			T*			operator->(void) const
			{
				return (&_ptr->getData());
			}
			BidirectionalMapIterator	&operator++(void)
			{
				pointer tmp;
				if ((tmp = _ptr->right()) != nullptr)
				{
					while (tmp->left() != nullptr)
						tmp = tmp->left();
				}
				else
				{
					while ((tmp = _ptr->parent()) != nullptr
						&& _ptr == tmp->right())
						_ptr = tmp;
				}
				_ptr = tmp;
				return (*this);
			}
			BidirectionalMapIterator	operator++(int)
			{
				BidirectionalMapIterator temp = *this;
				this->operator++();
				return (temp);
			}
			BidirectionalMapIterator	operator++(int) const
			{
				BidirectionalMapIterator temp = *this;
				this->operator++();
				return (temp);
			}

			BidirectionalMapIterator	&operator--(void)
			{
				pointer tmp;
				if ((tmp = _ptr->left()) != nullptr)
				{
					while (tmp->right() != nullptr)
						tmp = tmp->right();
				}
				else
				{
					while ((tmp = _ptr->parent()) != nullptr
						&& _ptr == tmp->left())
						_ptr = tmp;
				}
				_ptr = tmp;
				return (*this);
			}
			BidirectionalMapIterator	operator--(int)
			{
				BidirectionalMapIterator temp = *this;
				this->operator--();
				return (temp);
			}
			BidirectionalMapIterator	operator--(int) const
			{
				BidirectionalMapIterator temp = *this;
				this->operator--();
				return (temp);
			}
			pointer		getPointer(void) const
			{
				return (_ptr);
			}
			void		setPointer(pointer newPtr)
			{
				_ptr = newPtr;
			}
	};
	template <class T, class Node>
		bool operator== (const BidirectionalMapIterator<T, Node> &lhs,
			const BidirectionalMapIterator<T, Node> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class T, class Node>
		bool operator!= (const BidirectionalMapIterator<T, Node> &lhs,
			const BidirectionalMapIterator<T, Node> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
	template <class Base> class ReverseMapIterator :
		public std::reverse_iterator<Base>
	{
		public:
			typedef typename std::reverse_iterator<Base>	base_iterator;
			typedef typename base_iterator::value_type		value_type;
			typedef typename base_iterator::pointer			pointer;
			typedef typename base_iterator::reference		reference;

			explicit ReverseMapIterator(void) : base_iterator()
			{
			}
			ReverseMapIterator(const typename base_iterator::iterator_type &it)
				: base_iterator(it)
			{
			}
			ReverseMapIterator(const base_iterator &it) : base_iterator(it)
			{
			}
			ReverseMapIterator(pointer defptr)
				: base_iterator(typename base_iterator::iterator_type(defptr))
			{
			}
			virtual ~ReverseMapIterator(void)
			{
			}
			ReverseMapIterator &operator=(const ReverseMapIterator &rhs)
			{
				this->base()._ptr = rhs.base()._ptr;
				return (*this);
			}
			ReverseMapIterator operator++(int)
			{
				return (base_iterator::operator++(1));
			}
			ReverseMapIterator operator++(int) const
			{
				return (base_iterator::operator++(1));
			}
			ReverseMapIterator operator++(void)
			{
				base_iterator::operator++();
				return (*this);
			}
			ReverseMapIterator operator--(int)
			{
				return (base_iterator::operator--(1));
			}
			ReverseMapIterator operator--(int) const
			{
				return (base_iterator::operator--(1));
			}
			ReverseMapIterator operator--(void)
			{
				base_iterator::operator--();
				return (*this);
			}
			value_type	&operator*(void) const
			{
				return (this->base().getPointer()->getData());
			}
			value_type *operator->(void) const
			{
				return (&this->base().getPointer()->getData());
			}
			pointer		getPointer(void) const
			{
				return (this->base().getPointer());
			}
			void		setPointer(pointer newPtr)
			{
				this->base()._ptr = newPtr;
			}
	};
	template <class Base>
		bool operator== (const ReverseMapIterator<Base> &lhs,
			const ReverseMapIterator<Base> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class Base>
		bool operator!= (const ReverseMapIterator<Base> &lhs,
			const ReverseMapIterator<Base> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
}
#endif
