/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 12:21:01 by dayun             #+#    #+#             */
/*   Updated: 2022/07/14 21:17:05 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*nc;

	nc = (t_list *)malloc(sizeof(t_list));
	if (!nc)
		return (0);
	nc->content = content;
	nc->next = NULL;
	return (nc);
}
