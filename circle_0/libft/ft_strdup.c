/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 20:55:58 by dayun             #+#    #+#             */
/*   Updated: 2022/07/19 14:47:39 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	int		len;
	char	*arr;

	i = 0;
	len = ft_strlen(s1);
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (0);
	while (s1 && s1[i])
	{
		arr[i] = s1[i];
		i++;
	}
	arr[i] = 0;
	return (arr);
}
