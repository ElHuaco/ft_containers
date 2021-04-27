/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:57:38 by alejandro         #+#    #+#             */
/*   Updated: 2021/04/27 12:20:01 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iterator>

template <class T> BidirectionalIterator
	: public iterator<std::bidirectional_iterator_tag,T>
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
		~BidirectionalIterator(void)
		{
		}
		BidirectionalIterator	&operator=(const pointer data)
		{
			_ptr = data;
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
			return (*_ptr);
		}
		pointer		operator->(void) const
		{
			return (_ptr);
		}
		BidirectionalIterator	&operator++(void)
		{
			_ptr++;
			return (*this);
		}
		BidirectionalIterator	operator++(int)
		{
			BidirectionalIterator temp = *this;
			_ptr++;
			return (temp);
		}
		BidirectionalIterator	&operator--(void)
		{
			_ptr--;
			return (*this);
		}
		BidirectionalIterator	operator--(int)
		{
			BidirectionalIterator temp = *this;
			_ptr--;
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
#endif
