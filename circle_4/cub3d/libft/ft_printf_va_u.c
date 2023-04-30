/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:42 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:44 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_printf_recursive_va_u(unsigned int n, int result)
{
	char	c;

	if (n == 0)
		return (result);
	result = ft_printf_recursive_va_u(n / 10, result);
	c = (n % 10) + '0';
	return (result + write(1, &c, 1));
}

int	ft_printf_va_u(unsigned int n)
{
	int	result;

	result = 0;
	if (n == 0)
		return (write(1, "0", 1));
	return (ft_printf_recursive_va_u(n, result));
}
