/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 15:04:10 by dayun             #+#    #+#             */
/*   Updated: 2022/07/16 17:27:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int			len;
	char const	*start;
	char const	*end;
	char		*final_str;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = s1;
	while (ft_strchr(set, *start) && *start)
		start++;
	end = s1 + ft_strlen(s1) - 1;
	while (ft_strchr(set, *end) && end > start)
		end--;
	len = (end - start) / sizeof(char) + 1;
	final_str = (char *)malloc(sizeof(char) * len + 1);
	if (!final_str)
		return (0);
	ft_strlcpy(final_str, start, len + 1);
	return (final_str);
}
