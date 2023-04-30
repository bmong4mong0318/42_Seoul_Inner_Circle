/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:53:53 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:53:55 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dest, const char	*src, size_t destsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (src_len + 1 < destsize)
		ft_memcpy(dest, src, src_len + 1);
	else if (destsize != 0)
	{
		ft_memcpy(dest, src, destsize - 1);
		*(dest + destsize - 1) = '\0';
	}
	return (src_len);
}
