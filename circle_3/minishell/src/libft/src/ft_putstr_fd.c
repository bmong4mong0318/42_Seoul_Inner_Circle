/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:36:05 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:36:06 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* NOTE : Dangerous if write() error occures!! */
extern size_t	ft_strlen(const char *str);

/* NOTE : Paritial write && write() error handling */
void	ft_putstr_fd(char *string, int fd)
{
	size_t	idx;
	size_t	len;
	ssize_t	writed_bytes;

	idx = 0;
	len = ft_strlen(string);
	while (idx < len)
	{
		writed_bytes = write(fd, &string[idx], len);
		if (writed_bytes < 0)
			return ;
		idx += writed_bytes;
	}
}
