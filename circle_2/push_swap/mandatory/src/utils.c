/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:30:34 by dayun             #+#    #+#             */
/*   Updated: 2023/01/11 16:10:24 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

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

static int	check_error_and_sign(const char *s, long *plma)
{
	if (!(*s == '-' || *s == '+') && !(*s >= '0' && *s <= '9')
		&& *s != 32 && !(*s >= 9 && *s <= 13))
		return (0);
	if ((*s == '-' || *s == '+') && !(*(s + 1) >= '0' && *(s + 1) <= '9'))
		return (0);
	if ((*s == '-') && (*(s + 1) >= '0' && *(s + 1) <= '9'))
		*plma *= -1;
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
		if (!check_error_and_sign(s, &plma))
			return (0);
		if (*s >= '0' && *s <= '9')
		{
			while (*s >= '0' && *s <= '9')
			{
				if (ans < -2147483648 || 2147483647 < ans)
					return (plma * ans);
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
