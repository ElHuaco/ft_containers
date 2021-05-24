/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_map.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 11:35:21 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/24 12:08:29 by alejandro        ###   ########.fr       */
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
		std::cout << "END" << "; Size: " << mp.size() << "; Root: " <<
			mp.getRoot()->getData().first << std::endl; 
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
		std::cout << "END" << "; Size: " << mp.size() << std::endl; 
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
	std::cout << std::endl;
std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "STM1.insert(std::make_pair<char, double>('a', 3.14)): "<< std::endl;
	STM1.insert(std::make_pair<char, double>('a', 3.14));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('a', 3.14)): "<< std::endl;
	FTM1.insert(std::make_pair<char, double>('a', 3.14));
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
	std::cout << "STM1.insert(std::make_pair<char, double>('A', 0.0001)): "<< std::endl;
	STM1.insert(std::make_pair<char, double>('A', 0.0001));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('A', 0.0001)): "<< std::endl;
	FTM1.insert(std::make_pair<char, double>('A', 0.0001));
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
	std::cout << "STM1.insert(std::make_pair<char, double>('c', 69.0)): "<< std::endl;
	STM1.insert(std::make_pair<char, double>('c', 69.0));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('c', 69.0)): "<< std::endl;
	FTM1.insert(std::make_pair<char, double>('c', 69.0));
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
	std::cout << "STM1.insert(std::make_pair<char, double>('b', 42.42)): "<< std::endl;
	STM1.insert(std::make_pair<char, double>('b', 42.42));
	my::print(STM1, name_STM1);
	std::cout << "FTM1.insert(std::make_pair<char, double>('b', 42.42)): "<< std::endl;
	FTM1.insert(std::make_pair<char, double>('b', 42.42));
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
std::cout << Color::yellow << "Iterators and Capacity" << Color::clean << std::endl;
	std::cout << "STM1.max_size(): " << STM1.max_size() << std::endl;
	std::cout << "FTM1.max_size(): " << FTM1.max_size() << std::endl;
	std::cout << "STM1.rbegin(): " << STM1.rbegin()->first << std::endl;
	std::cout << "FTM1.rbegin(): " << FTM1.rbegin()->first << std::endl;
std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::map<char, double> STM2(STM1.begin(), STM1.end()); std::string name_STM2 = "STM2";
		std::cout << "STM2(STM1.begin(), STM1.end()): " << std::endl;
		my::print(STM2, name_STM2);
	ft::map<char, double> FTM2(FTM1.begin(), FTM1.end()); std::string name_FTM2 = "FTM2";
		std::cout << "FTM2(FTM1.begin(), FTM1.end()): " << std::endl;
	my::print(FTM2, name_FTM2);
	std::cout << std::endl;
	std::map<char, double> STM3(STM1); std::string name_STM3 = "STM3";
		std::cout << "STM3(STM1): " << std::endl;
		my::print(STM3, name_STM3);
	ft::map<char, double> FTM3(FTM1); std::string name_FTM3 = "FTM3";
		std::cout << "FTM3(FTM1): " << std::endl;
	my::print(FTM3, name_FTM3);
	std::cout << std::endl;
	std::cout << "STM1.erase('a'): " << std::endl;
	STM1.erase('a');
	my::print(STM1, name_STM1);
	std::cout << "FTM1.erase('a'): " << std::endl;
	FTM1.erase('a');
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
	std::cout << "STM2.erase(++STM2.begin(), STM2.end()): " << std::endl;
	STM2.erase(++STM2.begin(), STM2.end());
	my::print(STM2, name_STM2);
	std::cout << "FTM2.erase(++FTM2.begin(), FTM2.end()): " << std::endl;
	FTM2.erase(++FTM2.begin(), FTM2.end());
	my::print(FTM2, name_FTM2);
	std::cout << std::endl;
	std::cout << "STM2.swap(STM1): " << std::endl;
	STM2.swap(STM1);
	my::print(STM2, name_STM2);
	my::print(STM1, name_STM1);
	std::cout << "FTM2.swap(FTM1): " << std::endl;
	FTM2.swap(FTM1);
	my::print(FTM2, name_FTM2);
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
	std::cout << "STM1.clear(): ";
	STM1.clear();
	my::print(STM1, name_STM1);
	std::cout << "FTM1.clear(): ";
	FTM1.clear();
	my::print(FTM1, name_FTM1);
	std::cout << std::endl;
std::cout << Color::yellow << "Element Access Functions" << Color::clean << std::endl;
	std::cout << "STM2['b']: " << STM2['b'] << std::endl;
	std::cout << "STM2['a']: " << STM2['a'] << std::endl;
	std::cout << "STM2['Z']: " << STM2['Z'] << std::endl;
	my::print(STM2, name_STM2);
	std::cout << "FTM2['b']: " << FTM2['b'] << std::endl;
	std::cout << "FTM2['a']: " << FTM2['a'] << std::endl;
	std::cout << "FTM2['Z']: " << FTM2['Z'] << std::endl;
	my::print(FTM2, name_FTM2);
	std::cout << std::endl;
