/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:09 by dayun             #+#    #+#             */
/*   Updated: 2023/05/08 13:55:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <iostream>
#include <string>

int main()
{
	PhoneBook phoneBook = PhoneBook();
	std::string command;

	std::cout << "My Awesome PhoneBook!" << std::endl;
	std::cout << "command> ";
	while (std::getline(std::cin, command))
	{
		if (command == "EXIT")
		{
			std::cout << "exit" << std::endl;
			break;
		}
		else if (command == "ADD")
		{
			phoneBook.AddContact();
			std::cout << "command> ";
		}
		else if (command == "SEARCH")
		{
			phoneBook.SearchContact();
			std::cout << "command> ";
		}
		else
		{
			std::cout << "Invalid input - Command\n\n";
			std::cout << "command> ";
		}
	}
	if (std::cin.eof())
	{
		std::cout << "Enter EOF. Program Exit." << std::endl;
		return (0);
	}

	return (0);
}
