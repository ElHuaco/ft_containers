/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 10:16:09 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/11 12:52:26 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

#include "../shared_tools/predicates.hpp"
#include "../shared_tools/disable_if.hpp"
#include "RandomIterator.hpp"
#include <stdexcept>
#include <limits>

namespace ft
{
	template <class T, class Alloc = std::allocator<T> > class vector
	{
		public:
			/****************************/
			/*       MEMBER TYPES       */
			/****************************/
			typedef T									value_type;
			typedef Alloc								allocator_type;
			typedef value_type							*pointer;
			typedef value_type const					*const_pointer;
			typedef value_type							&reference;
			typedef value_type const					&const_reference;
			typedef RandomIterator<value_type>			iterator;
			typedef RandomIterator<value_type const>	const_iterator;
			typedef ReverseVecIterator<iterator>		reverse_iterator;
			typedef ReverseVecIterator<const_iterator>	const_reverse_iterator;
			typedef ptrdiff_t							difference_type;
			typedef size_t								size_type;

		private:
			/****************************/
			/*        ATTRIBUTES        */
			/****************************/
			value_type		*_c;
			size_type		_size;
			size_type		_capacity;

		public:
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit vector(const allocator_type &alloc = allocator_type()) :
				_c(nullptr), _size(0), _capacity(0)
			{
			}
			explicit vector(size_type n, const value_type &val = value_type(),
				const allocator_type &alloc = allocator_type()) :
				_c(nullptr), _size(0), _capacity(0)
			{
				this->assign(n, val);
			}
			template <class InputIterator>
			vector (InputIterator first, InputIterator last,
				const allocator_type &alloc = allocator_type(),
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type *dummy = 0) :
				_c(nullptr), _size(0), _capacity(0)
			{
				this->assign(first, last);
			}
			vector(const vector &other)
			{
				*this = other;
			}
			~vector(void)
			{
				this->clear();
			}
			vector &operator=(const vector &rhs)
			{
				this->assign(rhs.begin(), rhs.end());
				return (*this);
			}
			/****************************/
			/* ITERATOR MEMBER FUNCTIONS*/
			/****************************/
			iterator			begin(void)
			{
				return (iterator(this->_c));
			}
			const_iterator		begin(void) const
			{
				return (const_iterator(this->_c));
			}
			iterator			end(void)
			{
				if (this->_c == nullptr)
					return (iterator(nullptr));
				else
					return (iterator(this->_c + _size));
			}
			const_iterator		end(void) const
			{
				if (this->_c == nullptr)
					return (const_iterator(nullptr));
				else
					return (const_iterator(this->_c + _size));
			}
			reverse_iterator		rbegin(void)
			{
				return (reverse_iterator(this->end()));
			}
			const_reverse_iterator	rbegin(void) const
			{
				return (const_reverse_iterator(this->end()));
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator(this->begin()));
			}
			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(this->begin()));
			}
			/****************************/
			/* CAPACITY MEMBER FUNCTIONS*/
			/****************************/
			size_type		size(void) const
			{
				return (this->_size);
			}
			size_type		max_size(void) const
			{
				return (std::numeric_limits<size_type>::max() / sizeof(value_type));
			}
			void			resize(size_type n, value_type val = value_type())
			{
				if (n < _size)
					this->erase(iterator(this->_c + n), this->end());
				else
					this->insert(iterator(this->_c + _size), n - _size, val);
			}
			size_type		capacity(void) const
			{
				return (this->_capacity);
			}
			bool			empty(void) const
			{
				return (this->_size == 0);
			}
			void			reserve(size_type n)
			{
				if (_capacity >= n)
					return ;
				vector tmp = *this;
				this->clear();
				this->_capacity = n;
				this->_size = tmp._size;
				this->_c = new value_type[n];
				for(size_type i = 0; i < _size; ++i)
					this->_c[i] = tmp._c[i];
			}
			/****************************/
			/* ELEMENT ACCESS FUNCTIONS */
			/****************************/
			reference			operator[](size_type n)
			{
				return (this->_c[n]);
			}
			const_reference		operator[](size_type n) const
			{
				return (this->_c[n]);
			}
			reference			at(size_type n)
			{
				if (n >= _size)
					throw (std::out_of_range("Out of range"));
				else
					return (this->_c[n]);
			}
			const_reference		at(size_type n)
			{
				if (n >= _size)
					throw (std::out_of_range("Out of range"));
				else
					return (this->_c[n]);
			}
			reference			front(void)
			{
				return (*this->_c);
			}
			const_reference		front(void) const
			{
				return (*this->_c);
			}
			reference			back(void)
			{
				return (this->_c[_size - 1]);
			}
			const_reference		back(void) const
			{
				return (this->_c[_size - 1]);
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			template <class InputIterator>
			void assign (InputIterator first, InputIterator last,
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type *dummy = 0)
			{
				this->clear();
				this->insert(this->begin(), first, last);
			}
			void assign(size_type n, const value_type &val = value_type())
			{
				this->clear();
				this->insert(this->begin(), n, val);
			}
			void push_back(const value_type &val)
			{
				this->insert(iterator(this->end()), val);
			}
			void pop_back(const value_type &val)
			{
				this->insert(iterator(this->begin()), val);
			}
			//insert comprueba si puede simplemente asignar por capacidad
			//insert en end() pero no vacío?
			iterator insert(iterator position, const_value &val)
			{
			}
			void insert(iterator position, size_type n, const value_type &val)
			{
			}
			template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last,
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type *dummy = 0)
			{
				InputIterator it(const_cast<pointer>(first.getPointer()));
				InputIterator it2(const_cast<pointer>(last.getPointer()));
			}
			//erase no cambia capacidad?
			iterator erase(iterator position)
			{
			}
			iterator erase(iterator first, iterator last)
			{
			}
			void swap(vector &other)
			{
			}
			void clear()
			{
				this->erase(this->begin(), this->end());
			}
	};
	/****************************/
	/*  RELATIONAL OPERATORS    */
	/****************************/
	template <class T, class Alloc>
	bool operator== (const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		typename ft::vector<T, Alloc>::iterator it(
			const_cast<T *>(lhs.begin().getPointer()));
		typename ft::vector<T, Alloc>::iterator itend(
			const_cast<T *>(lhs.end().getPointer()));
		typename ft::vector<T, Alloc>::iterator it2(
			const_cast<T *>(rhs.begin().getPointer()));
		while (it.getPointer() != itend)
		{
			if (*it != *it2)
				return (false);
			it++;
			it2++;
		}
		return (true);
	}
	template <class T>
	bool operator!= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class T>
	bool operator< (const vector<T> &lhs, const vector<T> &rhs)
	{
		typename ft::vector<T, Alloc>::iterator it(
			const_cast<T *>(lhs.begin().getPointer()));
		typename ft::vector<T, Alloc>::iterator itend(
			const_cast<T *>(lhs.end().getPointer()));
		typename ft::vector<T, Alloc>::iterator it2(
			const_cast<T *>(rhs.begin().getPointer()));
		while (it != itend)
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
	bool operator<= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class T>
	bool operator> (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (rhs < lhs);
	}
	template <class T>
	bool operator>= (const vector<T> &lhs, const vector<T> &rhs)
	{
		return (!(lhs < rhs));
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class T, class Alloc>
	void swap (vector<T, Alloc> &x, vector<T, Alloc> &y)
	{
		x.swap(y);
	}
};
#endif
