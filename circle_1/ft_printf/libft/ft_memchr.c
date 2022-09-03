/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 20:15:13 by dayun             #+#    #+#             */
/*   Updated: 2022/07/19 15:16:42 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t size)
{
	unsigned char	*ns;

	ns = (unsigned char *)s;
	if (size == 0)
		return (0);
	while (size--)
	{
		if (*ns == (unsigned char)c)
			return ((void *)ns);
		ns++;
	}
	return (0);
}
