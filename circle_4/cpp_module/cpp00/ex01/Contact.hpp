/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 13:34:05 by dayun             #+#    #+#             */
/*   Updated: 2023/05/08 13:34:06 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_H_
#define CONTACT_H_

#include <iostream>

class Contact
{
private:
  std::string firstName;
  std::string lastName;
  std::string nickName;
  std::string phoneNumber;
  std::string darkestSecret;

public:
  Contact();
  ~Contact();
  Contact(
      std::string firstName,
      std::string lastName,
      std::string nickName,
      std::string phoneNumber,
      std::string darkestSecret);
  std::string GetFirstName();
  std::string GetLastName();
  std::string GetNickName();
  std::string GetPhoneNumber();
  std::string GetDarkestSecret();
};

#endif
