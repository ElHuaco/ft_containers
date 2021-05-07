/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:52:52 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/07 18:42:55 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../List/list.hpp"
#include <list>

namespace my
{
	template <class T> void print(ft::list<T> &lst, std::string &name)
	{
		std::cout << "List " << name << ": ";
		if (lst.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
	typename ft::list<T>::iterator it = lst.begin();
	std::cout << "(";
	while (it != lst.end())
		std::cout << *it++ << ", ";
	std::cout << "END); " << "Size: " << lst.size() <<"; Head: " << lst.front() <<
		"; End: " << lst.back() << std::endl;
	}
	template <class T> void print(std::list<T> &lst, std::string &name)
	{
		std::cout << "List " << name << ": ";
		if (lst.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
	typename std::list<T>::iterator it = lst.begin();
	std::cout << "(";
	while (it != lst.end())
		std::cout << *it++ << ", ";
	std::cout << "END); " << "Size: " << lst.size() <<"; Head: " << lst.front() <<
		"; End: " << lst.back() << std::endl;
	}

};

void test_list(void)
{
	std::cout << Color::bold << Color::red << "LIST TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Constructors" << Color::clean << std::endl;
	std::cout << Color::bold << "STL default constructor" << Color::clean << std::endl <<"\t";
	std::list<int> STL1; std::string name_STL1 = "STL1";
		my::print(STL1, name_STL1);
	ft::list<int> FT1; std::string name_FT1 = "FTL1";
	std::cout << Color::bold << "FT default constructor " << Color::clean << std::endl <<"\t";
		my::print(FT1, name_FT1);
	std::cout << Color::bold << "STL fill constructor" << Color::clean << std::endl <<"\t";
	std::list<int> STL2(4, 100); std::string name_STL2 = "STL2";
		my::print(STL2, name_STL2);
	ft::list<int> FT2(4, 100); std::string name_FT2 = "FTL2";
	std::cout << Color::bold << "FT fill constructor " << Color::clean << std::endl <<"\t";
		my::print(FT2, name_FT2);
	std::cout << Color::bold << "STL range constructor" << Color::clean << std::endl <<"\t";
	std::list<int> STL3(STL2.begin(), STL2.end()); std::string name_STL3 = "STL3";
		my::print(STL3, name_STL3);
	ft::list<int> FT3(FT2.begin(), FT2.end()); std::string name_FT3 = "FTL3";
	std::cout << Color::bold << "FT range constructor " << Color::clean << std::endl <<"\t";
		my::print(FT3, name_FT3);
	std::cout << Color::bold << "STL copy constructor" << Color::clean << std::endl <<"\t";
	std::list<int> STL4(STL3); std::string name_STL4 = "STL4";
		my::print(STL4, name_STL4);
	ft::list<int> FT4(FT3); std::string name_FT4 = "FTL4";
	std::cout << Color::bold << "FT copy constructor " << Color::clean << std::endl <<"\t";
		my::print(FT4, name_FT4);

	//L1.push_back(2);
	//L1.push_back(420);
	//ft::list<int> L2;
	//std::string name2 = "L2";
	//L2.push_back(123);
	//L2.push_back(0);
	//std::cout << "Sort L2" << std::endl;
	//L2.sort();
	//my::print_list(L2, name2);
	//std::cout << "Sort L1" << std::endl;
	//L1.sort();
	//my::print_list(L1, name1);
	//std::cout << "Splice L1, L2" << std::endl;
	//L1.splice(L1.begin(), L2);
	//my::print_list(L1, name1);
	//my::print_list(L2, name2);
	//std::cout << "Merge L1, L2" << std::endl;
	//std::cout << "Sort L1" << std::endl;
	//L1.sort();
	//L2.merge(L1);
	//my::print_list(L1, name1);
	//my::print_list(L2, name2);
}
