/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:30:34 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:20:06 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	if (fd < 0)
		return ;
	while (*s)
	{
		write (fd, s, 1);
		s++;
	}
}

void	ft_error(void)
{	
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

static int	check_error(const char *s)
{
	if (!(*s == '-' || *s == '+') && !(*s >= '0' && *s <= '9')
		&& *s != 32 && !(*s >= 9 && *s <= 13))
		return (0);
	if ((*s == '-' || *s == '+') && !(*(s + 1) >= '0' && *(s + 1) <= '9'))
		return (0);
	return (1);
}

int	ft_atoi(const char *s)
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
