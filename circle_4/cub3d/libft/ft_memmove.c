/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:14 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:16 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char		*dest_temp;
	const unsigned char	*src_temp;

	if (len == 0)
		return (dest);
	if (dest == NULL && src == NULL)
		return (NULL);
	dest_temp = (unsigned char *)dest;
	src_temp = (unsigned char *)src;
	if (dest > src)
	{
		dest_temp += len - 1;
		src_temp += len - 1;
		while (len-- > 0)
			*(dest_temp--) = *(src_temp--);
	}
	else
	{
		while (len-- > 0)
			*(dest_temp++) = *(src_temp++);
	}
	return (dest);
}
