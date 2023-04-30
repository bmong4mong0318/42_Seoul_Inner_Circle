/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:51 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:56:53 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	free_and_return_false(void *arg)
{
	if (arg != NULL)
		free(arg);
	return (FALSE);
}

void	free_args(int count, ...)
{
	va_list	ap;
	void	*ptr;

	if (count <= 0)
		return ;
	va_start(ap, count);
	while (count != 0)
	{
		ptr = (void *)va_arg(ap, void *);
		if (ptr != NULL)
			free(ptr);
		count -= 1;
	}
	va_end(ap);
}
