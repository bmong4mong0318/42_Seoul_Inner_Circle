/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 14:44:07 by dayun             #+#    #+#             */
/*   Updated: 2022/07/19 14:59:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	slen;
	char	*arr;

	i = 0;
	slen = ft_strlen(s);
	if (!s)
		return (0);
	if (len > slen)
		len = slen;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	while (i < len && start + i < slen)
	{
		arr[i] = s[start + i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
