/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 15:26:18 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 15:26:49 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

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
