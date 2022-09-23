/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:50:19 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 14:13:41 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*fill_hex(char *buf, unsigned long num, t_tag *tag)
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
	if ((tag->flags & SPECIAL) && !(tag->flag_num && (tag->flags & LEFT)))
		tag->size -= 2;
	if ((tag->flags & SPECIAL) && tag->flag_num && !(tag->flags & LEFT))
		tag->size += 2;
	if (num == 0 && (tag->prec || !tag->flag_dot))
		tmp[tag->base_len++] = '0';
	else
		while (num != 0)
			tmp[tag->base_len++] = (digits[do_div_hex(&num, tag->base)]
					| tag->locase);
	return (fill_hex2(buf, tag, tmp));
}

char	*fill_hex2(char *buf, t_tag *tag, char *tmp)
{
	if (tag->flag_p && tag->size >= tag->base_len + 2)
		tag->size -= 2;
	else if (tag->flag_p && tag->size < tag->base_len + 2)
	{
		if (tag->flag_num == 1)
			tag->size -= 1;
		tag->size -= 1;
	}
	if (tag->base_len > tag->prec)
		tag->prec = tag->base_len;
	tag->size -= tag->prec;
	if (!(tag->flags & (ZEROPAD + LEFT)))
	{
		while (tag->size-- > 0)
		{
			buf = fill_buf(buf, ' ', tag);
			if (!buf)
				return (0);
		}
	}
	return (fill_hex3(buf, tag, tmp));
}

char	*fill_hex3(char *buf, t_tag *tag, char *tmp)
{
	if (tag->sign)
	{
		buf = fill_buf(buf, tag->sign, tag);
		if (!buf)
			return (0);
	}
	buf = fill_special_hex(buf, tag);
	return (fill_hex4(buf, tag, tmp));
}

char	*fill_hex4(char *buf, t_tag *tag, char *tmp)
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
	while (tag->base_len < tag->prec--)
	{
		buf = fill_buf(buf, '0', tag);
		if (!buf)
			return (0);
	}
	return (fill_hex5(buf, tag, tmp));
}

char	*fill_hex5(char *buf, t_tag *tag, char *tmp)
{
	if (tag->flag_p)
	{
		buf = fill_buf(buf, '0', tag);
		if (!buf)
			return (0);
		buf = fill_buf(buf, 'x', tag);
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
