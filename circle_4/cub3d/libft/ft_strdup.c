/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:53:30 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:53:33 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	size_t	i;
	size_t	src_len;
	char	*ptr;

	i = 0;
	src_len = ft_strlen(src);
	if (src_len == 0)
		return (NULL);
	ptr = (char *)malloc((src_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (*(src + i) != '\0')
	{
		*(ptr + i) = *(src + i);
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
