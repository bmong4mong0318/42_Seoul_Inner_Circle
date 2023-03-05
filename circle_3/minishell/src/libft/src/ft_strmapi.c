/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:37:15 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:37:17 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

extern size_t	ft_strlen(const char *str);

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*pa_result;
	size_t			len;
	unsigned int	i;

	len = ft_strlen(s);
	pa_result = malloc(sizeof(*pa_result) * (len + 1));
	if (!pa_result)
		return (NULL);
	i = 0;
	while ((size_t)i < len)
	{
		pa_result[i] = f(i, s[i]);
		i++;
	}
	pa_result[len] = '\0';
	return (pa_result);
}
