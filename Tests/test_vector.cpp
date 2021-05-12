/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:17:39 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/12 13:13:56 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Vector/vector.hpp"
#include <vector>

namespace my
{
	template <class T> void print(ft::vector<T> &vec, std::string &name)
	{
		std::cout << "Vector " << Color::green << name << ": " << Color::clean;
		if (vec.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
	typename ft::vector<T>::iterator it = vec.begin();
	std::cout << "(";
	while (it != vec.end())
		std::cout << *it++ << ", ";
	std::cout << "END); " << "Size: " << vec.size() <<"; Cap.: "<< vec.capacity() << std::endl;
	}
	template <class T> void print(std::vector<T> &vec, std::string &name)
	{
		std::cout << "Vector " << Color::blue << name << ": " << Color::clean;
		if (vec.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
	typename std::vector<T>::iterator it = vec.begin();
	std::cout << "(";
	while (it != vec.end())
		std::cout << *it++ << ", ";
	std::cout << "END); " << "Size: " << vec.size() <<"; Cap.: " << vec.capacity() << std::endl;
	}

};

void test_vector(void)
{
	ft::vector<double> V1(4, 99.99); std::string name_V1("V1");
	V1.push_back(3.14);
	my::print(V1, name_V1);
	V1.reserve(100);
	my::print(V1, name_V1);
}
