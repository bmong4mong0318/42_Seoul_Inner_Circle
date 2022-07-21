/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 19:24:20 by dayun             #+#    #+#             */
/*   Updated: 2022/07/18 12:06:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;

	if (!dst && !src)
		return (0);
	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	if (dst <= src)
	{
		while (len--)
			*ndst++ = *nsrc++;
	}
	else
	{
		ndst += len - 1;
		nsrc += len - 1;
		while (len--)
			*ndst-- = *nsrc--;
	}
	return (dst);
}
