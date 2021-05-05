/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:06:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/05 12:59:32 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "List/list.hpp"
#include <iostream>
#include <string>

int main (void)
{
	ft::list<int> L1;
	L1.push_back(42);
	std::cout << L1.back() << std::endl;
	return (0);
}
