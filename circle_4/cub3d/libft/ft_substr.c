/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:27 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:29 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	get_ptr_size(size_t src_len, unsigned int start, size_t len)
{
	size_t	ptr_size;

	if (src_len - (start + 1) < len)
		ptr_size = src_len - (start + 1);
	else
		ptr_size = len;
	return (ptr_size);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			cnt;
	size_t			src_len;
	size_t			ptr_size;
	char			*ptr;

	if (s == NULL)
		return (NULL);
	src_len = ft_strlen(s);
	if (start >= src_len)
	{
		ptr = ft_strdup("");
		return (ptr);
	}
	ptr_size = get_ptr_size(src_len, start, len);
	ptr = (char *)malloc(sizeof(char) * (ptr_size + 1));
	if (ptr == NULL)
		return (NULL);
	i = start;
	cnt = 0;
	while (i < (unsigned int)src_len && cnt < len)
		*(ptr + cnt++) = *(s + i++);
	*(ptr + cnt) = '\0';
	return (ptr);
}
