/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:08 by dayun             #+#    #+#             */
/*   Updated: 2022/09/23 14:08:10 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

char	*ft_format_i(char *buf, va_list ap, t_tag *tag)
{
	tag->flags |= SIGN;
	buf = fill_num(buf, va_arg(ap, int), tag);
	if (!buf)
		return (0);
	return (buf);
}

char	*ft_format_u(char *buf, va_list ap, t_tag *tag)
{
	buf = fill_num(buf, va_arg(ap, unsigned int), tag);
	if (!buf)
		return (0);
	return (buf);
}

char	*ft_format_lowerx(char *buf, va_list ap, t_tag *tag)
{
	tag->base = 16;
	tag->flags |= SMALL;
	buf = fill_hex(buf, va_arg(ap, unsigned int), tag);
	if (!buf)
		return (0);
	return (buf);
}

char	*ft_format_upperx(char *buf, va_list ap, t_tag *tag)
{
	tag->base = 16;
	buf = fill_hex(buf, va_arg(ap, unsigned int), tag);
	if (!buf)
		return (0);
	return (buf);
}
