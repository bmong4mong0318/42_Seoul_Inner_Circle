/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 13:16:23 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 14:24:31 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{	
	size_t			i;
	size_t			length;
	char			*tmp;

	i = 0;
	length = ft_strlen(s1);
	tmp = malloc(length * sizeof(char) + 1);
	if (tmp == 0)
	{
		return (0);
	}
	while (i < length)
	{
		tmp[i] = s1[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}
