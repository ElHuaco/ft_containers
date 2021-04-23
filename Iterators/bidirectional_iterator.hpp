/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 11:57:38 by alejandro         #+#    #+#             */
/*   Updated: 2021/04/23 12:22:11 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

# include <iterator>

template <class T> BidirectionalIterator
	: public iterator<std::bidirectional_iterator_tag,T>
{
	public:
		BidirectionalIterator(void)
		{
		}
		BidirectionalIterator(const BidirectionalIterator &other)
		{
		}
		~BidirectionalIterator(void)
		{
		}
		BidirectionalIterator	&operator=(const BidirectionalIterator &rhs)
		{
		}
		reference	operator*(void) const
		{
		}
		pointer		operator->(void) const
		{
		}
		BidirectionalIterator	&operator++(void)
		{
		}
		BidirectionalIterator	operator++(int)
		{
		}
		BidirectionalIterator	&operator--(void)
		{
		}
		BidirectionalIterator	operator--(int)
		{
		}
};
template <class T>
	bool operator== (const BidirectionalIterator<T> &lhs,
		const BidirectionalIterator<T> &rhs)
	{
	}
template <class T>
	bool operator!= (const BidirectionalIterator<T> &lhs,
		const BidirectionalIterator<T> &rhs)
	{
	}
#endif
