/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:50:19 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 16:01:28 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_num(char *buf, long long num, t_tag *tag)
{
	char				tmp[100];
	static const char	*digits = "0123456789ABCDEF";

	tag->size = tag->field_width;
	tag->prec = tag->precision;
	tag->locase = (tag->flags & SMALL);
	if (num == 0)
		tag->flag_num = 1;
	if (tag->flags & LEFT)
		tag->flags &= ~ZEROPAD;
	if (tag->flags & SIGN)
		num = fill_sign(num, tag);
	if ((tag->flags & SPECIAL) && !(tag->flag_num && (tag->flags & LEFT)))
		tag->size -= 2;
	if (num == 0 && (tag->prec || !tag->flag_dot))
		tmp[tag->base_len++] = '0';
	else
		while (num != 0)
			tmp[tag->base_len++] = (digits[do_div(&num, tag->base)]
					| tag->locase);
	if (tag->base_len > tag->prec)
		tag->prec = tag->base_len;
	tag->size -= tag->prec;
	return (fill_num2(buf, tag, tmp));
}

char	*fill_num2(char *buf, t_tag *tag, char *tmp)
{
	if (!(tag->flags & (ZEROPAD + LEFT)))
	{
		while (tag->size-- > 0)
		{
			buf = fill_buf(buf, ' ', tag);
			if (!buf)
				return (0);
		}
	}	
	if (tag->sign)
	{
		buf = fill_buf(buf, tag->sign, tag);
		if (!buf)
			return (0);
	}
	buf = fill_special(buf, tag);
	return (fill_num3(buf, tag, tmp));
}

char	*fill_num3(char *buf, t_tag *tag, char *tmp)
{
	if (!(tag->flags & LEFT))
	{
		while (tag->size-- > 0)
		{
			if (tag->flags & ZEROPAD)
			{
				buf = fill_buf(buf, '0', tag);
				if (!buf)
					return (0);
			}
			else
			{
				buf = fill_buf(buf, ' ', tag);
				if (!buf)
					return (0);
			}
		}
	}
	return (fill_num4(buf, tag, tmp));
}

char	*fill_num4(char *buf, t_tag *tag, char *tmp)
{
	while (tag->base_len < tag->prec--)
	{
		buf = fill_buf(buf, '0', tag);
		if (!buf)
			return (0);
	}
	while (tag->base_len-- > 0)
	{
		buf = fill_buf(buf, tmp[tag->base_len], tag);
		if (!buf)
			return (0);
	}
	while (tag->size-- > 0)
	{
		buf = fill_buf(buf, ' ', tag);
		if (!buf)
			return (0);
	}
	return (buf);
}
