/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejandroleon <aleon-ca@student.42.fr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:51:48 by alejandro         #+#    #+#             */
/*   Updated: 2021/05/17 13:35:13 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Stack/stack.hpp"
#include <stack>

void test_stack(void)
{
	std::cout << Color::bold << Color::red << "LIST TESTS" << Color::clean << std::endl;
	std::cout << Color::yellow << "Coplien and Constructors" << Color::clean << std::endl;
	std::stack<int> STL1; std::string name_STL1 = "STL1";
	ft::stack<int> FTL1; std::string name_FTL1 = "FTL1";
	std::cout << "empty constructor for STL1, FTL1." << std::endl;
	std::stack<float, std::vector<float> > STL2(std::vector<float>(4, 420.69));
	std::string name_STL2 = "STL2";
	ft::stack<float, ft::vector<float> > FTL2(ft::vector<float>(4, 420.69));
	std::string name_FTL2 = "FTL2";
	std::cout << "Constructor with vector<float>(4, 420.69) for STL2, FTL2." << std::endl;
	std::cout << Color::yellow << "Capacity Member Functions" << Color::clean << std::endl;
	std::cout << "Stack " << Color::blue << "STL1.empty(): "<<Color::clean << std::boolalpha << STL1.empty() << std::endl;
	std::cout << "Stack " << Color::green << "FTL1.empty(): "<<Color::clean << std::boolalpha << FTL1.empty() << std::endl;
	std::cout << "Stack " << Color::blue << "STL2.size(): "<<Color::clean << STL2.size() << std::endl;
	std::cout << "Stack " << Color::green << "FTL2.size(): " <<Color::clean<< FTL2.size() << std::endl;
	std::cout << Color::yellow << "Access Member Functions" << Color::clean << std::endl;
	std::cout << "Stack" << Color::blue <<" STL2.top(): "<<Color::clean << STL2.top() << std::endl;
	std::cout << "Stack" << Color::green <<" FTL2.top(): "<<Color::clean << FTL2.top() << std::endl;
	std::cout << Color::yellow << "Modifier Member Functions" << Color::clean << std::endl;
	std::cout << "Stack STL2.push(3.14)" << std::endl;
	STL2.push(3.14);
	std::cout << "Stack FTL2.push(3.14)" << std::endl;
	FTL2.push(3.14);
	std::cout << "Stack" << Color::blue <<" STL2.top(): "<<Color::clean << STL2.top() << std::endl;
	std::cout << "Stack" << Color::green <<" FTL2.top(): "<<Color::clean << FTL2.top() << std::endl;
	std::cout << std::endl;
	std::cout << "Stack STL2.pop()" << std::endl;
	STL2.pop();
	std::cout << "Stack FTL2.pop()" << std::endl;
	FTL2.pop();
	std::cout << "Stack" << Color::blue <<" STL2.top(): "<<Color::clean << STL2.top() << std::endl;
	std::cout << "Stack" << Color::green <<" FTL2.top(): "<<Color::clean << FTL2.top() << std::endl;
}
