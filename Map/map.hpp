/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:50:51 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/19 10:31:27 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../shared_tools/disable_if.hpp"
# include "../shared_tools/predicates.hpp"
# include "BidirectionalMapIterator.hpp"
# include "BST_Nodes.hpp"
# include <utility>
# include <limits>
# include <functional>

namespace ft
{
	template <class Key, class T, class Compare = ft::is_less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> > class map
	{
		public:
			/****************************/
			/*       MEMBER TYPES       */
			/****************************/
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef std::pair<const key_type, mapped_type>	value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef typename allocator_type::reference		reference
			typedef typename allocator_type::const_reference	const_reference
			typedef typename allocator_type::pointer		pointer
			typedef typename allocator_type::const_pointer	const_pointer
			typedef BSTNode<value_type>						node;
			typedef BidirectionalMapIterator<value_type>	iterator;
			typedef BidirectionalMapIterator<const value_type>	const_iterator;
			typedef ReverseMapIterator<iterator>			reverse_iterator;
			typedef ReverseMapIterator<const_iterator>		const_reverse_iterator;
			typedef ptrdiff_t								difference_type;
			typedef size_t									size_type;
			class value_compare : std::binary_function<value_type, value_type, bool>
			{
				private:
					value_compare(void) {}
				protected:
					Compare comp;
					value_compare (const Compare &c = Compare()) : comp(c) {}
				public:
					virtual ~value_compare(void) {}
					value_compare	&operator=(const value_compare &other)
					{
						this->comp = other.comp;
						return (*this);
					}
					bool operator()(const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private:
			/****************************/
			/*        ATTRIBUTES        */
			/****************************/
			node			*_root;
			size_type		_size;

		public:
			/****************************/
			/* COPLIEN MEMBER FUNCTIONS */
			/****************************/
			explicit map(const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type()) :
				_root(nullptr), _size(0)
			{
			}
			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare &comp = key_compare(),
				const allocator_type &alloc = allocator_type(),
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type* dummy = 0) :
				_root(nullptr), _size(0)
			{
				this->insert(first, last);
			}
			map(const map &other) :
				_root(nullptr), _size(0)
			{
				*this = other;
			}
			~map(void)
			{
				this->clear();
			}
			map	&operator=(const map &rhs)
			{
				if (this == &rhs)
					return (*this);
				if (this->_size != 0)
					this->clear();
				this->insert(rhs.begin(), rhs.end());
				return (*this);
			}
			/****************************/
			/* ITERATOR MEMBER FUNCTIONS*/
			/****************************/
			iterator		begin(void)
			{
				if (this->_root == nullptr)
					return (iterator(this->_root));
				node *tmp = this->_root;
				while (tmp->left() != nullptr)
					tmp = tmp->left();
				return (iterator(tmp));
			}
			const_iterator	begin(void) const
			{
				if (this->_root == nullptr)
					return (const_iterator(this->_root));
				node *tmp = this->_root;
				while (tmp->left() != nullptr)
					tmp = tmp->left();
				return (const_iterator(tmp));
			}
			iterator		end(void)
			{
				return (iterator(nullptr));
			}
			const_iterator	end(void) const
			{
				return (const_iterator(nullptr));
			}
			reverse_iterator		rbegin(void)
			{
				if (this->_root == nullptr)
					return (reverse_iterator(this->_root));
				node *tmp = this->_root;
				while (tmp->right() != nullptr)
					tmp = tmp->right();
				return (reverse_iterator(tmp));
			}
			const_reverse_iterator	rbegin(void) const
			{
				if (this->_root == nullptr)
					return (const_reverse_iterator(this->_root));
				node *tmp = this->_root;
				while (tmp->right() != nullptr)
					tmp = tmp->right();
				return (const_reverse_iterator(tmp));
			}
			reverse_iterator		rend(void)
			{
				return (reverse_iterator(nullptr));
			}
			const_reverse_iterator	rend(void) const
			{
				return (const_reverse_iterator(nullptr));
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
			mapped_type	&operator[](const key_type &k)
			{
				return (*((this->insert(
					std::make_pair(k, mapped_type()))).first).second);
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			std::pair<iterator, bool>	insert(const value_type &val)
			{
			}
			iterator					insert(iterator position,
				const value_type &val)
			{
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last,
				typename ft::disable_if
					<ft::is_integral<InputIterator> >::type* dummy = 0)
			{
			}
			void	swap(map &x)
			{
				node *tmp = this->_root;
				this->_root = x._root;
				x._root = tmp;
				size_type tmp_s = this->_size;
				this->_size = x._size;
				x._size = tmp_s;
			}
			void	clear(void)
			{
				this->erase(this->begin(), this->end());
			}
			/****************************/
			/* OBSERVER MEMBER FUNCTIONS*/
			/****************************/
			key_compare	key_comp(void) const
			{
				return (key_compare());
			}
			value_compare	value_comp(void) const
			{
				return (value_compare());
			}
			/****************************/
			/* OPERATION MEMBER FUNCTION*/
			/****************************/
			iterator		find(const key_type &k)
			{
				iterator tmp(this->_root);
				while (tmp.getPointer() != nullptr && tmp->first != k)
				{
					if (key_compare(tmp->first, k) == true)
						tmp.getPointer() = tmp.getPointer()->right();
					else
						tmp.getPointer() = tmp.getPointer()->left();
				}
				return (tmp);
			}
			const_iterator	find(const key_type &k) const
			{
				iterator tmp(this->_root);
				while (tmp.getPointer() != nullptr && tmp->first != k)
				{
					if (key_compare(tmp->first, k) == true)
						tmp.getPointer() = tmp.getPointer()->right();
					else
						tmp.getPointer() = tmp.getPointer()->left();
				}
				return (const_iterator(tmp.getPointer()));
			}
			size_type	count(const key_type &k) const
			{
				iterator tmp = this->find(k);
				return (tmp.getPointer() == nullptr ? 0 : 1);
			}
			iterator		lower_bound(const key_type &k)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (key_compate(it->first, k) == false)
						return (it);
					++it;
				}
				return (it);
			}
			const_iterator	lower_bound(const key_type &k) const
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (key_compate(it->first, k) == false)
						return (const_iterator(it.getPointer()));
					++it;
				}
				return (const_iterator(it.getPointer()));
			}
			iterator		upper_bound(const key_type &k)
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (key_compate(it->first, k) == true)
						return (it);
					++it;
				}
				return (it);
			}
			const_iterator	upper_bound(const key_type &k) const
			{
				iterator it = this->begin();
				while (it != this->end())
				{
					if (key_compate(it->first, k) == true)
						return (const_iterator(it.getPointer()));
					++it;
				}
				return (const_iterator(it.getPointer()));
			}
			std::pair<iterator, iterator>				equal_range(const key_type &k)
			{
				return (std::pair<iterator, iterator>(
					this->lower_bond(k), this->upper_bond(k)));
			}
			std::pair<const_iterator, const_iterator>	equal_range(const key_type &k)
			{
				return (std::pair<const_iterator, const_iterator>(
					this->lower_bond(k), this->upper_bond(k)));
			}
	};
}
#endif
