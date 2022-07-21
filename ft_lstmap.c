/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 15:21:17 by dayun             #+#    #+#             */
/*   Updated: 2022/07/21 15:27:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*nlst;
	t_list	*tmp;

	if (!lst || !f)
		return (0);
	nlst = ft_lstnew(f(lst->content));
	if (!nlst)
		return (0);
	tmp = nlst;
	lst = lst->next;
	while (lst)
	{
		tmp->next = ft_lstnew(f(lst->content));
		if (!(tmp->next))
		{
			ft_lstclear(&nlst, del);
			return (0);
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	return (nlst);
}
