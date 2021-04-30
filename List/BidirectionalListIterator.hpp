/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalListIterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:38:17 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/04/30 12:24:16 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_LIST_ITERATOR_HPP
# define BIDIRECTIONAL_LIST_ITERATOR_HPP

# include <iterator>
# include "Node.hpp"

namespace ft
{
	template <class T> BidirectionalListIterator
		: public iterator<std::bidirectional_iterator_tag, Node<T>>
	{
		private:
			pointer		_ptr;
	
		public:
			explicit BidirectionalIterator(pointer defptr = nullptr) : _ptr(defptr)
			{
			}
			BidirectionalIterator(const BidirectionalIterator &other)
			{
				_ptr = other.ptr;
			}
			virtual ~BidirectionalIterator(void)
			{
			}
			BidirectionalIterator	&operator=(const pointer newNode)
			{
				_ptr = newNode;
				return (*this);
			}
			BidirectionalIterator	&operator=(const BidirectionalIterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				_ptr = rhs.ptr;
				return (*this);
			}
			reference	operator*(void) const
			{
				return (_ptr->getData());
			}
			pointer		operator->(void) const
			{
				return (&_ptr->getData());
			}
			BidirectionalIterator	&operator++(void)
			{
				_ptr = _ptr->next();
				return (*this);
			}
			BidirectionalIterator	operator++(int)
			{
				BidirectionalIterator temp = *this;
				_ptr = _ptr->next();
				return (temp);
			}
			BidirectionalIterator	&operator--(void)
			{
				_ptr = _ptr->prev();
				return (*this);
			}
			BidirectionalIterator	operator--(int)
			{
				BidirectionalIterator temp = *this;
				_ptr = _ptr->prev();
				return (temp);
			}
			pointer		getPointer(void) const
			{
				return (_ptr);
			}
	};
	template <class T>
		bool operator== (const BidirectionalIterator<T> &lhs,
			const BidirectionalIterator<T> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class T>
		bool operator!= (const BidirectionalIterator<T> &lhs,
			const BidirectionalIterator<T> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
}
#endif
