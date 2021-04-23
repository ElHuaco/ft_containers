/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 13:20:43 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/04/22 13:41:31 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEQUE_HPP
# define DEQUE_HPP

namespace ft
{
	template<class T, class Alloc> class deque;

	template <class T, class Alloc>
		bool operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);
	template <class T, class Alloc>
		bool operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs);

	//Qid: por qué no usar std::allocator<std>?
	template<class T, class Alloc = /*???*/ > class deque
	{
		private:

		public:
	};

	template <class T, class Alloc>
		bool operator==(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
	template <class T, class Alloc>
		bool operator!=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
	template <class T, class Alloc>
		bool operator<(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
	template <class T, class Alloc>
		bool operator<=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
	template <class T, class Alloc>
		bool operator>(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
	template <class T, class Alloc>
		bool operator>=(const deque<T, Alloc>& lhs, const deque<T, Alloc>& rhs)
		{
			return (true);
		}
};
#endif
