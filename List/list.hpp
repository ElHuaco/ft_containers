/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:05:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/04/30 13:30:41 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include "Node.hpp"
# include "BidirectionalListIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T>> class list
	{
		public:
			typedef T											value_type;
			typedef Alloc										allocator_type;
			typedef allocator_type::reference					reference;
			typedef allocator_type::const_reference				const_reference;
			typedef allocator_type::pointer						pointer;
			typedef allocator_type::const_pointer				const_pointer;
			typedef BidirectionalListIterator<value_type>		iterator;
			typedef BidirectionalListIterator<const value_type>	const_iterator;
			typedef ReverseIterator<iterator>					reverse_iterator;
			typedef ReveserseIterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;

		protected:
			typedef Node<value_type>							node;

		private:
			node		*_head;
			node		*_end;
			size_type	_size;

		public:
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit list (const allocator_type &alloc = allocator_type()) :
				_size(0), _head(nullptr), _end(nullptr)
			{
			}
			explicit list (size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) : _size(n),
				_head(nullptr), _end(nullptr)
			{
				size_type i = 0;
				while (i++ < n)
					this->push_back(val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type()) :
				_head(nullptr), _end(nullptr)
			{
				size_type size = 0;
				while (first != last)
				{
					this->push_back(*first++);
					size++;
				}
				this->_size = size;
			}
			list (const list &other)
			{
				*this = other;
			}
			~list (void)
			{
				this->erase(this->begin(), this->end());
			}
			list	&operator=(const list &rhs)
			{
				ft::swap(*this, rhs);
				return (*this);
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
				//updatea head, end
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
				//delete nodes
			}
			iterator	erase(iterator first, iterator last)
			{
				while (first != last)
					this->erase(first++);
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
	template <class T>
	bool operator== (const list<T> &lhs, const list<T> &rhs)
	{
	}
	template <class T>
	bool operator!= (const list<T> &lhs, const list<T> &rhs)
	{
	}
	template <class T>
	bool operator< (const list<T> &lhs, const list<T> &rhs)
	{
	}
	template <class T>
	bool operator<= (const list<T> &lhs, const list<T> &rhs)
	{
	}
	template <class T>
	bool operator> (const list<T> &lhs, const list<T> &rhs)
	{
	}
	template <class T>
	bool operator>= (const list<T> &lhs, const list<T> &rhs)
	{
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class T>
	void swap (list<T> &x, list<T> &y)
	{
	}
}
#endif
