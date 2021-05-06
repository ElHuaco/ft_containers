/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:06:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/06 17:33:00 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List/list.hpp"
#include <iostream>
#include <string>

namespace my
{
	template <class T> void print(ft::list<T> &lst)
	{
	typename ft::list<T>::iterator it = lst.begin();
	while (it != lst.end())
		std::cout << *it++ << std::endl;
	std::cout << "List size: " << lst.size() <<"; List head: " << lst.front() <<
		"; List end: " << lst.back() << std::endl;
	}
};

int main (void)
{
	ft::list<int> L1;
	L1.push_back(42);
	L1.push_back(2);
	L1.push_back(420);
	ft::list<int> L2(L1);
	L2.pop_back();
	my::print(L1);
	my::print(L2);
	ft::swap<int>(L1, L2);
	my::print(L1);
	my::print(L2);
	return (0);
}
