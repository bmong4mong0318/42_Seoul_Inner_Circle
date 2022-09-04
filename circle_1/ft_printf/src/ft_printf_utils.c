/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:23:06 by dayun             #+#    #+#             */
/*   Updated: 2022/09/04 18:21:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_strnlen(const char *s, t_tag *tag)
{
	int		i;
	size_t	len;

	len = tag->precision;
	if (s == 0)
		return (0);
	else
	{
		i = 0;
		while (s[i] && len--)
			i++;
		return (i);
	}
}

void	check_percent(char *str, t_tag *tag)
{
	if (str)
	{
		while (*str)
		{
			if (*str == '%')
				tag->flag_percent = 1;
			str++;
		}
	}
}

int	check_null_size(const char *s, t_tag *tag)
{
	int	i;

	i = tag->precision;
	if (tag->precision == 0)
		return (0);
	while (i < 6)
		i++;
	return (i);
}
