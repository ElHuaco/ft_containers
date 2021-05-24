/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 12:17:39 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/24 12:33:50 by alejandro        ###   ########.fr       */
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
	std::cout << Color::bold << Color::red << "VECTOR TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Coplien and Constructors" << Color::clean << std::endl;
	std::vector<double> STV1; std::string name_STV1 = "STV1";
		my::print(STV1, name_STV1);
	ft::vector<double> FTV1; std::string name_FTV1 = "FTV1";
		my::print(FTV1, name_FTV1);
	std::vector<double> STV2(4, 3.14); std::string name_STV2 = "STV2";
		std::cout << name_STV2 << "(4, 3.14): ";
		my::print(STV2, name_STV2);
	ft::vector<double> FTV2(4, 3.14); std::string name_FTV2 = "FTV2";
		std::cout << name_FTV2 << "(4, 3.14): ";
		my::print(FTV2, name_FTV2);
	std::vector<double> STV3(STV2.begin(), STV2.end()); std::string name_STV3 = "STV3";
		std::cout << "STV3(STV2.begin(), STV2.end()): ";
		my::print(STV3, name_STV3);
	ft::vector<double> FTV3(FTV2.begin(), FTV2.end()); std::string name_FTV3 = "FTV3";
		std::cout << "FTV3(FTV2.begin(), FTV2.end()): ";
		my::print(FTV3, name_FTV3);
	std::vector<double> STV4(STV3); std::string name_STV4 = "STV4";
		std::cout << "STV4(STV3): ";
		my::print(STV4, name_STV4);
	ft::vector<double> FTV4(FTV3); std::string name_FTV4 = "FTV4";
		std::cout << "FTV4(FTV3): ";
		my::print(FTV4, name_FTV4);
	std::vector<double> STV5; std::string name_STV5 = "STV5";
		STV5 = STV4;
		std::cout << "STV5 = STV4: ";
		my::print(STV5, name_STV5);
	ft::vector<double> FTV5; std::string name_FTV5 = "FTV5";
		FTV5 = FTV4;
		std::cout << "FTV5 = FTV4: ";
		my::print(FTV5, name_FTV5);
	std::cout << Color::yellow << "Capacity Member Functions" << Color::clean << std::endl;
	std::cout << "Vector STV1.empty(): " << STV1.empty() << std::endl;
	std::cout << "Vector FTV1.empty(): " << FTV1.empty() << std::endl;
	std::cout << "Vector STV1.capacity(): " << STV1.capacity() << std::endl;
	std::cout << "Vector FTV1.capacity(): " << FTV1.capacity() << std::endl;
	std::cout << "Vector STV5.reserve(50) -> ";
	STV5.reserve(50);
	std::cout << "Vector STV5.capacity(): " << STV5.capacity() << std::endl;
	my::print(STV5, name_STV5);
	std::cout << "Vector FTV5.reserve(50) -> ";
	FTV5.reserve(50);
	std::cout << "Vector FTV5.capacity(): " << FTV5.capacity() << std::endl;
	my::print(FTV5, name_FTV5);
	std::cout << "Vector STV2.size(): " << STV2.size() << std::endl;
	std::cout << "Vector FTV2.size(): " << FTV2.size() << std::endl;
	std::cout << "Vector STV2.max_size(): " << STV2.max_size() << std::endl;
	std::cout << "Vector FTV2.max_size(): " << FTV2.max_size() << std::endl;
	std::cout << "Vector STV2.resize(100): ";
	STV2.resize(100);
	my::print(STV2, name_STV2);
	std::cout << "Vector FTV2.resize(100): ";
	FTV2.resize(100);
	my::print(FTV2, name_FTV2);
