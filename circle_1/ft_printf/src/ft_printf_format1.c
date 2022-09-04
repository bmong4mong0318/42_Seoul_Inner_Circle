/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:43:55 by dayun             #+#    #+#             */
/*   Updated: 2022/09/03 17:27:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_format_c(va_list ap, t_tag *tag)
{
	if (!(tag->flags & LEFT))
	{
		while (--tag->field_width > 0)
		{
			write(1, " ", 1);
			tag->cnt += 1;
		}
	}
	ft_putchar_fd(va_arg(ap, int), 1);
	tag->cnt++;
	while (--tag->field_width > 0)
	{
		write(1, " ", 1);
		tag->cnt += 1;
	}
}

void	ft_format_s(va_list ap, t_tag *tag)
{
	char	*str;

	str = va_arg(ap, char *);
	tag->prec_len = ft_strnlen(str, tag);
	if (str == 0 && (tag->flags & LEFT) && tag->precision <= 6)
		tag->field_width -= tag->precision;
	else if (str == 0 && (tag->flags & LEFT) && tag->precision > 6)
		tag->field_width -= (tag->precision - 5);
	if (str == 0 && tag->field_width <= 6
		&& tag->precision && !(tag->flags & LEFT))
		tag->field_width = 0;
	else if (str == 0 && tag->flag_width && !tag->flag_prec)
		tag->field_width -= 6;
	else if (str == 0 && tag->field_width > 6 && tag->precision <= 6)
		tag->field_width -= tag->precision;
	else if (str == 0 && tag->field_width > 6 && tag->precision > 6)
		tag->field_width -= 6;
	if (!(tag->flags & LEFT))
	{
		while (tag->prec_len < tag->field_width--)
		{
			write(1, " ", 1);
			tag->cnt++;
		}
	}
	check_percent(str, tag);
	tag->flag_putstr = 1;
	ft_putstr(str, tag);
	while (tag->prec_len < tag->field_width--)
	{
		write(1, " ", 1);
		tag->cnt++;
	}
}

void	ft_format_p(va_list ap, t_tag *tag)
{
	unsigned long	pnum;

	tag->base = 16;
	tag->flags |= SMALL;
	pnum = (unsigned long)va_arg(ap, void *);
	if (!(tag-> flags & LEFT) && pnum == 0)
	{
		while (tag->field_width-- > 3)
		{
			write(1, " ", 1);
			tag->cnt++;
		}
	}
	else if (!(tag->flags & LEFT))
	{
		while (tag->field_width-- > 14)
		{
			write(1, " ", 1);
			tag->cnt++;
		}
	}
	write(1, "0x", 2);
	tag->cnt += 2;
	tag->field_width -= 2;
	ft_put_ptr(pnum, tag);
	tag->field_width -= 16;
	while (--tag->field_width > 0)
	{
		write(1, " ", 1);
		tag->cnt++;
	}
}

void	ft_format_d(va_list ap, t_tag *tag)
{
	ft_put_num(va_arg(ap, int), tag);
}
