/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 19:50:57 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/16 16:31:29 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void	*ptr, int value, size_t n)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)ptr;
	while (n != 0)
	{
		if (*tmp == (unsigned char)value)
		{
			return (tmp);
		}
		tmp++;
		n--;
	}
	return (0);
}
