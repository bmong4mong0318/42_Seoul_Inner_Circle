/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 13:51:11 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/20 16:39:22 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{	
	size_t	i;
	size_t	length;

	if (s == 0 || fd < 0)
	{
		return ;
	}
	i = 0;
	length = ft_strlen(s);
	while (i < length)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
