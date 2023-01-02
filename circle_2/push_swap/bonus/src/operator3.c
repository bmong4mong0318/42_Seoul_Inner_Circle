/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:16:17 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:19:37 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	rra(t_stack *a_stack)
{
	ft_push_top(a_stack, ft_pop_bottom(a_stack));
}

void	rrb(t_stack *b_stack)
{
	ft_push_top(b_stack, ft_pop_bottom(b_stack));
}

void	rrr(t_stack *a_stack, t_stack *b_stack)
{
	ft_push_top(a_stack, ft_pop_bottom(a_stack));
	ft_push_top(b_stack, ft_pop_bottom(b_stack));
}