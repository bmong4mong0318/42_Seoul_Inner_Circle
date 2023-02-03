/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 17:14:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 11:15:28 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	unsigned char	*new_dest;
	unsigned char	*new_src;

	if (dest == 0 && src == 0)
	{
		return (0);
	}
	new_dest = (unsigned char *)dest;
	new_src = (unsigned char *)src;
	if (dest < src)
	{
		while (size--)
		{
			*new_dest++ = *new_src++;
		}
	}
	else
	{
		new_dest = (unsigned char *)dest + (size - 1);
		new_src = (unsigned char *)src + (size - 1);
		while (size--)
			*new_dest-- = *new_src--;
	}
	return (dest);
}
