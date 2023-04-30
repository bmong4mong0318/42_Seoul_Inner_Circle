/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:53:20 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:53:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *src, int c)
{
	char	temp;
	char	*find;
	size_t	i;
	size_t	src_len;

	temp = (char) c;
	find = NULL;
	i = 0;
	src_len = ft_strlen(src);
	while (i <= src_len)
	{
		if (*(src + i) == temp)
		{
			find = (char *)(src + i);
			break ;
		}
		i += 1;
	}
	return (find);
}
