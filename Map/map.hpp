/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 08:50:51 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/18 09:16:41 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP

# include "../shared_tools/predicates.hpp"
# include "BidirectionalMapIterator.hpp"
# include <utility>
# include <functional>

namespace ft
{
	template <class Key, class T, class Compare = ft::is_less<Key>,
		class Alloc = std::allocator<std::pair<const Key, T> > class map
	{
		public:
			typedef Key										key_type;
			typedef T										mapped_type;
			typedef pair<const key_type, mapped_type>		value_type;
			typedef Compare									key_compare;
			typedef Alloc									allocator_type;
			typedef allocator_type::reference				reference
			typedef allocator_type::const_reference			const_reference
			typedef allocator_type::pointer					pointer
			typedef allocator_type::const_pointer			const_pointer
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
	};
};
#endif
