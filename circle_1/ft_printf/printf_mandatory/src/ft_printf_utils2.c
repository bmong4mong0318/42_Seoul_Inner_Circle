/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 16:00:47 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 16:01:14 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

long long	fill_sign(long long num, t_tag *tag)
{
	if (num < 0)
	{
		tag->sign = '-';
		num = -num;
		tag->size--;
	}
	else if (tag->flags & PLUS)
	{
		tag->sign = '+';
		tag->size--;
	}
	else if (tag->flags & SPACE)
	{
		tag->sign = ' ';
		tag->size--;
	}
	return (num);
}

char	*fill_special(char *buf, t_tag *tag)
{
	if (tag->flags & SPECIAL)
	{
		if (tag->flag_num)
		{
			if (tag->flags & LEFT)
				return (buf);
			buf = fill_buf(buf, ' ', tag);
			if (!buf)
				return (0);
			buf = fill_buf(buf, ' ', tag);
			if (!buf)
				return (0);
		}
		else
		{
			buf = fill_buf(buf, '0', tag);
			if (!buf)
				return (0);
			buf = fill_buf(buf, ('X' | tag->locase), tag);
			if (!buf)
				return (0);
		}
	}
	return (buf);
}

char	*fill_special_hex(char *buf, t_tag *tag)
{
	if (tag->flags & SPECIAL)
	{
		if (tag->flag_num)
		{
			if (tag->flags & LEFT)
				return (buf);
		}
		else
		{
			buf = fill_buf(buf, '0', tag);
			if (!buf)
				return (0);
			buf = fill_buf(buf, ('X' | tag->locase), tag);
			if (!buf)
				return (0);
		}
	}
	return (buf);
}
