/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 11:05:47 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/04 11:05:17 by alejandro        ###   ########.fr       */
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
				const allocator_type &alloc = allocator_type()) : _size(0),
				_head(nullptr), _end(nullptr)
			{
				size_type i = 0;
				while (i++ < n)
					this->push_back(val);
			}
			template <class InputIterator>
			list (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type()) : _size(0)
				_head(nullptr), _end(nullptr)
			{
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}
			list (const list &other)
			{
				*this = other;
			}
			~list (void)
			{
				this->clear();
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
				iterator head = this->_head;
				return (head);
			}
			const_iterator	begin(void)
			{
				const_iterator head = const_cast<const node *>(this->_head);
				return (head);
			}
			iterator		end(void)
			{
				iterator end = this->_end->next();
				return (end);
			}
			const_iterator	end(void)
			{
				const_iterator end = const_cast<const node *>(this->_end->next());
				return (end);
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(this->_end));
			}
			const_reverse_iterator	rbegin(void)
			{
				return (const_cast<const_reverse_iterator>(reverse_iterator(this->_end)));
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator(this->_head));
			}
			const_reverse_iterator	rend(void)
			{
				return (const_cast<const_reverse_iterator>(reverse_iterator(this->_head)));
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
				return (*(this->_head->getData()));
			}
			const_reference front(void)
			{
				return (const_cast<const_reference>(*(this->_head->getData())));
			}
			reference		back(void)
			{
				return (*(this->_end->getData()));
			}
			const_reference back(void)
			{
				return (const_cast<const_reference>(*(this->_end->getData())));
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last)
			{
				this->clear();
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}
			void		assign(size_type n, const_value_type &val)
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
				this->erase(BidirectionalListIterator(this->_end));
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
				iterator ret = position.getPointer->next();
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
				list temp = *this;
				this->assign(rhs.begin(), rhs.end());
				rhs.assign(temp.begin(), temp.end());
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
				this->erase(this->begin(), this->end());
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
						this->erase(BidirectionalListIterator(it.getPointer->next()));
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
						this->erase(BidirectionalListIterator(it.getPointer->next()));
					else
						it++;
				}
			}
			void		merge(list &other)
			{
				if (&other == this)
					return ;
				//TODO
			}
			template <class Compare>
			void merge (list &other, Compare comp)
			{
			}
			void		sort(void)
			{
				//operator <
				//no hay copia, destruction o construction
				//merge sort
			}
			template <class Compare>
			void sort (Compare comp)
			{
				//comp
			}
			void		reverse(void)
			{
				list temp();
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
			iterator it = lhs.begin();
			iterator it2 = rhs.begin();
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
		iterator it = lhs.begin();
		iterator it2 = rhs.begin();
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
		list<T> temp = x;
		x.assign(y.begin(), y.end());
		y.assign(temp.begin(), temp.end());
	}
}
#endif
