/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunjung <hyunjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:18:13 by hyunjung          #+#    #+#             */
/*   Updated: 2021/12/21 12:20:50 by hyunjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	size_t	i;
	size_t	length;

	i = 0;
	if (s == 0 || fd < 0)
	{
		return ;
	}
	length = ft_strlen(s);
	while (i < length)
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
