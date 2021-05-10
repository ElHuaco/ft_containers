/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 17:52:52 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/10 11:58:39 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../List/list.hpp"
#include <list>

namespace my
{
	template <class T> void print(ft::list<T> &lst, std::string &name)
	{
		std::cout << "List " << Color::green << name << ": " << Color::clean;
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
		std::cout << "List " << Color::blue << name << ": " << Color::clean;
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
bool is_bigger_than_99 (const int &n) {return (n > 99);}
bool both_even (const int &n1, const int &n2) {return (!(n1 % 2) && !(n2 % 2)); }
bool is_bigger (const int &n1, const int &n2) {return (n1 > n2);}

void test_list(void)
{
	std::cout << Color::bold << Color::red << "LIST TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Coplien and Constructors" << Color::clean << std::endl;
	std::list<int> STL1; std::string name_STL1 = "STL1";
		my::print(STL1, name_STL1);
	ft::list<int> FTL1; std::string name_FTL1 = "FTL1";
		my::print(FTL1, name_FTL1);
	std::list<int> STL2(4, 100); std::string name_STL2 = "STL2";
		std::cout << name_STL2 << "(4, 100): ";
		my::print(STL2, name_STL2);
	ft::list<int> FTL2(4, 100); std::string name_FTL2 = "FTL2";
		std::cout << name_FTL2 << "(4, 100): ";
		my::print(FTL2, name_FTL2);
	std::list<int> STL3(STL2.begin(), STL2.end()); std::string name_STL3 = "STL3";
		std::cout << "STL3(STL2.begin(), STL2.end()): ";
		my::print(STL3, name_STL3);
	ft::list<int> FTL3(FTL2.begin(), FTL2.end()); std::string name_FTL3 = "FTL3";
		std::cout << "FTL3(FTL2.begin(), FTL2.end()): ";
		my::print(FTL3, name_FTL3);
	std::list<int> STL4(STL3); std::string name_STL4 = "STL4";
		std::cout << "STL4(STL3): ";
		my::print(STL4, name_STL4);
	ft::list<int> FTL4(FTL3); std::string name_FTL4 = "FTL4";
		std::cout << "FTL4(FTL3): ";
		my::print(FTL4, name_FTL4);
	std::list<int> STL5; std::string name_STL5 = "STL5";
		STL5 = STL4;
		std::cout << "STL5 = STL4: ";
		my::print(STL5, name_STL5);
	ft::list<int> FTL5; std::string name_FTL5 = "FTL5";
		FTL5 = FTL4;
		std::cout << "FTL5 = FTL4: ";
		my::print(FTL5, name_FTL5);
	std::cout << Color::yellow << "Capacity Member Functions" << Color::clean << std::endl;
	std::cout << "List STL1.empty(): " << STL1.empty() << std::endl;
	std::cout << "List FTL1.empty(): " << FTL1.empty() << std::endl;
	std::cout << "List STL5.size(): " << STL2.size() << std::endl;
	std::cout << "List FTL5.size(): " << FTL2.size() << std::endl;
	std::cout << "List STL5.max_size(): " << STL5.max_size() << std::endl;
	std::cout << "List FTL5.max_size(): " << FTL5.max_size() << std::endl;
std::cout << Color::yellow << "Element Access Functions" << Color::clean << std::endl;
	std::cout << "List STL5.front(): " << STL5.front() << std::endl;
	std::cout << "List FTL5.front(): " << FTL5.front() << std::endl;
	std::cout << "List STL5.back(): " << STL5.back() << std::endl;
	std::cout << "List FTL5.back(): " << FTL5.back() << std::endl;
std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "STL5.assign(3, 42): ";
	STL5.assign(3, 42);
	my::print(STL5, name_STL5);
	std::cout << "FTL5.assign(3, 42): ";
	FTL5.assign(3, 42);
	my::print(FTL5, name_FTL5);
std::cout << std::endl;
	std::cout << "STL5.push_front(69): ";
	STL5.push_front(69);
	my::print(STL5, name_STL5);
	std::cout << "FTL5.push_front(69): ";
	FTL5.push_front(69);
	my::print(FTL5, name_FTL5);
	std::cout << "STL5.pop_front(): ";
	STL5.pop_front();
	my::print(STL5, name_STL5);
	std::cout << "FTL5.pop_front(): ";
	FTL5.pop_front();
	my::print(FTL5, name_FTL5);
	std::cout << "STL5.pop_back(): ";
	STL5.pop_back();
	my::print(STL5, name_STL5);
	std::cout << "FTL5.pop_back(): ";
	FTL5.pop_back();
	my::print(FTL5, name_FTL5);
std::cout << std::endl;
	std::cout << "STL1.insert(STL1.begin(), 123): ";
	STL1.insert(STL1.begin(), 123);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.insert(FTL1.begin(), 123): ";
	FTL1.insert(FTL1.begin(), 123);
	my::print(FTL1, name_FTL1);
	std::cout << "STL1.insert(++STL1.begin(), 3, 7): ";
	STL1.insert(++STL1.begin(), 3, 7);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.insert(++FTL1.begin(), 3, 7): ";
	FTL1.insert(++FTL1.begin(), 3, 7);
	my::print(FTL1, name_FTL1);
	std::cout << "STL1.insert(STL1.begin(), STL5.begin(), ++++STL5.begin()): ";
	STL1.insert(STL1.begin(), STL5.begin(), ++++STL5.begin());
	my::print(STL1, name_STL1);
	std::cout << "FTL1.insert(FTL1.begin(), FTL5.begin(), ++++FTL5.begin()): ";
	FTL1.insert(FTL1.begin(), FTL5.begin(), ++++FTL5.begin());
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	std::cout << "STL1.erase(++++STL1.begin()): ";
	STL1.erase(++++STL1.begin());
	my::print(STL1, name_STL1);
	std::cout << "FTL1.erase(++++FTL1.begin()): ";
	FTL1.erase(++++FTL1.begin());
	my::print(FTL1, name_FTL1);
	std::cout << "STL1.erase(STL1.begin(), STL1.end()): ";
	STL1.erase(STL1.begin(), STL1.end());
	my::print(STL1, name_STL1);
	std::cout << "FTL1.erase(FTL1.begin(), FTL1.end()): ";
	FTL1.erase(FTL1.begin(),FTL1.end());
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	std::cout << "STL1.swap(STL3): "<< std::endl;
	STL1.swap(STL3);
	my::print(STL1, name_STL1);
	my::print(STL3, name_STL3);
	std::cout << "STL1.swap(STL5): "<< std::endl;
	STL1.swap(STL5);
	my::print(STL1, name_STL1);
	my::print(STL5, name_STL5);
	std::cout << "FTL1.swap(FTL3): "<< std::endl;
	FTL1.swap(FTL3);
	my::print(FTL1, name_FTL1);
	my::print(FTL3, name_FTL3);
	std::cout << "FTL1.swap(FTL5): "<< std::endl;
	FTL1.swap(FTL5);
	my::print(FTL1, name_FTL1);
	my::print(FTL5, name_FTL5);
std::cout << std::endl;
	std::cout << "STL1.resize(8): ";
	STL1.resize(8);
	my::print(STL1, name_STL1);
	std::cout << "STL5.resize(3): ";
	STL5.resize(3);
	my::print(STL5, name_STL5);
	std::cout << "FTL1.resize(8): ";
	FTL1.resize(8);
	my::print(FTL1, name_FTL1);
	std::cout << "FTL5.resize(3): ";
	FTL5.resize(3);
	my::print(FTL5, name_FTL5);
std::cout << std::endl;
std::cout << Color::yellow << "Operation Member Functions" << Color::clean << std::endl;
	std::cout << "FTL1.splice(++FTL1.begin(), FTL5): ";
	FTL1.splice(++FTL1.begin(), FTL5);
	my::print(FTL1, name_FTL1);
	my::print(FTL5, name_FTL5);
	std::cout << "STL1.splice(++STL1.begin(), STL5): ";
	STL1.splice(++STL1.begin(), STL5);
	my::print(STL1, name_STL1);
	my::print(STL5, name_STL5);
std::cout << std::endl;
	std::cout << "STL1.remove(0): ";
	STL1.remove(0);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.remove(0): ";
	FTL1.remove(0);
	my::print(FTL1, name_FTL1);
	std::cout << "STL1.remove_if(is_bigger_than_99): ";
	STL1.remove_if(is_bigger_than_99);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.remove(is_bigger_than_99): ";
	FTL1.remove_if(is_bigger_than_99);
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	FTL1.push_back(78);
	FTL1.push_back(91);
	FTL1.push_back(78);
	FTL1.push_back(91);
	FTL1.push_back(456);
my::print(FTL1, name_FTL1);
	STL1.push_back(78);
	STL1.push_back(91);
	STL1.push_back(78);
	STL1.push_back(91);
	STL1.push_back(456);
my::print(STL1, name_STL1);
	std::cout << "STL1.unique(): ";
	STL1.unique();
	my::print(STL1, name_STL1);
	std::cout << "FTL1.unique(): ";
	FTL1.unique();
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	STL1.push_back(666);
	my::print(STL1, name_STL1);
	FTL1.push_back(666);
	my::print(FTL1, name_FTL1);
	std::cout << "STL1.unique(both_even): ";
	STL1.unique(both_even);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.unique(both_even): ";
	FTL1.unique(both_even);
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	std::cout << "STL1.sort(): ";
	STL1.sort();
	my::print(STL1, name_STL1);
	std::cout << "FTL1.sort(): ";
	FTL1.sort();
	my::print(FTL1, name_FTL1);
std::cout << std::endl;
	std::cout << "STL1.merge(STL2): ";
	STL1.merge(STL2);
	my::print(STL1, name_STL1);
	std::cout << "FTL1.merge(FTL2): ";
	FTL1.merge(FTL2);
	my::print(FTL1, name_FTL1);
std::cout << Color::yellow << "Relational Operators" << Color::clean << std::endl;

}
