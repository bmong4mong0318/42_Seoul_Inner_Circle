/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:20 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 16:26:42 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

char	*parse_spc(char *buf, va_list ap, const char *fmt, t_tag *tag)
{
	if (*fmt == 'c')
		buf = ft_format_c(buf, ap, tag);
	else if (*fmt == 's')
		buf = ft_format_s(buf, ap, tag);
	else if (*fmt == 'd')
		buf = ft_format_d(buf, ap, tag);
	else if (*fmt == 'i')
		buf = ft_format_i(buf, ap, tag);
	else if (*fmt == 'u')
		buf = ft_format_u(buf, ap, tag);
	else if (*fmt == 'p')
		buf = ft_format_p(buf, ap, tag);
	else if (*fmt == 'x')
		buf = ft_format_lowerx(buf, ap, tag);
	else if (*fmt == 'X')
		buf = ft_format_upperx(buf, ap, tag);
	else if (*fmt == '%')
		buf = ft_format_percent(buf, ap, tag);
	if (!buf)
		return (0);
	return (buf);
}

void	check_flags(va_list ap, const char *fmt, t_tag *tag)
{
	(void)ap;
	if (*fmt == '-')
		tag->flags |= LEFT;
	else if (*fmt == '+')
		tag->flags |= PLUS;
	else if (*fmt == ' ')
		tag->flags |= SPACE;
	else if (*fmt == '0' && !tag->flag_width)
		tag->flags |= ZEROPAD;
	else if (*fmt == '#')
		tag->flags |= SPECIAL;
	else if (ft_isdigit(*fmt) && tag->precision == -1)
	{
		tag->field_width = tag->field_width * 10 + *fmt - '0';
		tag->flag_width = 1;
	}
	else if (*fmt == '.')
	{
		tag->precision = 0;
		tag->flag_width = 1;
		tag->flag_dot = 1;
		tag->flags &= ~ZEROPAD;
	}
	else if (ft_isdigit(*fmt) && tag->precision != -1)
		tag->precision = tag->precision * 10 + *fmt - '0';
}

void	init_tag(t_tag *tag)
{
	tag->sign = 0;
	tag->flags = 0;
	tag->field_width = 0;
	tag->precision = -1;
	tag->flag_width = 0;
	tag->base = 10;
	tag->base_len = 0;
	tag->flag_num = 0;
	tag->flag_dot = 0;
	tag->flag_p = 0;
	tag->flag_c = 0;
}

int	parse_buf(char *buf, va_list ap, const char *fmt, t_tag *tag)
{
	while (*fmt)
	{
		if (*fmt == '%')
		{
			init_tag(tag);
			while (*++fmt && !ft_strchr(TYPE, *fmt))
				check_flags(ap, fmt, tag);
			if (tag->precision < 0)
				tag->precision = 0;
			buf = parse_spc(buf, ap, fmt, tag);
			if (!buf)
				return (-1);
		}
		else
		{
			buf = fill_buf(buf, *fmt, tag);
			if (!buf)
				return (-1);
		}
		fmt++;
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_tag	tag;
	char	buf[100000];

	va_start(ap, fmt);
	ft_memset(buf, 0, 100000);
	tag.cnt = 0;
	if (parse_buf(buf, ap, fmt, &tag) == -1)
		return (-1);
	va_end(ap);
	if (print_buf(buf, tag.cnt) == -1)
		return (-1);
	return (tag.cnt);
}
