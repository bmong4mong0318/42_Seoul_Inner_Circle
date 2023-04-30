/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:11 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:13 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *small, size_t len)
{
	size_t	i;
	size_t	cnt;
	size_t	small_len;

	small_len = ft_strlen((char *)small);
	if (small_len == 0)
		return ((char *)(big));
	i = 0;
	cnt = 0;
	while (i < len && *(big + i) != '\0')
	{
		while (*(big + i + cnt) == *(small + cnt) && *(big + i + cnt) != '\0')
		{
			if (i + cnt == len)
				break ;
			cnt += 1;
		}	
		if (cnt == small_len)
			break ;
		i += 1;
		cnt = 0;
	}
	if (cnt != small_len)
		return (NULL);
	return ((char *)(big + i));
}
