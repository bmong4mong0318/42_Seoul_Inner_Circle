/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:15 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:18 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *src, int c)
{
	char	temp;
	char	*find;
	size_t	src_len;
	size_t	i;

	temp = (char) c;
	find = NULL;
	src_len = ft_strlen(src);
	i = 0;
	while (i <= src_len)
	{
		if (*(src + i) == temp)
			find = (char *)src + i;
		i += 1;
	}
	return (find);
}
