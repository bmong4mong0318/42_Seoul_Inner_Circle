/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 14:43:15 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:32:23 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*ndst;
	unsigned char	*nsrc;

	if (!dst && !src)
		return (0);
	ndst = (unsigned char *)dst;
	nsrc = (unsigned char *)src;
	while (len--)
		*ndst++ = *nsrc++;
	return (dst);
}

int	word_count(const char *str, char c)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (*str != c)
			cnt++;
		while (*str != c && *str)
			str++;
		while (*str == c && *str)
			str++;
	}
	return (cnt);
}

int	ft_free(char **str, int i)
{
	while (i--)
		free(str[i]);
	free(str);
	return (-1);
}

int	word_put(char **answer, char const *str, char c)
{
	int			i;
	char const	*tmp;

	i = 0;
	while (*str)
	{
		if (*str != c)
		{
			tmp = str;
			while (*str != c && *str)
				str++;
			answer[i] = (char *)malloc(ft_strlen(tmp) - ft_strlen(str) + 1);
			if (!answer[i])
				return (ft_free(answer, i));
			ft_memcpy(answer[i], tmp, ft_strlen(tmp) - ft_strlen(str));
			answer[i][ft_strlen(tmp) - ft_strlen(str)] = 0;
			i++;
			if (!*str)
				break ;
		}
		str++;
	}
	return (i);
}

char	**ft_split(char const *str, char c)
{
	int		i;
	char	**answer;

	if (!str)
		return (0);
	answer = (char **)malloc(sizeof(char *) * ((word_count(str, c) + 1)));
	if (!answer)
		return (0);
	i = word_put(answer, str, c);
	if (i == -1)
		return (0);
	answer[i] = 0;
	return (answer);
}
