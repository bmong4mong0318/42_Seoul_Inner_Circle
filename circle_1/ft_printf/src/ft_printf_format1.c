/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:43:55 by dayun             #+#    #+#             */
/*   Updated: 2022/09/08 20:01:57 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h" 

char	*ft_format_c(char *buf, va_list ap, t_tag *tag)
{
	char	c;

	c = va_arg(ap, int);
	if (!(tag->flags & LEFT))
	{
		while (--tag->field_width > 0)
			*buf++ = ' ';
	}
	*buf++ = c;
	while (--tag->field_width > 0)
		*buf++ = ' ';
	return (buf);
}

char	*ft_format_s(char *buf, va_list ap, t_tag *tag)
{
	int		i;
	char	*str;
	int		len;

	str = va_arg(ap, char *);
	if (str == NULL)
		len = check_null_size(str, tag);
	else
		len = ft_strnlen(str, tag);
	if (str == NULL)
		str = "(null)";
	if (!(tag->flags & LEFT))
		while (len < tag->field_width--)
			*buf++ = ' ';
	i = -1;
	while (++i < len)
		*buf++ = *str++;
	while (len < tag->field_width--)
		*buf++ = ' ';
	return (buf);
}

char	*ft_format_p(char *buf, va_list ap, t_tag *tag)
{
	tag->base = 16;
	tag->flags |= SMALL;
	tag->flag_p = 1;
	buf = fill_hex(buf, va_arg(ap, unsigned long), tag);
	return (buf);
}

char	*ft_format_d(char *buf, va_list ap, t_tag *tag)
{
	tag->flags |= SIGN;
	buf = fill_num(buf, va_arg(ap, int), tag);
	return (buf);
}
