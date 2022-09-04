/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 16:50:19 by dayun             #+#    #+#             */
/*   Updated: 2022/09/03 20:47:19 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	do_div(long long *n, int base)
{
	int	res;

	res = *n % base;
	*n /= base;
	return (res);
}

static int	check_sign(t_tag *tag)
{
	if (tag->flags & PLUS || tag->flags & SPACE)
		return (1);
	else
		return (0);
}

static void	print_sign(t_tag *tag)
{
	if (tag->flags & SIGN)
		ft_putchar_int('-', tag);
	else if (tag->flags & PLUS)
		ft_putchar_int('+', tag);
	else if (tag->flags & SPACE)
		ft_putchar_int(' ', tag);
}

static void	print_special(t_tag *tag)
{	
	if ((tag->flags & SPECIAL) && !tag->flag_final)
	{
		if (tag->flags & SMALL)
		{
			ft_putchar_int('0', tag);
			ft_putchar_int('x', tag);
		}
		else
		{
			ft_putchar_int('0', tag);
			ft_putchar_int('X', tag);
		}
	}
}

void	ft_put_num(long long num, t_tag	*tag)
{
	int					base;
	int					locase;
	char				tmp[100];
	long long			num_mem;
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
		// tag->field_width--;
	}
	num_mem = num;
	if (num == 0)
	{
		tag->flag_final = 1;
		if (tag->preczero)
		{
			if (tag->flag_prec == 0 || tag->preczero == 2)
				tmp[tag->base_len++] = '0';
			else
				tmp[tag->base_len++] = ' ';
		}
		else
			tmp[tag->base_len++] = '0';
	}
	else
		while (num != 0)
			tmp[tag->base_len++] = (digits[do_div(&num, tag->base)] | locase);
	if (tag->base_len > tag->precision)
		tag->precision = tag->base_len;
	tag->field_width -= tag->precision;
	print_num(tag, num_mem, tag->field_width, tmp);
}

static void	print_num(t_tag *tag, long long num, int width, char *tmp)
{
	if (check_sign(tag)
		|| (num == 0 && (tag->preczero == 2)))
		width--;
	if (num == 0 && (tag->flag_prec || tag->flags & ZEROPAD))
		width++;
	if (!(tag->flags & (ZEROPAD + LEFT)))
		while (width-- > 0)
			ft_putchar_int(' ', tag);
	print_sign(tag);
	print_special(tag);
	if (!(tag->flags & LEFT))
	{
		if (num == 0 && !tag->flag_prec)
			width--;
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
	if (!(num == 0 && (tag->preczero || tag->flag_prec)))
	{
		while (tag->base_len-- > 0)
			ft_putchar_int(tmp[tag->base_len], tag);
	}
	if (num == 0 && tag->preczero == 2)
	{
		tag->base_len--;
		ft_putchar_int(tmp[tag->base_len], tag);
	}
	while (width-- > 0)
		ft_putchar_int(' ', tag);
}
