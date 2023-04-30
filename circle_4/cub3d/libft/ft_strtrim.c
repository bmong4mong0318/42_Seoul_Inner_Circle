/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:21 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:23 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	front;
	size_t	back;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	front = 0;
	back = ft_strlen(s1);
	while (*(s1 + front) && ft_strchr(set, *(s1 + front)) != NULL)
		front += 1;
	while (*(s1 + back - 1) && ft_strchr(set, *(s1 + back - 1)) != NULL)
	{
		if (back - 1 == 0)
			break ;
		back -= 1;
	}
	if (front > back)
		return (ft_strdup(""));
	ptr = (char *)malloc(sizeof(char) * (back - front + 1));
	if (ptr == NULL)
		return (NULL);
	ft_strlcpy(ptr, s1 + front, back - front + 1);
	return (ptr);
}
