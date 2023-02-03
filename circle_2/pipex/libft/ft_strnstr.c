/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:45:25 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/06 18:42:09 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *substr, size_t n)
{
	size_t			i;
	size_t			j;

	i = 0;
	if (*substr == 0)
	{
		return ((char *)str);
	}
	while (str[i] != 0 && i < n)
	{
		j = 0;
		while (str[i + j] == substr[j] && i + j < n)
		{
			j++;
			if (substr[j] == 0)
			{
				return ((char *)&str[i]);
			}
		}	
		i++;
	}
	return (0);
}
