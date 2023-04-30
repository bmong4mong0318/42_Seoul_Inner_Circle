/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_p.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:33 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:34 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_recursive_hex(size_t addr, int result)
{
	char	*hex;

	hex = "0123456789abcdef";
	if (addr == 0)
		return (result);
	result = print_recursive_hex(addr / 16, result);
	return (result + write(1, &hex[addr % 16], 1));
}

int	ft_printf_va_p(void *p)
{
	int		result;
	size_t	addr;

	result = 0;
	addr = *(size_t *)&p;
	result += write(1, "0x", 2);
	if (p == NULL)
		return (result + write(1, "0", 1));
	else
		return (print_recursive_hex(addr, result));
}
