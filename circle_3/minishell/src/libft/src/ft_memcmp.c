/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:34:24 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:34:27 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_uchar;
	const unsigned char	*s2_uchar;

	s1_uchar = (const unsigned char *)s1;
	s2_uchar = (const unsigned char *)s2;
	while ((n > 0) && (*s1_uchar == *s2_uchar))
	{
		++s1_uchar;
		++s2_uchar;
		--n;
	}
	if (n == 0)
		return (0);
	else
		return ((int)*s1_uchar - (int)*s2_uchar);
}
