/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:33:46 by dayun             #+#    #+#             */
/*   Updated: 2023/05/08 13:34:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(
	std::string firstName,
	std::string lastName,
	std::string nickName,
	std::string phoneNumber,
	std::string darkestSecret)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->nickName = nickName;
	this->phoneNumber = phoneNumber;
	this->darkestSecret = darkestSecret;
}

Contact::Contact()
{
	*this = Contact("", "", "", "", "");
}

Contact::~Contact()
{
}

std::string Contact::GetFirstName()
{
	return this->firstName;
}

std::string Contact::GetLastName()
{
	return this->lastName;
}

std::string Contact::GetNickName()
{
	return this->nickName;
}

std::string Contact::GetPhoneNumber()
{
	return this->phoneNumber;
}

std::string Contact::GetDarkestSecret()
{
	return this->darkestSecret;
}
