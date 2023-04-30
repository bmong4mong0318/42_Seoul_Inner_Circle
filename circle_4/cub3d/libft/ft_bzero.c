/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:50:29 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:50:30 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dest, size_t size)
{
	size_t			i;
	unsigned char	*temp;

	temp = (unsigned char *)dest;
	i = 0;
	while (i < size)
	{
		*(temp + i) = 0;
		i += 1;
	}
}
