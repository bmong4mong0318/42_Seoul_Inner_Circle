/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:15:13 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:15:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	ra(t_stack *a_stack)
{
	ft_push_bottom(a_stack, ft_pop_top(a_stack));
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *b_stack)
{
	ft_push_bottom(b_stack, ft_pop_top(b_stack));
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *a_stack, t_stack *b_stack)
{
	ft_push_bottom(a_stack, ft_pop_top(a_stack));
	ft_push_bottom(b_stack, ft_pop_top(b_stack));
	ft_putstr_fd("rr\n", 1);
}
