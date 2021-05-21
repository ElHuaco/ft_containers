/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:35:21 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/21 13:42:07 by alejandro        ###   ########.fr       */
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
			std::cout << "[" << it->first << "]: " << it->second << ", ";
			it++;
		}
		std::cout << "END; " << "Size: " << mp.size() << std::endl;
		return ;
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
			std::cout << "[" << it->first << "]: " << it->second << ", ";
			it++;
		}
		std::cout << "END; " << "Size: " << mp.size() << std::endl;
		return ;
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
//	std::map<char, double> STM4(STM3); std::string name_STM4 = "STM4";
//		std::cout << "STM4(STM3): ";
//		my::print(STM4, name_STM4);
//	ft::map<char, double> FTM4(FTM3); std::string name_FTM4 = "FTM4";
//		std::cout << "FTM4(FTM3): ";
//		my::print(FTM4, name_FTM4);
//	std::map<char, double> STM5; std::string name_STM5 = "STM5";
//		STM5 = STM4;
//		std::cout << "STM5 = STM4: ";
//		my::print(STM5, name_STM5);
//	ft::map<char, double> FTM5; std::string name_FTM5 = "FTM5";
//		FTM5 = FTM4;
//		std::cout << "FTM5 = FTM4: ";
//		my::print(FTM5, name_FTM5);
std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "STM1.insert(std::make_pair<char, double>('a', 3.14)): "<< std::endl;
	std::cout << "\t";
	STM1.insert(std::make_pair<char, double>('a', 3.14));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('a', 3.14)): "<< std::endl;
	std::cout << "\t";
	FTM1.insert(std::make_pair<char, double>('a', 3.14));
	my::print(FTM1, name_FTM1);
	std::cout << "STM1.insert(std::make_pair<char, double>('A', 0.0001)): "<< std::endl;
	std::cout << "\t";
	STM1.insert(std::make_pair<char, double>('A', 0.0001));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('A', 0.0001)): "<< std::endl;
	std::cout << "\t";
	FTM1.insert(std::make_pair<char, double>('A', 0.0001));
	my::print(FTM1, name_FTM1);
	std::cout << "STM1.insert(std::make_pair<char, double>('b', 42.42)): "<< std::endl;
	std::cout << "\t";
	STM1.insert(std::make_pair<char, double>('b', 42.42));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('b', 42.42)): "<< std::endl;
	std::cout << "\t";
	FTM1.insert(std::make_pair<char, double>('b', 42.42));
	my::print(FTM1, name_FTM1);
	std::map<char, double> STM2(STM1.begin(), STM1.end()); std::string name_STM2 = "STM2";
		std::cout << "STM2(STM1.begin(), STM1.end()): ";
		my::print(STM2, name_STM2);
	ft::map<char, double> FTM2(FTM1.begin(), FTM1.end()); std::string name_FTM2 = "FTM2";
		std::cout << "FTM2(FTM1.begin(), FTM1.end()): ";
	std::cout << "Map test ending.";
		my::print(FTM2, name_FTM2);
	std::cout << "Map test ended.";
	return ;
}
