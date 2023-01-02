/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sandglass.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 20:17:37 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:35:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	efficient_ra(t_stack *a_stack, int idx)
{
	if (0 <= idx && idx < a_stack->num_of_data / 2)
		rra(a_stack);
	else
		ra(a_stack);
}

void	ft_stack_atob(t_stack *a_stack, t_stack *b_stack, int chunk)
{
	t_node	*top_a;
	int		idx;

	idx = 0;
	while (a_stack->num_of_data)
	{
		top_a = a_stack->top;
		if (top_a->index <= idx)
		{
			pb(a_stack, b_stack);
			++idx;
		}
		else if (idx < top_a->index && top_a->index <= idx + chunk)
		{
			pb(a_stack, b_stack);
			rb(b_stack);
			++idx;
		}
		else if (idx + chunk < top_a->index)
			efficient_ra(a_stack, idx);
	}
}

void	put_to_the_top(t_stack *stack)
{
	int	max_idx;

	max_idx = 0;
	stack->cur = stack->top;
	while (stack->cur->index != stack->num_of_data - 1)
	{
		max_idx++;
		stack->cur = stack->cur->next;
	}
	while (stack->top->index < stack->num_of_data - 1)
	{
		if (max_idx < stack->num_of_data / 2)
			rb(stack);
		else
			rrb(stack);
	}
}

void	ft_stack_btoa(t_stack *a_stack, t_stack *b_stack)
{
	while (b_stack->num_of_data > 0)
	{
		put_to_the_top(b_stack);
		pa(a_stack, b_stack);
	}
}

void	ft_sort_other(t_stack *a_stack, t_stack *b_stack)
{
	int	chunk;
	int	x;

	x = a_stack->num_of_data;
	chunk = 0.000000053 * x * x + 0.03 * x + 14.5;
	ft_stack_atob(a_stack, b_stack, chunk);
	ft_stack_btoa(a_stack, b_stack);
}
