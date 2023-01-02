/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 21:37:53 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:19:25 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	sa(t_stack *a_stack)
{
	t_node	*first_tmp;
	t_node	*second_tmp;

	first_tmp = ft_pop_top(a_stack);
	second_tmp = ft_pop_top(a_stack);
	ft_push_top(a_stack, first_tmp);
	ft_push_top(a_stack, second_tmp);
}

void	sb(t_stack *b_stack)
{
	t_node	*first_tmp;
	t_node	*second_tmp;

	first_tmp = ft_pop_top(b_stack);
	second_tmp = ft_pop_top(b_stack);
	ft_push_top(b_stack, first_tmp);
	ft_push_top(b_stack, second_tmp);
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
}

void	pa(t_stack *a_stack, t_stack *b_stack)
{
	if (b_stack->top != NULL)
		ft_push_top(a_stack, ft_pop_top(b_stack));
}

void	pb(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->top != NULL)
		ft_push_top(b_stack, ft_pop_top(a_stack));
}