std::cout << Color::yellow << "Element Access Functions" << Color::clean << std::endl;
	STV5.push_back(1.57);
	STV5.insert(STV5.begin(), 234);
	FTV5.push_back(1.57);
	FTV5.insert(FTV5.begin(), 234);
	FTV5.erase(++FTV5.begin(), ++++++++FTV5.begin());
	STV5.erase(++STV5.begin(), ++++++++STV5.begin());
	my::print(STV5, name_STV5);
	my::print(FTV5, name_FTV5);
	std::cout << "Vector STV5.front(): " << STV5.front() << std::endl;
	std::cout << "Vector FTV5.front(): " << FTV5.front() << std::endl;
	std::cout << "Vector STV5.back(): " << STV5.back() << std::endl;
	std::cout << "Vector FTV5.back(): " << FTV5.back() << std::endl;
	std::cout << "Vector STV5[1]: " << STV5[1] << std::endl;
	std::cout << "Vector FTV5[1]: " << FTV5[1] << std::endl;
	std::cout << "Vector STV5.at(1): " << STV5.at(1) << std::endl;
	std::cout << "Vector FTV5.at(1): " << FTV5.at(1) << std::endl;
	try
	{
		std::cout << "Vector STV5.at(10000): " << STV5.at(10000) << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Vector FTV5.at(10000): " << FTV5.at(10000) << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Vector STV5.at(-10000): " << STV5.at(-10000) << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		std::cout << "Vector FTV5.at(-10000): " << FTV5.at(-10000) << std::endl;
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "STV5.assign(3, 42): ";
	STV5.assign(3, 42);
	my::print(STV5, name_STV5);
	std::cout << "FTV5.assign(3, 42): ";
	FTV5.assign(3, 42);
	my::print(FTV5, name_FTV5);
std::cout << std::endl;
	std::cout << "STV5.push_back(69): ";
	STV5.push_back(69);
	my::print(STV5, name_STV5);
	std::cout << "FTV5.push_back(69): ";
	FTV5.push_back(69);
	my::print(FTV5, name_FTV5);
	std::cout << "STV5.pop_back(): ";
	STV5.pop_back();
	my::print(STV5, name_STV5);
	std::cout << "FTV5.pop_back(): ";
	FTV5.pop_back();
	my::print(FTV5, name_FTV5);
	std::cout << "STV5.pop_back(): ";
	STV5.pop_back();
	my::print(STV5, name_STV5);
	std::cout << "FTV5.pop_back(): ";
	FTV5.pop_back();
	my::print(FTV5, name_FTV5);
std::cout << std::endl;
	std::cout << "STV1.insert(STV1.begin(), 123): ";
	STV1.insert(STV1.begin(), 123);
	my::print(STV1, name_STV1);
	std::cout << "FTV1.insert(FTV1.begin(), 123): ";
	FTV1.insert(FTV1.begin(), 123);
	my::print(FTV1, name_FTV1);
	std::cout << "STV1.insert(++STV1.begin(), 3, 7): ";
	STV1.insert(++STV1.begin(), 3, 7);
	my::print(STV1, name_STV1);
	std::cout << "FTV1.insert(++FTV1.begin(), 3, 7): ";
	FTV1.insert(++FTV1.begin(), 3, 7);
	my::print(FTV1, name_FTV1);
	std::cout << "STV1.insert(STV1.begin(), STV5.begin(), ++++STV5.begin()): ";
	STV1.insert(STV1.begin(), STV5.begin(), ++++STV5.begin());
	my::print(STV1, name_STV1);
	std::cout << "FTV1.insert(FTV1.begin(), FTV5.begin(), ++++FTV5.begin()): ";
	FTV1.insert(FTV1.begin(), FTV5.begin(), ++++FTV5.begin());
	my::print(FTV1, name_FTV1);
std::cout << std::endl;
	std::cout << "STV1.erase(STV1.begin()): ";
	STV1.erase(STV1.begin());
	my::print(STV1, name_STV1);
	std::cout << "FTV1.erase(FTV1.begin()): ";
	FTV1.erase(FTV1.begin());
	my::print(FTV1, name_FTV1);
	std::cout << "STV1.erase(++++STV1.begin()): ";
	STV1.erase(++++STV1.begin());
	my::print(STV1, name_STV1);
	std::cout << "FTV1.erase(++++FTV1.begin()): ";
	FTV1.erase(++++FTV1.begin());
	my::print(FTV1, name_FTV1);
	std::cout << "STV1.erase(STV1.begin(), STV1.end()): ";
	STV1.erase(STV1.begin(), STV1.end());
	my::print(STV1, name_STV1);
	std::cout << "FTV1.erase(FTV1.begin(), FTV1.end()): ";
	FTV1.erase(FTV1.begin(),FTV1.end());
	my::print(FTV1, name_FTV1);
std::cout << std::endl;
	std::cout << "STV1.swap(STV3): "<< std::endl;
	STV1.swap(STV3);
	my::print(STV1, name_STV1);
	my::print(STV3, name_STV3);
	std::cout << "STV1.swap(STV5): "<< std::endl;
	STV1.swap(STV5);
	my::print(STV1, name_STV1);
	my::print(STV5, name_STV5);
	std::cout << "FTV1.swap(FTV3): "<< std::endl;
	FTV1.swap(FTV3);
	my::print(FTV1, name_FTV1);
	my::print(FTV3, name_FTV3);
	std::cout << "FTV1.swap(FTV5): "<< std::endl;
	FTV1.swap(FTV5);
	my::print(FTV1, name_FTV1);
	my::print(FTV5, name_FTV5);
std::cout << Color::yellow << "Relational Operators" << Color::clean << std::endl;
	STV5.push_back(420.69);
	STV5.push_back(420.69);
	my::print(STV1, name_STV1);
	my::print(STV5, name_STV5);
	my::print(STV4, name_STV4);
	std::cout << std::endl;
	FTV5.push_back(420.69);
	FTV5.push_back(420.69);
	my::print(FTV1, name_FTV1);
	my::print(FTV5, name_FTV5);
	my::print(FTV4, name_FTV4);
	std::cout << "STV5 == STV4: ";
	std::cout << std::boolalpha << (STV5 == STV4);
	std::cout << std::endl;
	std::cout << "STV4 < STV1: ";
	std::cout << std::boolalpha << (STV4 < STV1);
	std::cout << std::endl;
	std::cout << "STV4 > STV1: ";
	std::cout << std::boolalpha << (STV4 > STV1);
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "FTV5 == FTV4: ";
	std::cout << std::boolalpha << (FTV5 == FTV4);
	std::cout << std::endl;
	std::cout << "FTV4 < FTV1: ";
	std::cout << std::boolalpha << (FTV4 < FTV1);
	std::cout << std::endl;
	std::cout << "FTV4 > FTV1: ";
	std::cout << std::boolalpha << (FTV4 > FTV1);
	std::cout << std::endl;
}
