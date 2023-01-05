/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:23:02 by dayun             #+#    #+#             */
/*   Updated: 2023/01/05 16:19:47 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_error(const char *s)
{
	if (!(*s == '-' || *s == '+') && !(*s >= '0' && *s <= '9')
		&& *s != 32 && !(*s >= 9 && *s <= 13))
		return (0);
	if ((*s == '-' || *s == '+') && !(*(s + 1) >= '0' && *(s + 1) <= '9'))
		return (0);
	return (1);
}

long	ft_atoi(const char *s)
{
	long	plma;
	long	ans;

	plma = 1;
	ans = 0;
	while (*s)
	{
		if (!check_error(s))
			return (0);
		if ((*s == '-') && (*(s + 1) >= '0' && *(s + 1) <= '9'))
				plma *= -1;
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
			{
				ans = ans * 10 + (*s++ - '0');
				if (ans < 0)
					return ((plma + 1) / (-2));
			}
			break ;
		}
		s++;
	}
	return (plma * ans);
}
