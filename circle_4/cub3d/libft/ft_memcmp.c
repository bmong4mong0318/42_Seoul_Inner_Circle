/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:04 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:05 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				result;
	size_t			i;
	unsigned char	*s1_temp;
	unsigned char	*s2_temp;

	if (n == 0)
		return (0);
	i = 0;
	result = 0;
	s1_temp = (unsigned char *)s1;
	s2_temp = (unsigned char *)s2;
	while (i < n)
	{
		if (*(s1_temp + i) != *(s2_temp + i))
		{
			result = ((int)*(s1_temp + i) - *(s2_temp + i));
			break ;
		}
		i += 1;
	}
	return (result);
}
