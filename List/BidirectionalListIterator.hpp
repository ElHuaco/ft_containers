/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalListIterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:38:17 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/12 10:34:40 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_LIST_ITERATOR_HPP
# define BIDIRECTIONAL_LIST_ITERATOR_HPP

# include <iterator>
# include "Node.hpp"

namespace ft
{
	template <class T, class Node> class BidirectionalListIterator
		: public std::iterator<std::bidirectional_iterator_tag, Node>
	{
		public:
			typedef T			value_type;
			typedef Node		*pointer;
			typedef Node		&reference;

		private:
			pointer		_ptr;
	
		public:
			explicit BidirectionalListIterator(pointer defptr = nullptr) : _ptr(defptr)
			{
			}
			BidirectionalListIterator(const BidirectionalListIterator &other)
			{
				_ptr = other._ptr;
			}
			virtual ~BidirectionalListIterator(void)
			{
			}
			BidirectionalListIterator	&operator=(const pointer newNode)
			{
				_ptr = newNode;
				return (*this);
			}
			BidirectionalListIterator	&operator=(const BidirectionalListIterator &rhs)
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
			BidirectionalListIterator	&operator++(void)
			{
				_ptr = _ptr->next();
				return (*this);
			}
			BidirectionalListIterator	operator++(int)
			{
				BidirectionalListIterator temp = *this;
				_ptr = _ptr->next();
				return (temp);
			}
			BidirectionalListIterator	operator++(int) const
			{
				BidirectionalListIterator temp = *this;
				_ptr = _ptr->next();
				return (temp);
			}

			BidirectionalListIterator	&operator--(void)
			{
				_ptr = _ptr->prev();
				return (*this);
			}
			BidirectionalListIterator	operator--(int)
			{
				BidirectionalListIterator temp = *this;
				_ptr = _ptr->prev();
				return (temp);
			}
			BidirectionalListIterator	operator--(int) const
			{
				BidirectionalListIterator temp = *this;
				_ptr = _ptr->prev();
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
		bool operator== (const BidirectionalListIterator<T, Node> &lhs,
			const BidirectionalListIterator<T, Node> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class T, class Node>
		bool operator!= (const BidirectionalListIterator<T, Node> &lhs,
			const BidirectionalListIterator<T, Node> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
	template <class Base> class ReverseListIterator :
		public std::reverse_iterator<Base>
	{
		public:
			typedef typename std::reverse_iterator<Base>	base_iterator;
			typedef typename base_iterator::value_type		value_type;
			typedef typename base_iterator::pointer			pointer;
			typedef typename base_iterator::reference		reference;

			explicit ReverseListIterator(void) : base_iterator()
			{
			}
			ReverseListIterator(const typename base_iterator::iterator_type &it)
				: base_iterator(it)
			{
			}
			ReverseListIterator(const base_iterator &it) : base_iterator(it)
			{
			}
			ReverseListIterator(pointer defptr)
				: base_iterator(typename base_iterator::iterator_type(defptr))
			{
			}
			virtual ~ReverseListIterator(void)
			{
			}
			ReverseListIterator &operator=(const ReverseListIterator &rhs)
			{
				this->base()._ptr = rhs.base()._ptr;
				return (*this);
			}
			ReverseListIterator operator++(int)
			{
				return (base_iterator::operator++(1));
			}
			ReverseListIterator operator++(int) const
			{
				return (base_iterator::operator++(1));
			}
			ReverseListIterator operator++(void)
			{
				base_iterator::operator++();
				return (*this);
			}
			ReverseListIterator operator--(int)
			{
				return (base_iterator::operator--(1));
			}
			ReverseListIterator operator--(int) const
			{
				return (base_iterator::operator--(1));
			}
			ReverseListIterator operator--(void)
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
		bool operator== (const ReverseListIterator<Base> &lhs,
			const ReverseListIterator<Base> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class Base>
		bool operator!= (const ReverseListIterator<Base> &lhs,
			const ReverseListIterator<Base> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
}
#endif
