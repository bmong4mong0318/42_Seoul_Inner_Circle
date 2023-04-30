/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_va_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:52:38 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:52:39 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_va_s(char *s)
{
	size_t	len;

	len = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	len = ft_strlen(s);
	return (write(1, s, len));
}
