/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:50:51 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/25 08:41:04 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../shared_tools/predicates.hpp"
# include "BidirectionalMapIterator.hpp"
# include "BST_Nodes.hpp"
# include <utility>
# include <limits>
# include <functional>

namespace ft
{
	template <class Key, class T, class Compare = ft::is_less_ft<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> > > class map
	{
		public:
			/****************************/
			/*       MEMBER TYPES       */
			/****************************/
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef std::pair<key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Alloc										allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef BSTNode<value_type>							node;
			typedef BidirectionalMapIterator<value_type, node>	iterator;
			typedef BidirectionalMapIterator<const value_type, const node> const_iterator;
			typedef ReverseMapIterator<iterator>				reverse_iterator;
			typedef ReverseMapIterator<const_iterator>			const_reverse_iterator;
			typedef ptrdiff_t									difference_type;
			typedef size_t										size_type;
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
			node			*getRoot(void) const
			{
				return (this->_root);
			}
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
				const allocator_type &alloc = allocator_type()) : 
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
				return (this->insert(
					std::make_pair(k, mapped_type())).first->second);
			}
			/****************************/
			/* MODIFIER MEMBER FUNCTIONS*/
			/****************************/
			std::pair<iterator, bool>	insert(const value_type &val)
			{
				if (this->_size == 0)
				{
					this->_root = new node(val);
					this->_size++;
					return (std::make_pair(iterator(this->_root), true));
				}
				iterator it(this->_root);
				while (1)
				{
					if (it->first == val.first)
						return (std::make_pair(it, false));
					else if (key_compare()(it->first, val.first) == true)
					{
						if (it.getPointer()->right() == nullptr)
						{
							it.getPointer()->insertRight(new node(val));
							it = it.getPointer()->right();
							this->_size++;
							return (std::make_pair(it, true));
						}
						it = it.getPointer()->right();
					}
					else
					{
						if (it.getPointer()->left() == nullptr)
						{
							it.getPointer()->insertLeft(new node(val));
							it = it.getPointer()->left();
							this->_size++;
							return (std::make_pair(it, true));
						}
						it = it.getPointer()->left();
					}
				}
			}
			iterator	insert(iterator position, const value_type &val)
			{
				return (this->insert(val));
			}
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				InputIterator it(const_cast<node *>(first.getPointer()));
				InputIterator it2(const_cast<node *>(last.getPointer()));
				while (it != it2)
				{
					this->insert(*it);
					it++;
				}
			}
			void		erase(iterator position)
			{
				if (position.getPointer() == nullptr || this->empty() == true)
					return ;
				if (position.getPointer()->left() == nullptr &&
					position.getPointer()->right() == nullptr)
				{
					if (position.getPointer() == this->_root)
						this->_root = nullptr;
					position.getPointer()->deleteLeaf();
				}
				else if (position.getPointer()->left() == nullptr ||
					position.getPointer()->right() == nullptr)
				{
					if (position.getPointer() == this->_root)
						this->_root = (position.getPointer()->left() == nullptr) ?
							position.getPointer()->right() :
							position.getPointer()->left();
					position.getPointer()->deleteOneChild();
				}
				else
				{
					iterator it2 = position;
					iterator it = ++position;
					position = it2;
					position.getPointer()->swap(it.getPointer());
					this->erase(it);
					return ;
				}
				this->_size--;
			}
			size_type	erase(const key_type &k)
			{
				iterator it = this->find(k);
				size_type ret = (it.getPointer() == nullptr) ? 0 : 1;
				this->erase(it);
				return (ret);
			}
			void		erase(iterator first, iterator last)
			{
				iterator temp;
				while ((first != last))
				{
					temp = first;
					++temp;
					this->erase(first);
					first = temp;
				}
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
				this->_root = nullptr;
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
				iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (it->first == k)
						return (it);
				return (it);
			}
			const_iterator	find(const key_type &k) const
			{
				const_iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (it->first == k)
						return (it);
				return (it);
			}
			size_type	count(const key_type &k) const
			{
				const_iterator tmp = this->find(k);
				return ((tmp.getPointer() == nullptr) ? 0 : 1);
			}
			iterator		lower_bound(const key_type &k)
			{
				iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (key_compare()(it->first, k) == false)
						return (it);
				return (it);
			}
			const_iterator	lower_bound(const key_type &k) const
			{
				const_iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (key_compare()(it->first, k) == false)
						return (it);
				return (it);
			}
			iterator		upper_bound(const key_type &k)
			{
				iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (key_compare()(k, it->first) == true)
						return (it);
				return (it);
			}
			const_iterator	upper_bound(const key_type &k) const
			{
				const_iterator it;
				for (it = this->begin(); it != this->end(); ++it)
					if (key_compare()(k, it->first) == true)
						return (it);
				return (it);
			}
			std::pair<iterator, iterator> equal_range(const key_type &k)
			{
				return (std::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}
			std::pair<const_iterator, const_iterator> equal_range(const key_type &k) const
			{
				return (std::make_pair(this->lower_bound(k), this->upper_bound(k)));
			}
	};
	template <class Key,class T, class Compare, class Alloc>
	bool operator== (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		else
		{
			typename ft::map<Key,T,Compare,Alloc>::iterator it(
				const_cast<BSTNode<std::pair<Key, T> > *>(lhs.begin().getPointer()));
			typename ft::map<Key,T,Compare,Alloc>::iterator it2(
				const_cast<BSTNode<std::pair<Key, T> > *>(rhs.begin().getPointer()));
			while (it.getPointer() != nullptr)
			{
				if ((it->first != it2->first) || (it->second != it2->second))
					return (false);
				it++;
				it2++;
			}
		}
		return (true);
	}
	template <class Key,class T, class Compare, class Alloc>
	bool operator!= (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}
	template <class Key,class T, class Compare, class Alloc>
	bool operator< (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		typename ft::map<Key,T,Compare,Alloc>::iterator it(
			const_cast<BSTNode<std::pair<Key, T> > *>(lhs.begin().getPointer()));
		typename ft::map<Key,T,Compare,Alloc>::iterator it2(
			const_cast<BSTNode<std::pair<Key, T> > *>(rhs.begin().getPointer()));
		while (it.getPointer() != nullptr)
		{
			if (it.getPointer() == nullptr && it2.getPointer() != nullptr)
				return (true);
			else if (it2.getPointer() == nullptr)
				return (false);
			if (it->first < it2->first)
				return (true);
			else if (it->first > it2->first)
				return (false);
			else if ((it->first == it2->first) && (it->second < it2->second))
				return (true);
			else if ((it->first == it2->first) && (it->second > it2->second))
				return (false);
			it++;
			it2++;
		}
		return (false);
	}
	template <class Key,class T, class Compare, class Alloc>
	bool operator<= (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (!(rhs < lhs));
	}
	template <class Key,class T, class Compare, class Alloc>
	bool operator> (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (rhs < lhs);
	}
	template <class Key,class T, class Compare, class Alloc>
	bool operator>= (const ft::map<Key,T,Compare,Alloc> &lhs, const ft::map<Key,T,Compare,Alloc> &rhs)
	{
		return (!(lhs < rhs));
	}
	/****************************/
	/*      SWAP OVERLOAD       */
	/****************************/
	template <class Key,class T, class Compare, class Alloc>
	void swap (ft::map<Key,T,Compare,Alloc> &x, ft::map<Key,T,Compare,Alloc> &y)
	{
		x.swap(y);
	}
}
#endif
