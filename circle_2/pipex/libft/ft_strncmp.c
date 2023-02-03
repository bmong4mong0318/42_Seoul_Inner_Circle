/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:33:23 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 11:38:15 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char	*str1, const char	*str2, size_t n)
{	
	size_t			i;
	unsigned char	*new_str1;
	unsigned char	*new_str2;

	i = 0;
	if (n == 0)
	{
		return (0);
	}
	if (str1 == 0 && str2 == 0)
	{
		return (0);
	}
	new_str1 = (unsigned char *)str1;
	new_str2 = (unsigned char *)str2;
	while ((new_str1[i] != 0 || new_str2[i] != 0) && i < n)
	{
		if (new_str1[i] != new_str2[i])
		{
			return (new_str1[i] - new_str2[i]);
		}
		i++;
	}
	return (0);
}
