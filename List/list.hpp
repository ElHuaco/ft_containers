/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:05:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/07 13:22:30 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_HPP
# define LIST_HPP

# include <limits>
# include "Node.hpp"
# include "BidirectionalListIterator.hpp"

# include <iostream>

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
			typedef std::reverse_iterator<iterator>					reverse_iterator;
			typedef std::reverse_iterator<const_iterator>			const_reverse_iterator;
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
			void quick_sort(iterator first, iterator inc_last)
			{
				if (inc_last.getPointer() != nullptr
					&& first.getPointer() != inc_last.getPointer()
					&& first.getPointer() != inc_last.getPointer()->next())
				{	
					iterator pit = first;
					for (iterator it = first; it != inc_last; it++)
					{
						if (*it <= *inc_last)
						{
							it.getPointer()->swap(pit.getPointer());
							pit++;
						}
					}
					inc_last.getPointer()->swap(pit.getPointer());
					iterator tmp = pit;
					quick_sort(first, --tmp);
					tmp = pit;
					quick_sort(++tmp, inc_last);
				}
			}
			template <class Compare>
			void quick_sort(iterator first, iterator inc_last, Compare comp)
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
					quick_sort(first, --tmp);
					tmp = pit;
					quick_sort(++tmp, inc_last);
				}
			}


		public:

