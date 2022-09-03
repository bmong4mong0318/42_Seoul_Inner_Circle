/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 19:36:25 by dayun             #+#    #+#             */
/*   Updated: 2022/07/13 20:26:17 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*nb;
	unsigned char	nc;

	nb = (unsigned char *)b;
	nc = (unsigned char)c;
	while (len--)
		*nb++ = nc;
	return (b);
}
