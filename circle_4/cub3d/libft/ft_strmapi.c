/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:02 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:04 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	size_t			size;
	char			*ptr;

	i = 0;
	if (!s || !f)
		return (NULL);
	size = ft_strlen(s);
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	while (*(s + i) != '\0')
	{
		*(ptr + i) = f(i, *(s + i));
		i += 1;
	}
	*(ptr + i) = '\0';
	return (ptr);
}
