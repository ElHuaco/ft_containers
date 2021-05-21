/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:35:21 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/21 12:10:27 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Map/map.hpp"
#include <map>

namespace my
{
	template <class Key, class T> void print(ft::map<Key, T> &mp, std::string &name)
	{
		std::cout << "Map " << Color::green << name << ": " << Color::clean;
		if (mp.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
		typename ft::map<Key, T>::iterator it = mp.begin();
		while (it != mp.end())
		{	
			std::cout << "[ " << it->first << " ]: " << it->second << ", ";
			it++;
		}
		std::cout << "END; " << "Size: " << mp.size() << std::endl;
	}
		template <class Key, class T> void print(std::map<Key, T> &mp, std::string &name)
	{
		std::cout << "Map " << Color::blue << name << ": " << Color::clean;
		if (mp.empty())
		{
			std::cout << "is empty." << std::endl;
			return ;
		}
		typename std::map<Key, T>::iterator it = mp.begin();
		while (it != mp.end())
		{	
			std::cout << "[ " << it->first << " ]: " << it->second << ", ";
			it++;
		}
		std::cout << "END; " << "Size: " << mp.size() << std::endl;
	}
};

void test_map(void)
{
	std::cout << Color::bold << Color::red << "MAP TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Coplien and Constructors" << Color::clean << std::endl;
	std::map<char, double> STM1; std::string name_STM1 = "STM1";
		my::print(STM1, name_STM1);
	ft::map<char, double> FTM1; std::string name_FTM1 = "FTM1";
		my::print(FTM1, name_FTM1);
	std::map<char, double> STM2; std::string name_STM2 = "STM2";
		my::print(STM2, name_STM2);
	ft::map<char, double> FTM2; std::string name_FTM2 = "FTM2";
		my::print(FTM2, name_FTM2);
	std::map<char, double> STM3(STM2.begin(), STM2.end()); std::string name_STM3 = "STM3";
		std::cout << "STM3(STM2.begin(), STM2.end()): ";
		my::print(STM3, name_STM3);
	ft::map<char, double> FTM3(FTM2.begin(), FTM2.end()); std::string name_FTM3 = "FTM3";
		std::cout << "FTM3(FTM2.begin(), FTM2.end()): ";
		my::print(FTM3, name_FTM3);
	std::map<char, double> STM4(STM3); std::string name_STM4 = "STM4";
		std::cout << "STM4(STM3): ";
		my::print(STM4, name_STM4);
	ft::map<char, double> FTM4(FTM3); std::string name_FTM4 = "FTM4";
		std::cout << "FTM4(FTM3): ";
		my::print(FTM4, name_FTM4);
	std::map<char, double> STM5; std::string name_STM5 = "STM5";
		STM5 = STM4;
		std::cout << "STM5 = STM4: ";
		my::print(STM5, name_STM5);
	ft::map<char, double> FTM5; std::string name_FTM5 = "FTM5";
		FTM5 = FTM4;
		std::cout << "FTM5 = FTM4: ";
		my::print(FTM5, name_FTM5);
//	std::cout << Color::yellow << "Capacity Member Functions" << Color::clean << std::endl;
//	std::cout << "Map STM1.empty(): " << STM1.empty() << std::endl;
//	std::cout << "Map FTM1.empty(): " << FTM1.empty() << std::endl;
//	std::cout << "Map STM1.capacity(): " << STM1.capacity() << std::endl;
//	std::cout << "Map FTM1.capacity(): " << FTM1.capacity() << std::endl;
//	std::cout << "Map STM5.reserve(50) -> ";
//	STM5.reserve(50);
//	std::cout << "Map STM5.capacity(): " << STM5.capacity() << std::endl;
//	my::print(STM5, name_STM5);
//	std::cout << "Map FTM5.reserve(50) -> ";
//	FTM5.reserve(50);
//	std::cout << "Map FTM5.capacity(): " << FTM5.capacity() << std::endl;
//	my::print(FTM5, name_FTM5);
//	std::cout << "Map STM2.size(): " << STM2.size() << std::endl;
//	std::cout << "Map FTM2.size(): " << FTM2.size() << std::endl;
//	std::cout << "Map STM2.max_size(): " << STM2.max_size() << std::endl;
//	std::cout << "Map FTM2.max_size(): " << FTM2.max_size() << std::endl;
//	std::cout << "Map STM2.resize(100): ";
//	my::print(STM2, name_STM2);
//	std::cout << "Map FTM2.resize(100): ";
//	my::print(FTM2, name_FTM2);
//std::cout << Color::yellow << "Element Access Functions" << Color::clean << std::endl;
//	std::cout << "Map STM5.front(): " << STM5.front() << std::endl;
//	std::cout << "Map FTM5.front(): " << FTM5.front() << std::endl;
//	std::cout << "Map STM5.back(): " << STM5.back() << std::endl;
//	std::cout << "Map FTM5.back(): " << FTM5.back() << std::endl;
//	std::cout << "Map STM5[2]: " << STM5[2] << std::endl;
//	std::cout << "Map FTM5[2]: " << FTM5[2] << std::endl;
//	std::cout << "Map STM5.at(2): " << STM5.at(2) << std::endl;
//	std::cout << "Map FTM5.at(2): " << FTM5.at(2) << std::endl;
//	try
//	{
//		std::cout << "Map STM5.at(10000): " << STM5.at(10000) << std::endl;
//	}
//	catch (std::out_of_range &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//	try
//	{
//		std::cout << "Map FTM5.at(10000): " << FTM5.at(10000) << std::endl;
//	}
//	catch (std::out_of_range &e)
//	{
//		std::cout << e.what() << std::endl;
//	}
//std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
//	std::cout << "STM5.assign(3, 42): ";
//	STM5.assign(3, 42);
//	my::print(STM5, name_STM5);
//	std::cout << "FTM5.assign(3, 42): ";
//	FTM5.assign(3, 42);
//	my::print(FTM5, name_FTM5);
//std::cout << std::endl;
//	std::cout << "STM5.push_back(69): ";
//	STM5.push_back(69);
//	my::print(STM5, name_STM5);
//	std::cout << "FTM5.push_back(69): ";
//	FTM5.push_back(69);
//	my::print(FTM5, name_FTM5);
//	std::cout << "STM5.pop_back(): ";
//	STM5.pop_back();
//	my::print(STM5, name_STM5);
//	std::cout << "FTM5.pop_back(): ";
//	FTM5.pop_back();
//	my::print(FTM5, name_FTM5);
//	std::cout << "STM5.pop_back(): ";
//	STM5.pop_back();
//	my::print(STM5, name_STM5);
//	std::cout << "FTM5.pop_back(): ";
//	FTM5.pop_back();
//	my::print(FTM5, name_FTM5);
//std::cout << std::endl;
//	std::cout << "STM1.insert(STM1.begin(), 123): ";
//	STM1.insert(STM1.begin(), 123);
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.insert(FTM1.begin(), 123): ";
//	FTM1.insert(FTM1.begin(), 123);
//	my::print(FTM1, name_FTM1);
//	std::cout << "STM1.insert(++STM1.begin(), 3, 7): ";
//	STM1.insert(++STM1.begin(), 3, 7);
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.insert(++FTM1.begin(), 3, 7): ";
//	FTM1.insert(++FTM1.begin(), 3, 7);
//	my::print(FTM1, name_FTM1);
//	std::cout << "STM1.insert(STM1.begin(), STM5.begin(), ++++STM5.begin()): ";
//	STM1.insert(STM1.begin(), STM5.begin(), ++++STM5.begin());
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.insert(FTM1.begin(), FTM5.begin(), ++++FTM5.begin()): ";
//	FTM1.insert(FTM1.begin(), FTM5.begin(), ++++FTM5.begin());
//	my::print(FTM1, name_FTM1);
//std::cout << std::endl;
//	std::cout << "STM1.erase(STM1.begin()): ";
//	STM1.erase(STM1.begin());
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.erase(FTM1.begin()): ";
//	FTM1.erase(FTM1.begin());
//	my::print(FTM1, name_FTM1);
//	std::cout << "STM1.erase(++++STM1.begin()): ";
//	STM1.erase(++++STM1.begin());
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.erase(++++FTM1.begin()): ";
//	FTM1.erase(++++FTM1.begin());
//	my::print(FTM1, name_FTM1);
//	std::cout << "STM1.erase(STM1.begin(), STM1.end()): ";
//	STM1.erase(STM1.begin(), STM1.end());
//	my::print(STM1, name_STM1);
//	std::cout << "FTM1.erase(FTM1.begin(), FTM1.end()): ";
//	FTM1.erase(FTM1.begin(),FTM1.end());
//	my::print(FTM1, name_FTM1);
//std::cout << std::endl;
//	std::cout << "STM1.swap(STM3): "<< std::endl;
//	STM1.swap(STM3);
//	my::print(STM1, name_STM1);
//	my::print(STM3, name_STM3);
//	std::cout << "STM1.swap(STM5): "<< std::endl;
//	STM1.swap(STM5);
//	my::print(STM1, name_STM1);
//	my::print(STM5, name_STM5);
//	std::cout << "FTM1.swap(FTM3): "<< std::endl;
//	FTM1.swap(FTM3);
//	my::print(FTM1, name_FTM1);
//	my::print(FTM3, name_FTM3);
//	std::cout << "FTM1.swap(FTM5): "<< std::endl;
//	FTM1.swap(FTM5);
//	my::print(FTM1, name_FTM1);
//	my::print(FTM5, name_FTM5);
//std::cout << Color::yellow << "Relational Operators" << Color::clean << std::endl;
//	STM2.push_back(420.69);
//	STM2.push_back(420.69);
//	my::print(STM1, name_STM1);
//	my::print(STM2, name_STM2);
//	my::print(STM4, name_STM4);
//	std::cout << std::endl;
//	FTM2.push_back(420.69);
//	FTM2.push_back(420.69);
//	my::print(FTM1, name_FTM1);
//	my::print(FTM2, name_FTM2);
//	my::print(FTM4, name_FTM4);
//	std::cout << "STM2 == STM4: ";
//	std::cout << std::boolalpha << (STM2 == STM4);
//	std::cout << std::endl;
//	std::cout << "STM4 < STM1: ";
//	std::cout << std::boolalpha << (STM4 < STM1);
//	std::cout << std::endl;
//	std::cout << "STM4 > STM1: ";
//	std::cout << std::boolalpha << (STM4 > STM1);
//	std::cout << std::endl;
//	std::cout << std::endl;
//	std::cout << "FTM2 == FTM4: ";
//	std::cout << std::boolalpha << (FTM2 == FTM4);
//	std::cout << std::endl;
//	std::cout << "FTM4 < FTM1: ";
//	std::cout << std::boolalpha << (FTM4 < FTM1);
//	std::cout << std::endl;
//	std::cout << "FTM4 > FTM1: ";
//	std::cout << std::boolalpha << (FTM4 > FTM1);
//	std::cout << std::endl;
}
