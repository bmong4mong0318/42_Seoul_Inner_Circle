/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:51:59 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:01 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*find;
	unsigned char	*src_temp;
	unsigned char	temp;

	if (n == 0)
		return (NULL);
	i = 0;
	find = NULL;
	src_temp = (unsigned char *)src;
	temp = (unsigned char)c;
	while (i < n)
	{
		if (*(src_temp + i) == temp)
		{
			find = (src_temp + i);
			break ;
		}
		i += 1;
	}
	return (find);
}
