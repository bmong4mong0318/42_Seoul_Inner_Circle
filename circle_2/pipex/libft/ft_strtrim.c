/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 17:15:55 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 12:08:03 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	front;
	size_t	back;
	char	*new_str;

	new_str = 0;
	if (s1 != 0 && set != 0)
	{
		front = 0;
		back = ft_strlen(s1);
		while (s1[front] && ft_strchr(set, s1[front]))
			front++;
		while (s1[back - 1] && ft_strchr(set, s1[back - 1]) && back > front)
			back--;
		new_str = malloc(((back - front) * sizeof(char)) + 1);
	}
	if (new_str == 0)
		return (0);
	else
	{
		ft_strlcpy(new_str, &s1[front], (back - front + 1));
		return (new_str);
	}
}
