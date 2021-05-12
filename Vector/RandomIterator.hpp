/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RandomIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:09:20 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/12 10:34:52 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ITERATOR_HPP
# define RANDOM_ITERATOR_HPP

# include <iterator>

namespace ft
{
	template <class T> class RandomIterator
		: public std::iterator<std::random_access_iterator_tag, T>
	{
		public:
			typedef T			value_type;
			typedef value_type	*pointer;
			typedef value_type	&reference;
			typedef size_t		size_type;

		private:
			pointer		_ptr;
	
		public:
			explicit RandomIterator(pointer defptr = nullptr) : _ptr(defptr)
			{
			}
			RandomIterator(const RandomIterator &other)
			{
				_ptr = other._ptr;
			}
			virtual ~RandomIterator(void)
			{
			}
			RandomIterator	&operator=(const pointer n_ptr)
			{
				_ptr = n_ptr;
				return (*this);
			}
			RandomIterator	&operator=(const RandomIterator &rhs)
			{
				if (*this == rhs)
					return (*this);
				_ptr = rhs._ptr;
				return (*this);
			}
			reference	operator*(void) const
			{
				return (*_ptr);
			}
			pointer		operator->(void) const
			{
				return (_ptr);
			}
			RandomIterator	&operator++(void)
			{
				_ptr++;
				return (*this);
			}
			RandomIterator	operator++(int)
			{
				RandomIterator temp = *this;
				_ptr++;
				return (temp);
			}
			RandomIterator	operator++(int) const
			{
				RandomIterator temp = *this;
				_ptr++;
				return (temp);
			}

			RandomIterator	&operator--(void)
			{
				_ptr--;
				return (*this);
			}
			RandomIterator	operator--(int)
			{
				RandomIterator temp = *this;
				_ptr--;
				return (temp);
			}
			RandomIterator	operator--(int) const
			{
				RandomIterator temp = *this;
				_ptr--;
				return (temp);
			}
			RandomIterator	operator-(const RandomIterator &rhs) const
			{
				return (RandomIterator(_ptr - rhs._ptr));
			}
			RandomIterator	operator+(const size_type &n)
			{
				RandomIterator tmp;
				tmp._ptr = this->_ptr + n;
				return (tmp);
			}
			RandomIterator	operator-(const size_type &n)
			{
				RandomIterator tmp;
				tmp._ptr = this->_ptr - n;
				return (tmp);
			}
			RandomIterator	&operator+=(const size_type &n)
			{
				_ptr += n;
				return (*this);
			}
			RandomIterator	&operator-=(const size_type &n)
			{
				_ptr -= n;
				return (*this);
			}
			value_type	operator[](const size_type &n)
			{
				return (*(_ptr + n));
			}
			pointer		getPointer(void) const
			{
				return (_ptr);
			}
			void		setPointer(pointer newPtr)
			{
				_ptr = newPtr;
			}
	};
	template <class T>
		bool operator== (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (lhs.getPointer() == rhs.getPointer());
		}
	template <class T>
		bool operator!= (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (!(lhs == rhs));
		}
	template <class T>
		bool operator< (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (lhs.getPointer() < rhs.getPointer());
		}
	template <class T>
		bool operator> (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (rhs < lhs);
		}
	template <class T>
		bool operator<= (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (!(rh < lhs));
		}
	template <class T>
		bool operator>= (const RandomIterator<T> &lhs, const RandomIterator<T> &rhs)
		{
			return (!(lhs < rhs));
		}

	template <class Base> class ReverseRandomIterator :
		public std::reverse_iterator<Base>
	{
		public:
			typedef typename std::reverse_iterator<Base>	base_iterator;
			typedef typename base_iterator::value_type		value_type;
			typedef typename base_iterator::pointer			pointer;
			typedef typename base_iterator::reference		reference;

			explicit ReverseRandomIterator(void) : base_iterator()
			{
			}
			ReverseRandomIterator(const typename base_iterator::iterator_type &it)
				: base_iterator(it)
			{
			}
			ReverseRandomIterator(const base_iterator &it) : base_iterator(it)
			{
			}
			ReverseRandomIterator(pointer defptr)
				: base_iterator(typename base_iterator::iterator_type(defptr))
			{
			}
			virtual ~ReverseRandomIterator(void)
			{
			}
			ReverseRandomIterator &operator=(const ReverseRandomIterator &rhs)
			{
				this->base()._ptr = rhs.base()._ptr;
				return (*this);
			}
			ReverseRandomIterator operator++(int)
			{
				return (base_iterator::operator++(1));
			}
			ReverseRandomIterator operator++(int) const
			{
				return (base_iterator::operator++(1));
			}
			ReverseRandomIterator operator++(void)
			{
				base_iterator::operator++();
				return (*this);
			}
			ReverseRandomIterator operator--(int)
			{
				return (base_iterator::operator--(1));
			}
			ReverseRandomIterator operator--(int) const
			{
				return (base_iterator::operator--(1));
			}
			ReverseRandomIterator operator--(void)
			{
				base_iterator::operator--();
				return (*this);
			}
			value_type	&operator*(void) const
			{
				return (*this->base().getPointer());
			}
			value_type *operator->(void) const
			{
				return (&this->base().getPointer());
			}
			pointer		getPointer(void) const
			{
				return (this->base().getPointer());
			}
			void		setPointer(pointer newPtr)
			{
				this->base()._ptr = newPtr;
			}
	};
	template <class Base>
		bool operator== (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (lhs.base().getPointer() == rhs.base().getPointer());
		}
	template <class Base>
		bool operator!= (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (!(lhs == rhs));
		}
	template <class Base>
		bool operator< (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (lhs.base().getPointer() < rhs.base().getPointer());
		}
	template <class Base>
		bool operator> (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (rhs < lhs);
		}
	template <class Base>
		bool operator<= (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (!(rh < lhs));
		}
	template <class Base>
		bool operator>= (const ReverseRandomIterator<Base> &lhs,
			const ReverseRandomIterator<Base> &rhs)
		{
			return (!(lhs < rhs));
		}
}
#endif

