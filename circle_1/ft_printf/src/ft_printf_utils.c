/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:23:06 by dayun             #+#    #+#             */
/*   Updated: 2022/09/08 20:16:09 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	do_div(long long *n, int base)
{
	int	res;

	res = *n % base;
	*n /= base;
	return (res);
}

int	do_div_hex(unsigned long *n, int base)
{
	int	res;

	res = *n % base;
	*n /= base;
	return (res);
}

size_t	ft_strnlen(const char *s, t_tag *tag)
{
	int		i;
	size_t	len;

	i = 0;
	len = tag->precision;
	if (tag->flag_dot == 0)
	{
		while (s[i])
			i++;
		return (i);
	}
	else
	{
		while (s[i] && len--)
			i++;
		return (i);
	}
}

int	check_null_size(const char *s, t_tag *tag)
{
	int	i;

	i = 0;
	if (tag->flag_dot == 0)
		return (6);
	while (i < tag->precision && i < 6)
		i++;
	return (i);
}
