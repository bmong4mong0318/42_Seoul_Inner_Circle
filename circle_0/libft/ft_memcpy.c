/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 17:02:09 by dayun             #+#    #+#             */
/*   Updated: 2022/07/18 11:06:11 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;

	if (!dst && !src)
		return (0);
	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	while (len--)
		*ndst++ = *nsrc++;
	return (dst);
}
