/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:23:15 by dayun             #+#    #+#             */
/*   Updated: 2022/07/18 11:06:41 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	j = 0;
	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dlen < len)
	{
		i = dlen;
		while (src[j] != 0 && j < len - dlen - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = 0;
	}
	else
		return (slen + len);
	return (dlen + slen);
}
