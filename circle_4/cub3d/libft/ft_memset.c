/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:19 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *ptr, int c, size_t len)
{
	size_t			i;
	unsigned char	*temp;

	i = 0;
	temp = (unsigned char *)ptr;
	while (i < len)
	{
		temp[i] = (unsigned char)c;
		i += 1;
	}
	return (temp);
}
