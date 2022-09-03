/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:07:15 by dayun             #+#    #+#             */
/*   Updated: 2022/07/14 21:47:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcpy(char *dest, const char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = 0;
}

char	*ft_strjoin(char const *s1, char const *s2)
{	
	int		total_len;
	char	*final_str;
	char	*tmp;

	if (!s1 || !s2)
		return (0);
	total_len = ft_strlen(s1) + ft_strlen(s2);
	final_str = (char *)malloc(sizeof(char) * total_len + 1);
	if (!final_str)
		return (0);
	tmp = final_str;
	ft_strcpy(tmp, s1);
	tmp += ft_strlen(s1);
	ft_strcpy(tmp, s2);
	return (final_str);
}
