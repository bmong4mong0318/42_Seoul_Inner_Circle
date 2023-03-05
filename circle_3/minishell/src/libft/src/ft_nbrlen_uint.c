/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:34:50 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:34:51 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_nbrlen_uint(unsigned int num_pos)
{
	size_t	len;

	len = 0;
	if (num_pos == 0)
		return (1);
	while (num_pos != 0)
	{
		num_pos /= 10;
		len += 1;
	}
	return (len);
}
