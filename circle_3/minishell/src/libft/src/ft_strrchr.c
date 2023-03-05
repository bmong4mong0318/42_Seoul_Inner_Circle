/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:37:29 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:37:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	size_t	size;

	size = 0;
	while (*s)
	{
		s++;
		size++;
	}
	if (size == 0 && c == 0)
		return ((char *)s);
	while (size > 0)
	{
		if (*s == (char)c)
			return ((char *)s);
		s--;
		size--;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
