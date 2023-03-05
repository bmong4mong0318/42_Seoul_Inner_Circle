/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:34:45 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:34:47 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*b_char;

	b_char = (unsigned char *)b;
	while (len > 0)
	{
		*b_char = (unsigned char)c;
		++b_char;
		--len;
	}
	return (b);
}
