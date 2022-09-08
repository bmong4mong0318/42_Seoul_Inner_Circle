/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:20 by dayun             #+#    #+#             */
/*   Updated: 2022/09/08 20:43:04 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static char	*parse_spc(char *buf, va_list ap, const char *fmt, t_tag *tag)
{
	if (*fmt == 'c')
		return (ft_format_c(buf, ap, tag));
	else if (*fmt == 's')
		return (ft_format_s(buf, ap, tag));
	else if (*fmt == 'd')
		return (ft_format_d(buf, ap, tag));
	else if (*fmt == 'i')
		return (ft_format_i(buf, ap, tag));
	else if (*fmt == 'u')
		return (ft_format_u(buf, ap, tag));
	else if (*fmt == 'p')
		return (ft_format_p(buf, ap, tag));
	else if (*fmt == 'x')
		return (ft_format_lowerx(buf, ap, tag));
	else if (*fmt == 'X')
		return (ft_format_upperx(buf, ap, tag));
	else if (*fmt == '%')
		return (ft_format_percent(buf, ap, tag));
	else
		return (0);
}

static void	check_flags(va_list ap, const char *fmt, t_tag *tag)
{
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

static void	init_tag(t_tag *tag)
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

static int	parse_buf(char *buf, va_list ap, const char *fmt, t_tag *tag)
{
	char	*tmp;

	tmp = buf;
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
		}
		else
			*buf++ = *fmt;
		fmt++;
	}
	*buf = '\0';
	return (buf - tmp);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_tag	tag;
	char	buf[1024];
	int		print_len;

	va_start(ap, fmt);
	ft_memset(buf, 0, 1024);
	print_len = parse_buf(buf, ap, fmt, &tag);
	va_end(ap);
	if (print_buf(buf, print_len) == -1)
		return (-1);
	return (print_len);
}
