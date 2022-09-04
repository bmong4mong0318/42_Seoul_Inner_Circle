/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_ptr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 14:29:49 by dayun             #+#    #+#             */
/*   Updated: 2022/09/02 14:37:01 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	div_ptr(unsigned long *n, int base)
{
	int	res;

	res = *n % base;
	*n /= base;
	return (res);
}

void	ft_put_ptr(unsigned long num, t_tag	*tag)
{
	int					base;
	int					locase;
	char				tmp[100];
	static const char	*digits = "0123456789ABCDEF";

	locase = (tag->flags & SMALL);
	if (tag->flags & LEFT)
		tag->flags &= ~ZEROPAD;
	if (tag->flags & SPECIAL)
		tag->field_width -= 2;
	if (num < 0)
	{
		num = -num;
		tag->flags |= SIGN;
		tag->field_width--;
	}
	if (num == 0)
		tmp[tag->base_len++] = '0';
	else
		while (num != 0)
			tmp[tag->base_len++] = (digits[div_ptr(&num, tag->base)] | locase);
	if (tag->base_len > tag->precision)
		tag->precision = tag->base_len;
	tag->field_width -= tag->precision;
	print_ptr(tag, num, tag->field_width, tmp);
}

static void	print_ptr(t_tag *tag, unsigned long num, int width, char *tmp)
{
	if (!(tag->flags & (ZEROPAD + LEFT)))
		while (width-- > 0)
			ft_putchar_int(' ', tag);
	if (!(tag->flags & LEFT))
	{
		while (width-- > 0)
		{
			if (tag->flags & ZEROPAD)
				ft_putchar_int('0', tag);
			else if (!(tag->flags & ZEROPAD))
				ft_putchar_int(' ', tag);
		}
	}
	while (tag->base_len < tag->precision--)
		ft_putchar_int('0', tag);
	while (tag->base_len-- > 0)
		ft_putchar_int(tmp[tag->base_len], tag);
	while (width-- > 0)
		ft_putchar_int(' ', tag);
}
