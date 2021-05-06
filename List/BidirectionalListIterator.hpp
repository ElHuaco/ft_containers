/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BidirectionalListIterator.hpp                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:38:17 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/06 11:32:08 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_LIST_ITERATOR_HPP
# define BIDIRECTIONAL_LIST_ITERATOR_HPP

# include <iterator>
# include "Node.hpp"

namespace ft
{
	template <class T> class BidirectionalListIterator
		: public std::iterator<std::bidirectional_iterator_tag, ft::Node<T> >
	{
		public:
			typedef Node<T>		value_type;
			typedef Node<T>*	pointer;
			typedef Node<T>&	reference;

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
			BidirectionalListIterator	&operator=(pointer newNode)
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
			pointer		getPointer(void) const
			{
				return (_ptr);
			}
			void		setPointer(pointer newPtr)
			{
				_ptr = newPtr;
			}
	};
	template <class T>
		bool operator== (const BidirectionalListIterator<T> &lhs,
			const BidirectionalListIterator<T> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class T>
		bool operator!= (const BidirectionalListIterator<T> &lhs,
			const BidirectionalListIterator<T> &rhs)
		{
			return (lhs.getPointer() != rhs.getPointer());
		}
}
#endif
