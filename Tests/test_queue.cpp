/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 13:37:24 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/17 13:41:44 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Queue/queue.hpp"
#include <queue>

void test_queue(void)
{
	std::cout << Color::bold << Color::red << "LIST TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Coplien and Constructors" << Color::clean << std::endl;
	std::queue<int> STL1; std::string name_STL1 = "STL1";
	ft::queue<int> FTL1; std::string name_FTL1 = "FTL1";
	std::cout << "empty constructor for STL1, FTL1." << std::endl;
	std::queue<float, std::list<float> > STL2(std::list<float>(1, 420.69));
	std::string name_STL2 = "STL2";
	ft::queue<float, ft::list<float> > FTL2(ft::list<float>(1, 420.69));
	std::string name_FTL2 = "FTL2";
	std::cout << "Constructor with list<float>(1, 420.69) for STL2, FTL2." << std::endl;
	std::cout << Color::yellow << "Capacity Member Functions" << Color::clean << std::endl;
	std::cout << "Queue " << Color::blue << "STL1.empty(): "<<Color::clean << std::boolalpha << STL1.empty() << std::endl;
	std::cout << "Queue " << Color::green << "FTL1.empty(): "<<Color::clean << std::boolalpha << FTL1.empty() << std::endl;
	std::cout << "Queue " << Color::blue << "STL2.size(): "<<Color::clean << STL2.size() << std::endl;
	std::cout << "Queue " << Color::green << "FTL2.size(): " <<Color::clean<< FTL2.size() << std::endl;
	std::cout << Color::yellow << "Access Member Functions" << Color::clean << std::endl;
	std::cout << "Queue" << Color::blue <<" STL2.front(): "<<Color::clean << STL2.front() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.front(): "<<Color::clean << FTL2.front() << std::endl;
	std::cout << "Queue" << Color::blue <<" STL2.back(): "<<Color::clean << STL2.back() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.back(): "<<Color::clean << FTL2.back() << std::endl;
	std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "Queue STL2.push(3.14)" << std::endl;
	STL2.push(3.14);
	std::cout << "Queue FTL2.push(3.14)" << std::endl;
	FTL2.push(3.14);
	std::cout << "Queue" << Color::blue <<" STL2.front(): "<<Color::clean << STL2.front() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.front(): "<<Color::clean << FTL2.front() << std::endl;
	std::cout << "Queue" << Color::blue <<" STL2.back(): "<<Color::clean << STL2.back() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.back(): "<<Color::clean << FTL2.back() << std::endl;
	std::cout << std::endl;
	std::cout << "Queue STL2.pop()" << std::endl;
	STL2.pop();
	std::cout << "Queue FTL2.pop()" << std::endl;
	FTL2.pop();
	std::cout << "Queue" << Color::blue <<" STL2.front(): "<<Color::clean << STL2.front() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.front(): "<<Color::clean << FTL2.front() << std::endl;
	std::cout << "Queue" << Color::blue <<" STL2.back(): "<<Color::clean << STL2.back() << std::endl;
	std::cout << "Queue" << Color::green <<" FTL2.back(): "<<Color::clean << FTL2.back() << std::endl;
}
