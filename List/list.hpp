/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:05:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/25 08:41:49 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include "../shared_tools/disable_if.hpp"
# include "../shared_tools/predicates.hpp"
# include "Node.hpp"
# include "BidirectionalListIterator.hpp"

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > class list
	{
		public:
			/****************************/
			/*       MEMBER TYPES       */
			/****************************/
			typedef T											value_type;

		protected:
			/****************************/
			/*   INHERITABLE NODE TYPE  */
			/****************************/
			typedef Node<value_type>							node;
			typedef node *										node_ptr;

		public:
			/****************************/
			/*       MEMBER TYPES       */
			/****************************/
			typedef Alloc											allocator_type;
			typedef typename allocator_type::reference				reference;
			typedef typename allocator_type::const_reference		const_reference;
			typedef typename allocator_type::pointer				pointer;
			typedef typename allocator_type::const_pointer			const_pointer;
			typedef BidirectionalListIterator<value_type, node>		iterator;
			typedef BidirectionalListIterator<const value_type, const node> const_iterator;
			typedef ReverseListIterator<iterator>					reverse_iterator;
			typedef ReverseListIterator<const_iterator>				const_reverse_iterator;
			typedef ptrdiff_t										difference_type;
			typedef size_t											size_type;

		private:
			/****************************/
			/*        ATTRIBUTES        */
			/****************************/
			node_ptr	_head;
			node_ptr	_end;
			size_type	_size;

		private:
			/****************************/
			/*       FUNCTION UTILS     */
			/****************************/
			template <class Compare>
			void quick_sort(iterator first, iterator inc_last, Compare &comp)
			{
				if (inc_last.getPointer() != nullptr
					&& first.getPointer() != inc_last.getPointer()
					&& first.getPointer() != inc_last.getPointer()->next())
				{	
					iterator pit = first;
					for (iterator it = first; it != inc_last; it++)
					{
						if (comp(*it, *inc_last) == true)
						{
							it.getPointer()->swap(pit.getPointer());
							pit++;
						}
					}
					inc_last.getPointer()->swap(pit.getPointer());
					iterator tmp = pit;
					quick_sort(first, --tmp, comp);
					tmp = pit;
					quick_sort(++tmp, inc_last, comp);
				}
			}

		public:
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit list (const allocator_type &alloc = allocator_type()) :
				_size(0), _head(nullptr), _end(nullptr)
			{
			}
			explicit list (size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) :
				_size(0), _head(nullptr), _end(nullptr)
			{
				size_type i = 0;
				while (i++ < n)
					this->push_back(val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type(),
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type* dummy = 0) :
				_size(0), _head(nullptr), _end(nullptr)
			{
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}
			list (const list &other) : _size(0), _head(nullptr), _end(nullptr)
			{
				*this = other;
			}
			~list (void)
			{
				this->clear();
			}
			list	&operator=(const list &rhs)
			{
				this->assign(rhs.begin(), rhs.end());
				return (*this);
			}
			/****************************/
			/* ITERATOR MEMBER FUNCTIONS*/
			/****************************/
			iterator		begin(void)
			{
				return (iterator(this->_head));
			}
			const_iterator	begin(void) const
			{
				return (const_iterator(this->_head));
			}
			iterator		end(void)
			{
				iterator it_end;
				if (this->_end == nullptr)
					it_end = nullptr;
				else
					it_end = this->_end->next();
				return (it_end);
			}
			const_iterator	end(void) const
			{
				const_iterator it_end;
				if (this->_end == nullptr)
					it_end = nullptr;
				else
					it_end = this->_end->next();
				return (it_end);
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(iterator(this->_end)));
			}
			const_reverse_iterator	rbegin(void) const
			{
				return (const_cast<const_reverse_iterator>(reverse_iterator(
					iterator(this->_end))));
			}
			reverse_iterator		rend(void)
			{
				reverse_iterator rev_end;
			if (this->_head == nullptr)
					rev_end.base() = iterator();
				else
					rev_end.base() = iterator(this->_head->prev());
				return (rev_end);
			}
			const_reverse_iterator	rend(void) const
			{
				const_reverse_iterator rev_end;
				if (this->_head == nullptr)
					rev_end.base() = iterator();
				else
					rev_end.base() = iterator(this->_head->prev());
				return (rev_end);
			}
			/****************************/
			/* CAPACITY MEMBER FUNCTIONS*/
			/****************************/
			bool		empty(void) const
			{
				return (this->_size == 0);
			}
			size_type	size(void) const
			{
				return (this->_size);
			}
			size_type	max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(node)); 
			}
			/****************************/
			/* ELEMENT ACCESS FUNCTIONS */
			/****************************/
			reference		front(void)
			{
				return (this->_head->getData());
			}
			const_reference front(void) const
			{
				return (const_cast<const_reference>(this->_head->getData()));
			}
			reference		back(void)
			{
				return (this->_end->getData());
			}
			const_reference back(void) const
			{
				return (const_cast<const_reference>(this->_end->getData()));
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type* dummy = 0)
			{
				InputIterator it(const_cast<node *>(first.getPointer()));
				InputIterator it2(const_cast<node *>(last.getPointer()));
				this->clear();
				while (it != it2)
				{
					this->push_back(*it);
					it++;
				}
			}
			void		assign(size_type n, const value_type &val)
			{
				this->clear();
				this->resize(n, val);
			}
			void		push_front(const value_type &val)
			{
				if (this->empty())
				{
					this->_head = new node(val);
					this->_end = this->_head;
				}
				else
				{
					node *temp = new node(val);
					this->_head->prev() = temp;
					temp->next() = this->_head;
					this->_head = temp;
				}
				this->_size++;
			}
			void		pop_front(void)
			{
				if (this->empty())
					return ;
				if (this->_head->next())
					this->_head->next()->prev() = nullptr;
				this->erase(this->begin());
			}
			void		push_back(const value_type &val)
			{
				if (this->empty())
				{
					this->_head = new node(val);
					this->_end = this->_head;
				}
				else
				{
					node *temp = new node(val);
					this->_end->next() = temp;
					temp->prev() = this->_end;
					this->_end = temp;
				}
				this->_size++;
			}
			void		pop_back(void)
			{
				if (this->empty())
					return ;
				if (this->_end->prev())
					this->_end->prev()->next() = nullptr;
				this->erase(iterator(this->_end));
			}
			iterator	insert(iterator position, const value_type &val)
			{
				if (!this->empty())
				{
					this->_size++;
					if (position.getPointer() == this->_end->next())
					{
						this->_end->insertAfter(new node(val));
						this->_end = this->_end->next();
						return (iterator(this->_end->prev()));
					}
					position.getPointer()->insertBefore(new node(val));
					if (position.getPointer() == this->_head)
						this->_head = position.getPointer()->prev();
					return (--position);
				}
				else
				{
					this->_head = new node(val);
					this->_end = this->_head;
					this->_size++;
					return (this->begin());
				}
			}
			void		insert(iterator position, size_type n,
				const value_type &val)
			{
				size_type i = 0;
				while (i++ < n)
					insert(position, val);
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type* dummy = 0)
			{
				InputIterator it(const_cast<node *>(first.getPointer()));
				InputIterator it2(const_cast<node *>(last.getPointer()));
				while (it != it2)
				{
					position = insert(position, *it);
					it++;
					if (this->_size != 1)
						position++;
				}
			}
			iterator	erase(iterator position)
			{
				if (position.getPointer() == nullptr)
					return (position);
				if (position.getPointer()->prev() != nullptr)
					position.getPointer()->prev()->next() =
						position.getPointer()->next();
				else
					this->_head = position.getPointer()->next();
				if (position.getPointer()->next() != nullptr)
					position.getPointer()->next()->prev() = 
						position.getPointer()->prev();
				else
					this->_end = position.getPointer()->prev();
				iterator ret(position.getPointer()->next());
				delete position.getPointer();
				this->_size--;
				return (ret);
			}
			iterator	erase(iterator first, iterator last)
			{
				iterator ret;
				while (first != last)
					ret = this->erase(first++);
				return (ret);
			}
			void		swap(list &rhs)
			{
				node_ptr tmp_n = this->_head;
				this->_head = rhs._head;
				rhs._head = tmp_n;
				tmp_n = this->_end;
				this->_end = rhs._end;
				rhs._end = tmp_n;
				size_type tmp_s = this->_size;
				this->_size = rhs._size;
				rhs._size = tmp_s;
				return ;
			}
			void		resize(size_type n, value_type val = value_type())
			{
				if (n > this->_size)
				{
					while (this->_size != n)
						this->push_back(val);
				}
				else if (n < this->_size)
				{
					while (this->_size != n)
						this->pop_back();
				}
			}
			void		clear(void)
			{
				if (this->empty() == false)
					this->erase(this->begin(), this->end());
			}
			/****************************/
			/* OPERATION MEMBER FUNCTION*/
			/****************************/
			void		splice(iterator position, list &other)
			{
				this->splice(position, other, other.begin(), other.end());
			}
			void		splice(iterator position, list &other, iterator i)
			{
				iterator last = i;
				this->splice(position, other, i, ++last);
			}
			void		splice(iterator position, list &other, iterator first,
				iterator last)
			{
				if (other.empty())
					return ;
				if (this->empty())
				{
					this->swap(other);
					return ;
				}
				if (first.getPointer()->prev() != nullptr)
					first.getPointer()->prev()->next() = last.getPointer();
				else
					other._head = last.getPointer();
				if (last.getPointer() != nullptr)
					last.getPointer()->prev() = first.getPointer()->prev();
				else
					other._end = first.getPointer()->prev();
				iterator temp;
				while (first != last)
				{
					temp = first.getPointer()->next();
					position.getPointer()->insertBefore(first.getPointer());
					if (position.getPointer() == this->_head)
						this->_head = first.getPointer();
					this->_size++;
					other._size--;
					first = temp;
				}
				return ;
			}
			void		remove(const value_type &val)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (*it == val)
						it = this->erase(it);
					else
						it++;
				}
			}
			template <class Predicate>
			void remove_if (Predicate pred)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (pred(*it))
						it = this->erase(it);
					else
						it++;
				}
			}
			void		unique(void)
			{
				iterator it = this->begin();
				iterator last(this->_end);
				while (it != last)
					if (*it == *(++it))
						this->erase(it--);
			}
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator it = this->begin();
				iterator last(this->_end);
				while (it != last)
					if (binary_pred(*(++it), *(--it)))
						this->erase(++it);
					else
						++it;
			}
			void		merge(list &other)
			{
				merge(other, ft::is_less<value_type>);
			}
			template <class Compare>
			void merge (list &other, Compare comp)
			{
				if (&other == this)
					return ;
				iterator it = this->begin();
				iterator itend = this->end();
				iterator it2 = other.begin();
				iterator it2end = other.end();
				while (it != itend && it2 != it2end)
				{
					if (comp(*it2, *it) == true && it != it2)
					{
						this->splice(it, other, it2);
						it = this->begin();
						it2 = other.begin();
					}
					else
						it++;
				}
				this->splice(iterator(this->_end), other);
				return ;
			}
			void		sort(void)
			{
				quick_sort(this->begin(), iterator(this->_end),
					ft::is_less<value_type>);
			}
			template <class Compare>
			void sort (Compare comp)
			{
				quick_sort(this->begin(), iterator(this->_end), comp);
			}
			void		reverse(void)
			{
				list temp;
				temp.assign(this->rbegin(), this->rend());
				this->clear();
				this->swap(temp);
			}
	};
	/****************************/
	/*  RELATIONAL OPERATORS    */
	/****************************/
	template <class T>
	bool operator== (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
		{
			typename ft::list<T>::iterator it(
				const_cast<Node<T> *>(lhs.begin().getPointer()));
			typename ft::list<T>::iterator it2(
				const_cast<Node<T> *>(rhs.begin().getPointer()));
			while (it.getPointer() != nullptr)
			{
				if (*it != *it2)
					return (false);
				it++;
				it2++;
			}
		}
		return (true);
	}
	template <class T>
	bool operator!= (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T>
	bool operator< (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		typename ft::list<T>::iterator it(
			const_cast<Node<T> *>(lhs.begin().getPointer()));
		typename ft::list<T>::iterator it2(
			const_cast<Node<T> *>(rhs.begin().getPointer()));
		while (it.getPointer() != nullptr)
		{
			if (it.getPointer() == nullptr && it2.getPointer() != nullptr)
				return (true);
			else if (it2.getPointer() == nullptr)
				return (false);
			if (*it < *it2)
				return (true);
			else if (*it > *it2)
				return (false);
			it++;
			it2++;
		}
		return (false);
	}
	template <class T>
	bool operator<= (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T>
	bool operator> (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T>
	bool operator>= (const ft::list<T> &lhs, const ft::list<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class T>
	void swap (ft::list<T> &x, ft::list<T> &y)
	{
		x.swap(y);
	}
}
#endif
