/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   predicates.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 12:49:20 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/10 12:50:44 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PREDICATES_HPP
# define PREDICATES_HPP

namespace ft
{
	template <class T>
	bool is_less(const T& n1, const T& n2) {return (n1 < n2);}
};
#endif
