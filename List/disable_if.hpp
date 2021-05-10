/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disable_if.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 09:28:10 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/10 09:50:18 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISABLE_IF_HPP
# define DISABLE_IF_HPP

namespace ft
{
	template <class T, T val>
	struct integral_constant
	{
	   typedef T value_type;
	   typedef integral_constant<T, val> type;
	   static const T value = val;
	};
	
	template <class T, T val>
	T const integral_constant<T, val>::value;

	template <bool val>
	struct integral_constant<bool, val>
	{
	   typedef bool value_type;
	   typedef integral_constant<bool, val> type;
	   static const bool value = val;
	};
	
	template <bool val>
	bool const integral_constant<bool, val>::value;
	
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

	template <class T> struct is_integral : public false_type {};
	template <class T> struct is_integral<const T> : public is_integral<T> {};
	
	template <> struct is_integral<unsigned char> : public true_type{};
	template <> struct is_integral<unsigned short> : public true_type{};
	template <> struct is_integral<unsigned int> : public true_type{};
	template <> struct is_integral<unsigned long> : public true_type{};
	template <> struct is_integral<signed char> : public true_type{};
	template <> struct is_integral<short> : public true_type{};
	template <> struct is_integral<int> : public true_type{};
	template <> struct is_integral<long> : public true_type{};
	template <> struct is_integral<char> : public true_type{};
	template <> struct is_integral<bool> : public true_type{};
	
	template <bool B, class T = void>
	struct disable_if_c {
	typedef T type;
	};

	template <class T>
	struct disable_if_c<true, T> {};

	template <class Cond, class T = void> 
	struct disable_if : public disable_if_c<Cond::value, T> {};
};
#endif
