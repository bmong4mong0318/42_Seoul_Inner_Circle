/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:34:18 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:34:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*s_uchar;

	s_uchar = (unsigned char *)s;
	while (n > 0)
	{
		if (*s_uchar == (unsigned char)c)
			return ((void *)s_uchar);
		--n;
		++s_uchar;
	}
	return (0);
}
