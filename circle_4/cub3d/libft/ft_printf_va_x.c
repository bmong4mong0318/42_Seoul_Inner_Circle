/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:47 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:48 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_recursive_va_x(unsigned int n, char c, int result)
{
	char	*hex;

	if (c == 'x')
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	if (n == 0)
		return (result);
	result = ft_printf_recursive_va_x(n / 16, c, result);
	return (result + write(1, &hex[n % 16], 1));
}

int	ft_printf_va_x(unsigned int n, char c)
{
	int	result;

	result = 0;
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_printf_recursive_va_x(n, c, result));
}
