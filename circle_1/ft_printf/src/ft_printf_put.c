/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_put.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 20:23:33 by dayun             #+#    #+#             */
/*   Updated: 2022/09/04 17:51:15 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

size_t	ft_putstr(const char *s, t_tag *tag)
{
	int					i;
	const char			*from;
	static const char	*null_str = "(null)";

	if (s == 0)
	{
		i = 0;
		while (tag->precision && i < 6)
		{
			write(1, &null_str[i++], 1);
			tag->cnt++;
			tag->precision--;
			tag->field_width--;
		}
		return (0);
	}
	from = s;
	if (tag->flag_percent == 1)
		while (*s && tag->prec_len--)
			s++;
	else if (tag->flag_putstr)
	{
		while (*s && tag->prec_len)
		{
			s++;
			tag->prec_len--;
		}
		tag->flag_putstr = 0;
	}		
	else
		while (*s != '%' && *s && tag->prec_len--)
			s++;
	write(1, from, s - from);
	tag->cnt += s - from;
	tag->field_width -= s - from;
	return (s - from);
}

void	ft_putnbr_int(int n, t_tag *tag)
{
	if (n == -2147483648)
	{
		ft_putnbr_int(-214748364, tag);
		ft_putnbr_int('8', tag);
	}
	else if (n < 0)
	{
		ft_putchar_int('-', tag);
		ft_putnbr_int(-n, tag);
	}
	else
	{
		if (n >= 0)
			ft_putnbr_int(n / 10, tag);
		ft_putchar_int(n % 10 + '0', tag);
	}
}

void	ft_putchar_int(char c, t_tag *tag)
{
	write(1, &c, 1);
	tag->cnt++;
	tag->field_width--;
}

void	ft_putnbr_uint(unsigned int n, t_tag *tag)
{
	if (n >= 10)
		ft_putnbr_uint(n / 10, tag);
	ft_putchar_int(n % 10 + '0', tag);
}