//			node_ptr		getEnd() const
//			{
//				return (this->_end);
//			}
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit list (const allocator_type &alloc = allocator_type()) :
				_size(0), _head(nullptr), _end(nullptr)
			{
			}
			explicit list (size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) : _size(0),
				_head(nullptr), _end(nullptr)
			{
				size_type i = 0;
				while (i++ < n)
					this->push_back(val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type()) : _size(0),
				_head(nullptr), _end(nullptr)
			{
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}
			list (const list &other) : _size(0)
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
				iterator end;
				if (this->_end == nullptr)
					end = nullptr;
				else
					end = this->_end->next();
				return (end);
			}
			const_iterator	end(void) const
			{
				const_iterator end;
				if (this->_end == nullptr)
					end = nullptr;
				else
					end = this->_end->next();
				return (end);
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(this->_end));
			}
			const_reverse_iterator	rbegin(void) const
			{
				return (const_cast<const_reverse_iterator>(reverse_iterator(this->_end)));
			}
			reverse_iterator		rend(void)
			{
				reverse_iterator rend;
			if (this->_head == nullptr)
					rend = nullptr;
				else
					rend = this->_head->prev();
				return (rend);
			}
			const_reverse_iterator	rend(void) const
			{
				const_reverse_iterator rend;
				if (this->_head == nullptr)
					rend = nullptr;
				else
					rend = const_cast<const_reverse_iterator>(reverse_iterator(this->_head));
				return (rend);
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
			void assign (InputIterator first, InputIterator last)
			{
				iterator it(const_cast<node *>(first.getPointer()));
				iterator it2(const_cast<node *>(last.getPointer()));
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
					if (position.getPointer() == nullptr)
						return (position);
					position.getPointer->insertBefore(new node(val));
					if (position.getPointer() == this->_head)
						this->_head = position.getPointer()->prev();
					this->_size++;
					return (position--);
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
			void insert (iterator position, InputIterator first, InputIterator last)
			{
				while (first != last)
				{
					position = insert(position, *first);
					first++;
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
				if (other.empty() || position.getPointer() == nullptr)
					return ;
				iterator it = other.begin();
				iterator temp;
				while (it != other.end())
				{
					temp = it.getPointer()->next();
					position.getPointer()->insertAfter(it.getPointer());
					if (position.getPointer() == this->_end)
						this->_end = it.getPointer();
					this->_size++;
					position++;
					it = temp;
				}
				other._size = 0;
				other._head = nullptr;
				other._end = nullptr;
			}
			void		splice(iterator position, list &other, iterator i)
			{
				if (position == i || position.getPointer() == nullptr
					|| i.getPointer() == nullptr)
					return ;
				if (i.getPointer()->prev() != nullptr)
					i.getPointer()->prev()->next() = i.getPointer()->next();
				else
					other._head = i.getPointer()->next();
				if (i.getPointer()->next() != nullptr)
					i.getPointer()->next()->prev() = i.getPointer()->prev();
				else
					other._end = i.getPointer()->prev();
				position.getPointer()->insertAfter(i.getPointer());
				if (position.getPointer() == this->_end)
					this->_end = i.getPointer();
				this->_size++;
				other->_size--;
			}
			void		splice(iterator position, list &other, iterator first,
				iterator last)
			{
				if (position.getPointer() == nullptr || first.getPointer() == nullptr)
					return ;
				if (first.getPointer()->prev != nullptr)
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
					position.getPointer()->insertAfter(first.getPointer());
					if (position.getPointer() == this->_end)
						this->_end = first.getPointer();
					this->_size++;
					other._size--;
					position++;
					first = temp;
				}
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
				while (it != this->end())
				{
					if (*it == *(it.getPointer()->next()))
						this->erase(it.getPointer->next());
					else
						it++;
				}
			}
			template <class BinaryPredicate>
			void unique (BinaryPredicate binary_pred)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (binary_pred(*(it.getPointer()->next()), *it))
						this->erase(it.getPointer->next());
					else
						it++;
				}
			}
			void		merge(list &other)
			{
				if (&other == this)
					return ;
				if (other.empty())
					return ;
				if (this->empty())
				{
					this->_head = other._head;
					this->_end = other._end;
					this->_size = other._size;
					other._size = 0;
					other._head = nullptr;
					other._end = nullptr;
					return ;
				}
				iterator it = this->begin();
				iterator it2 = other.begin();
				iterator tmp;
				while (it2 != other.end())
				{
					tmp = it2.getPointer()->next();
					if (*it > *it2)
					{
						it.getPointer()->insertBefore(it2.getPointer());
						if (it.getPointer() == this->_head)
							this->_head = it2.getPointer();
					}
					else
					{
						it.getPointer()->insertAfter(it2.getPointer());
						if (it.getPointer() == this->_end)
							this->_end = it2.getPointer();
						it++;
					}
					std::cout << "added one" << std::endl;
					this->_size++;
					it2 = tmp;
					std::cout << "\tnow it2: " << it2.getPointer() << std::endl;
					std::cout << "\tother._end: " << other._end << std::endl;
					std::cout << "\tother.end(): " << other.end().getPointer() << std::endl;
					std::cout << "ended loop iteration" << std::endl;
				}
				std::cout << "ended loop" << std::endl;
				other._size = 0;
				other._head = nullptr;
				other._end = nullptr;
				return ;
			}
			template <class Compare>
			void merge (list &other, Compare comp)
			{
				if (&other == this)
					return ;
				if (other.empty())
					return ;
				if (this->empty())
				{
					this->_head = other._head;
					this->_end = other._end;
					this->_size = other._size;
					other._size = 0;
					other._head = nullptr;
					other._end = nullptr;
					return ;
				}
				iterator it = this->begin();
				iterator it2 = other.begin();
				iterator tmp;
				while (it2 != other.end())
				{
					tmp = it2.getPointer()->next();
					if (comp(*it, *it2) == false)
					{
						it.getPointer()->insertBefore(it2.getPointer());
						if (it.getPointer() == this->_head)
							this->_head = it2.getPointer();
					}
					else
					{
						it.getPointer()->insertAfter(it2.getPointer());
						if (it.getPointer() == this->_end)
							this->_end = it2.getPointer();
						it++;
					}
					this->_size++;
					it2 = tmp;
				}
				other._head = nullptr;
				other._end = nullptr;
				other._size = 0;
				return ;
			}
			void		sort(void)
			{
				quick_sort(this->begin(), iterator(this->_end));
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
	bool operator== (const list<T> &lhs, const list<T> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
		{
			typename ft::list<T>::iterator it = lhs.begin();
			typename ft::list<T>::iterator it2 = rhs.begin();
			while (it != lhs.end())
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
	bool operator!= (const list<T> &lhs, const list<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T>
	bool operator< (const list<T> &lhs, const list<T> &rhs)
	{
		typename ft::list<T>::iterator it = lhs.begin();
		typename ft::list<T>::iterator it2 = rhs.begin();
		while (it != lhs.end())
		{
			if (it.getPointer() == nullptr && it2.getPointer() != nullptr)
				return (true);
			else if (it2.getPointer() == nullptr)
				return (false);
			if (*it < *it2)
				return (true);
			it++;
			it2++;
		}
		return (false);
	}
	template <class T>
	bool operator<= (const list<T> &lhs, const list<T> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T>
	bool operator> (const list<T> &lhs, const list<T> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T>
	bool operator>= (const list<T> &lhs, const list<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class T>
	void swap (list<T> &x, list<T> &y)
	{
		x.swap(y);
	}
}
#endif
