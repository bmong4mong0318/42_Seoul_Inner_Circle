/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:37:53 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:15:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_stack *a_stack)
{
	t_node	*first_tmp;
	t_node	*second_tmp;

	first_tmp = ft_pop_top(a_stack);
	second_tmp = ft_pop_top(a_stack);
	ft_push_top(a_stack, first_tmp);
	ft_push_top(a_stack, second_tmp);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *b_stack)
{
	t_node	*first_tmp;
	t_node	*second_tmp;

	first_tmp = ft_pop_top(b_stack);
	second_tmp = ft_pop_top(b_stack);
	ft_push_top(b_stack, first_tmp);
	ft_push_top(b_stack, second_tmp);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *a_stack, t_stack *b_stack)
{
	t_node	*first_tmp;
	t_node	*second_tmp;

	first_tmp = ft_pop_top(a_stack);
	second_tmp = ft_pop_top(a_stack);
	ft_push_top(a_stack, first_tmp);
	ft_push_top(a_stack, second_tmp);
	first_tmp = ft_pop_top(b_stack);
	second_tmp = ft_pop_top(b_stack);
	ft_push_top(b_stack, first_tmp);
	ft_push_top(b_stack, second_tmp);
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	if (b_stack->top != NULL)
		ft_push_top(a_stack, ft_pop_top(b_stack));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->top != NULL)
		ft_push_top(b_stack, ft_pop_top(a_stack));
	ft_putstr_fd("pb\n", 1);
}
