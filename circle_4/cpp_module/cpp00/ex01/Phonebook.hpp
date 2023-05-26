/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:25 by dayun             #+#    #+#             */
/*   Updated: 2023/05/08 13:34:34 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H_
#define PHONEBOOK_H_

#include "Contact.hpp"
#include <string>

class PhoneBook
{
private:
  Contact contact[8];
  Contact CreateContact();
  void DisplaySearchList(std::string contactInfo);
  void DisplayContact();
  void ValidateInputIndex(std::string inputIndex);
  int idx;

public:
  PhoneBook();
  ~PhoneBook();
  void AddContact();
  void SearchContact();
};

#endif