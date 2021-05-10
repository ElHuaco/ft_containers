/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleon-ca <aleon-ca@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 12:06:27 by aleon-ca          #+#    #+#             */
/*   Updated: 2021/05/10 10:16:27 by alejandro        ###   ########.fr       */
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

int main (int argc, char **argv)
{
	if (argc != 2)
	{	
		std::cout << "Enter a container name." << std::endl;
		return (0);
	}
	if (!strcmp(argv[1], "list"))
		test_list();
	return (0);
}
