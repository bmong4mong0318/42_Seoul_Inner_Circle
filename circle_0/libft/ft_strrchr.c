/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:10:26 by dayun             #+#    #+#             */
/*   Updated: 2022/07/13 19:40:51 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	len;

	len = ft_strlen((char *)str);
	str += len;
	while (len)
	{
		if (*str == (char)c)
			return ((char *)str);
		str--;
		len--;
	}
	if (*str == (char)c)
		return ((char *)str);
	if (c == 0)
		return ((char *)(str + len));
	return (0);
}
