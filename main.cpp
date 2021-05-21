/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:06:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/21 13:48:32 by alejandro        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

namespace Color
{
	class Modifier
	{
		std::string	color_code;
		public:
			Modifier(std::string code) : color_code(code) {}
			std::string	getColorCode(void) const { return (this->color_code);}
			void setColorCode(std::string code) { this->color_code = code;}
	};
	std::ostream &operator<<(std::ostream &os, const Modifier &mod)
	{
		return (os << "\033[" << mod.getColorCode() << "m");
	}
	Modifier clean("0");
	Modifier red("31");
	Modifier yellow("93");
	Modifier blue("96");
	Modifier green("32");
	Modifier bold("1");
	Modifier def("39");
};

#include "Tests/test_list.cpp"
#include "Tests/test_vector.cpp"
#include "Tests/test_stack.cpp"
#include "Tests/test_queue.cpp"
#include "Tests/test_map.cpp"

int main (int argc, char **argv)
{
	if (argc != 2)
	{
		test_list();
		test_vector();
		test_map();
		test_stack();
		test_queue();
	}
	else if (!strcmp(argv[1], "list"))
		test_list();
	else if (!strcmp(argv[1], "vector"))
		test_vector();
	else if (!strcmp(argv[1], "stack"))
		test_stack();
	else if (!strcmp(argv[1], "queue"))
		test_queue();
	else if (!strcmp(argv[1], "map"))
		test_map();
	else if (!strcmp(argv[1], "all"))
	{
		test_list();
		test_vector();
		test_map();
		test_stack();
		test_queue();
	}
	return (0);
}
