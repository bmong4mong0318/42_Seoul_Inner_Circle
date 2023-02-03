/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:29:05 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/16 16:52:27 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i] != 0)
	{
		free(str[i]);
		i++;
	}
	free(str[i]);
	return (0);
}

static char	**do_split(char **new_str, char const *s, char c, size_t count)
{
	size_t	i;
	size_t	j;
	size_t	next;

	i = 0;
	j = 0;
	while (s[i] != 0 && j < count)
	{
		if (s[i] != c)
		{
			next = i + 1;
			while (s[next] != 0 && s[next] != c)
				next++;
			new_str[j] = ft_substr(s, i, next - i);
			if (new_str[j] == 0)
				return (ft_free(new_str));
			j++;
			i = next;
		}
		else
			i++;
	}
	new_str[j] = 0;
	return (new_str);
}

char	**ft_split(char const *s, char c)
{
	char	**new_str;
	size_t	word_count;
	size_t	i;

	if (s == 0)
		return (NULL);
	i = 0;
	word_count = 0;
	while (s[i] != 0)
	{
		if (s[i] != c)
		{
			word_count++;
			while ((s[i] != c) && s[i] != 0)
				i++;
		}
		else
			i++;
	}
	new_str = malloc(sizeof(char *) * (word_count + 1));
	if (new_str == 0)
		return (0);
	do_split(new_str, s, c, word_count);
	return (new_str);
}
