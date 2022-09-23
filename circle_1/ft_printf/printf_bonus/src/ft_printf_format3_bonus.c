/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 14:06:55 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 16:26:48 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

char	*ft_format_percent(char *buf, va_list ap, t_tag *tag)
{
	(void)ap;
	tag->size = tag->field_width - 1;
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
	return (ft_format_percent2(buf, ap, tag));
}

char	*ft_format_percent2(char *buf, va_list ap, t_tag *tag)
{
	(void)ap;
	buf = fill_buf(buf, '%', tag);
	if (!buf)
		return (0);
	while (tag->size-- > 0)
	{
		buf = fill_buf(buf, ' ', tag);
		if (!buf)
			return (0);
	}
	return (buf);
}

char	*fill_buf(char *buf, char c, t_tag *tag)
{
	tag->cnt++;
	if (tag->cnt > 100000)
		return (0);
	*buf++ = c;
	return (buf);
}

int	print_buf(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (write(1, str, 1) == -1)
			return (-1);
		str++;
		i++;
	}
	return (i);
}
