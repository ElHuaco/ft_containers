/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 10:38:27 by alejandro         #+#    #+#             */
/*   Updated: 2021/04/23 11:55:26 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <memory>
# include "Iterators/bidirectional_iterator.hpp"
# include "Iterators/reverse_iterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T>> class list
	{
		private:
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef allocator_type::reference			reference;
			typedef allocator_type::const_reference		const_reference;
			typedef allocator_type::pointer				pointer;
			typedef allocator_type::const_pointer		const_pointer;
			typedef BidirectionalIterator<value_type,
				pointer, reference>						iterator;
			typedef BidirectionalIterator<value_type,
				const_pointer, const_reference>			const_iterator;
			typedef ReverseIterator<iterator>			reverse_iterator;
			typedef ReveserseIterator<const_iterator>	const_reverse_iterator;
			typedef std::iterator_traits<iterator>
				::difference_type						difference_type;
			typedef size_t								size_type;

		public:
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit list (const allocator_type &alloc = allocator_type())
			{
			}
			explicit list (size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type())
			{
			}
			template <class InputIterator>
				list (InputIterator first, InputIterator last,
					const allocator_type &alloc = allocator_type())
			{
			}
			list (const list &other)
			{
			}
			~list (void)
			{
			}
			list	&operator=(const list &rhs)
			{
			}
			/****************************/
			/* ITERATOR MEMBER FUNCTIONS*/
			/****************************/
			iterator		begin(void)
			{
			}
			const_iterator	begin(void)
			{
			}
			iterator		end(void)
			{
			}
			const_iterator	end(void)
			{
			}
			reverse_iterator		rbegin(void)
			{
			}
			const_reverse_iterator	rbegin(void)
			{
			}
			reverse_iterator		rend(void)
			{
			}
			const_reverse_iterator	rend(void)
			{
			}
			/****************************/
			/* CAPACITY MEMBER FUNCTIONS*/
			/****************************/
			bool		empty(void) const
			{
			}
			size_type	size(void) const
			{
			}
			size_type	max_size(void) const
			{
			}
			/****************************/
			/* ELEMENT ACCESS FUNCTIONS*/
			/****************************/
			reference		front(void)
			{
			}
			const_reference front(void)
			{
			}
			reference		back(void)
			{
			}
			const_reference back(void)
			{
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
			}
			void		assign(size_type n, const_value_type &val)
			{
			}
			void		push_front(const value_type &val)
			{
			}
			void		pop_front(void)
			{
			}
			void		push_back(const value_type &val)
			{
			}
			void		pop_back(void)
			{
			}
			iterator	insert(iterator position, const value_type &val)
			{
			}
			void		insert(iterator position, size_type n,
				const value_type &val)
			{
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
			{
			}
			iterator	erase(iterator position)
			{
			}
			iterator	erase(iterator first, iterator last)
			{
			}
			void		swap(list &rhs)
			{
			}
			void		resize(size_type n, value_type val = value_type())
			{
			}
			void		clear(void)
			{
			}
			/****************************/
			/* OPERATION MEMBER FUNCTION*/
			/****************************/
			void		splice(iterator position, list &other)
			{
			}
			void		splice(iterator position, list &other, iterator i)
			{
			}
			void		splice(iterator position, list &other, iterator first,
				iterator last)
			{
			}
			void		remove(const value_type &val)
			{
			}
			template <class Predicate>
			void remove_if (Predicate pred)
			{
			}
			void		unique(void)
			{
			}
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
			}
			void		merge(list &other)
			{
			}
			template <class Compare>
			void merge (list &other, Compare comp)
			{
			}
			void		sort(void)
			{
			}
			template <class Compare>
			void sort (Compare comp)
			{
			}
			void		reverse(void)
			{
			}
	};
	/****************************/
	/*  RELATIONAL OPERATORS    */
	/****************************/
	template <class T, class Alloc>
	bool operator== (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	template <class T, class Alloc>
	bool operator!= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	template <class T, class Alloc>
	bool operator< (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	template <class T, class Alloc>
	bool operator<= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	template <class T, class Alloc>
	bool operator> (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	template <class T, class Alloc>
	bool operator>= (const list<T,Alloc> &lhs, const list<T,Alloc> &rhs)
	{
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class T, class Alloc>
	void swap (list<T,Alloc> &x, list<T,Alloc> &y)
	{
	}
};
#endif
