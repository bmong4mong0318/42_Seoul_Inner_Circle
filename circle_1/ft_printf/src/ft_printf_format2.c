/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_format2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:08 by dayun             #+#    #+#             */
/*   Updated: 2022/09/03 19:33:53 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_format_i(va_list ap, t_tag *tag)
{
	ft_put_num(va_arg(ap, int), tag);
}

void	ft_format_u(va_list ap, t_tag *tag)
{
	ft_put_num(va_arg(ap, unsigned int), tag);
}

void	ft_format_lowerx(va_list ap, t_tag *tag)
{
	tag->base = 16;
	tag->flags |= SMALL;
	ft_put_num(va_arg(ap, unsigned long), tag);
}

void	ft_format_upperx(va_list ap, t_tag *tag)
{
	tag->base = 16;
	ft_put_num(va_arg(ap, unsigned long), tag);
}

void	ft_format_percent(va_list ap, t_tag *tag)
{
	// int	width;

	(void)ap;
	// width = tag->field_width;
	// if (!(tag->flags & LEFT))
	// {
	// 	while (--width)
	// 	{
	// 		if (tag->flags & ZEROPAD)
	// 			ft_putchar_int('0', tag);
	// 		else if (!(tag->flags & ZEROPAD))
	// 			ft_putchar_int(' ', tag);
	// 	}
	// }
	ft_putchar_int('%', tag);
}
