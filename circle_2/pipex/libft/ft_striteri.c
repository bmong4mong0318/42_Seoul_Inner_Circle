/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:01:16 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 12:23:04 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	size_t	length;
	size_t	i;

	i = 0;
	if (s == 0 || f == 0)
	{
		return ;
	}
	length = ft_strlen(s);
	while (i < length)
	{
		f(i, &s[i]);
		i++;
	}
}
