/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:28 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

static int	get_digits(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i *= 10;
		n /= 10;
	}
	return (i);
}

int	ft_printf_va_d(int n)
{
	int	result;
	int	sign;
	int	digits;
	int	divisor;

	result = 0;
	sign = check_sign(n);
	digits = get_digits(n);
	if (sign == -1)
		result += write(1, "-", 1);
	while (n > 0 || n < 0)
	{
		divisor = ((n / digits) * sign) + '0';
		result += write(1, &divisor, 1);
		n %= digits;
		digits /= 10;
	}
	while (digits > 0)
	{
		result += write(1, "0", 1);
		digits /= 10;
	}
	return (result);
}