std::cout << Color::yellow << "Operation Functions" << Color::clean << std::endl;
	std::cout << "STM2.find('Z') : " << STM2.find('Z')->second << std::endl;
	std::cout << "FTM2.find('Z') : " << FTM2.find('Z')->second << std::endl;
	std::cout << "STM2.find('A') : " << STM2.find('A')->second << std::endl;
	std::cout << "FTM2.find('A') : " << FTM2.find('A')->second << std::endl;
	std::cout << std::endl;
	std::cout << "FTM2.find('k') : " << FTM2.find('k').getPointer() << std::endl;
	std::cout << std::endl;
	std::cout << "STM2.count('Z'): " << STM2.count('Z') << std::endl;
	std::cout << "FTM2.count('Z'): " << FTM2.count('Z') << std::endl;
	std::cout << "STM2.count('k'): " << STM2.count('k') << std::endl;
	std::cout << "FTM2.count('k'): " << FTM2.count('k') << std::endl;
	std::cout << std::endl;
	std::cout << "STM2.lower_bound('A'): " << STM2.lower_bound('A')->first << std::endl;
	std::cout << "FTM2.lower_bound('A'): " << FTM2.lower_bound('A')->first << std::endl;
	std::cout << "STM2.lower_bound('a'): " << STM2.lower_bound('a')->first << std::endl;
	std::cout << "FTM2.lower_bound('a'): " << FTM2.lower_bound('a')->first << std::endl;
	std::cout << "STM2.lower_bound('b'): " << STM2.lower_bound('b')->first << std::endl;
	std::cout << "FTM2.lower_bound('b'): " << FTM2.lower_bound('b')->first << std::endl;
	std::cout << "STM2.lower_bound('Z'): " << STM2.lower_bound('Z')->first << std::endl;
	std::cout << "FTM2.lower_bound('Z'): " << FTM2.lower_bound('Z')->first << std::endl;
	std::cout << std::endl;
	std::cout << "STM2.upper_bound('A'): " << STM2.upper_bound('A')->first << std::endl;
	std::cout << "FTM2.upper_bound('A'): " << FTM2.upper_bound('A')->first << std::endl;
	std::cout << "STM2.upper_bound('a'): " << STM2.upper_bound('a')->first << std::endl;
	std::cout << "FTM2.upper_bound('a'): " << FTM2.upper_bound('a')->first << std::endl;
	std::cout << "STM2.upper_bound('b'): " << STM2.upper_bound('b')->first << std::endl;
	std::cout << "FTM2.upper_bound('b'): " << FTM2.upper_bound('b')->first << std::endl;
	std::cout << "STM2.upper_bound('Z'): " << STM2.upper_bound('Z')->first << std::endl;
	std::cout << "FTM2.upper_bound('Z'): " << FTM2.upper_bound('Z')->first << std::endl;
	std::cout << std::endl;
	std::cout << "STM2.equal_range('A'): " << STM2.equal_range('A').first->first << std::endl;
	std::cout << "FTM2.equal_range('A'): " << FTM2.equal_range('A').first->first << std::endl;
	std::cout << "STM2.equal_range('c'): " << STM2.equal_range('c').first->first << std::endl;
	std::cout << "FTM2.equal_range('c'): " << FTM2.equal_range('c').first->first << std::endl;
	std::cout << "STM2.equal_range('b'): " << STM2.equal_range('b').first->first << std::endl;
	std::cout << "FTM2.equal_range('b'): " << FTM2.equal_range('b').first->first << std::endl;
	std::cout << std::endl;
std::cout << Color::yellow << "Observer Functions" << Color::clean << std::endl;
	std::cout << "STM2.key_comp()('A', 'Z'): " << std::boolalpha << STM2.key_comp()('A', 'Z') << std::endl;
	std::cout << "FTM2.key_comp()('A', 'Z'): " << std::boolalpha << FTM2.key_comp()('A', 'Z') << std::endl;
	std::cout << "STM2.value_comp()(*STM2.begin(), *STM2.find(c)): " << std::boolalpha << STM2.key_comp()('A', 'Z') << std::endl;
	std::cout << "FTM2.value_comp()(*FTM2.begin(), *FTM2.find(c)): " << std::boolalpha << FTM2.key_comp()('A', 'Z') << std::endl;
std::cout << Color::yellow << "Relational Operators" << Color::clean << std::endl;
	STM3.insert(std::make_pair('u', -245.2));	
	FTM3.insert(std::make_pair('u', -245.2));	
	STM3.insert(std::make_pair('T', -12.007));	
	FTM3.insert(std::make_pair('T', -12.007));
	my::print(STM2, name_STM2);
	my::print(STM3, name_STM3);
	my::print(FTM2, name_FTM2);
	my::print(FTM3, name_FTM3);
	std::cout << " STM2 == STM3 " << std::boolalpha << (STM2 == STM3) << std::endl;
	std::cout << " FTM2 == FTM3 " << std::boolalpha << (FTM2 == FTM3) << std::endl;
	std::cout << std::endl;
	std::cout << " STM2 != STM3 " << std::boolalpha << (STM2 != STM3) << std::endl;
	std::cout << " FTM2 != FTM3 " << std::boolalpha << (FTM2 != FTM3) << std::endl;
	std::cout << std::endl;
	std::cout << " STM2 < STM3 " << std::boolalpha << (STM2 < STM3) << std::endl;
	std::cout << " FTM2 < FTM3 " << std::boolalpha << (FTM2 < FTM3) << std::endl;
	std::cout << std::endl;
	std::cout << " STM2 <= STM3 " << std::boolalpha << (STM2 <= STM3) << std::endl;
	std::cout << " FTM2 <= FTM3 " << std::boolalpha << (FTM2 <= FTM3) << std::endl;
	std::cout << std::endl;
	std::cout << " STM2 > STM3 " << std::boolalpha << (STM2 > STM3) << std::endl;
	std::cout << " FTM2 > FTM3 " << std::boolalpha << (FTM2 > FTM3) << std::endl;
	std::cout << std::endl;
	std::cout << " STM2 >= STM3 " << std::boolalpha << (STM2 >= STM3) << std::endl;
	std::cout << " FTM2 >= FTM3 " << std::boolalpha << (FTM2 >= FTM3) << std::endl;
	std::cout << std::endl;
	return ;
}
