/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:07:41 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/04/22 13:12:20 by aleon-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "deque.hpp"

namespace my
{
	template<class T, class Container> class queue;

	template <class T, class Container>
		bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <class T, class Container>
		bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <class T, class Container>
		bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <class T, class Container>
		bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <class T, class Container>
		bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs);
	template <class T, class Container>
		bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs);

	template <class T, class Container = my::deque<T>> class queue
	{
		private:
			Container	c;
			typedef T value_type;
			typedef Container container_type;
			typedef Container::size_type size_type;

		public:
			queue(void);
			queue(queue const &other);
			~queue(void);

			queue				&operator=(queue const &rhs);

			bool				empty(void) const;
			size_type			size(void) const;
			
			value_type			&front(void);
			const value_type	&front(void) const;
			value_type			&back(void);
			const value_type	&back(void) const;

			void				push(const value_type &val);
			void				pop(void);

			friend bool			operator== <T, Container>(const queue &lhs,const queue &rhs);
			friend bool			operator!= <T, Container>(const queue &lhs,const queue &rhs);
			friend bool			operator< <T, Container>(const queue &lhs,const queue &rhs);
			friend bool			operator<= <T, Container>(const queue &lhs,const queue &rhs);
			friend bool			operator> <T, Container>(const queue &lhs,const queue &rhs);
			friend bool			operator>= <T, Container>(const queue &lhs,const queue &rhs);
	};

	template <class T, class Container>
		bool operator==(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator==(lhs.c, rhs.c));
		}
	template <class T, class Container>
		bool operator!=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator!=(lhs.c, rhs.c));
		}
	template <class T, class Container>
		bool operator<(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator<(lhs.c, rhs.c));
		}
	template <class T, class Container>
		bool operator<=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator<=(lhs.c, rhs.c));
		}
	template <class T, class Container>
		bool operator>(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator>(lhs.c, rhs.c));
		}
	template <class T, class Container>
		bool operator>=(const queue<T, Container>& lhs, const queue<T, Container>& rhs)
		{
			return (operator>=(lhs.c, rhs.c));
		}
};
#endif
