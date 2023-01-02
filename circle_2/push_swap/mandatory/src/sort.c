/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:52:02 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:17:28 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	already_sorted(t_stack *stack)
{
	stack->cur = stack->top;
	while (stack->cur->next)
	{
		if (stack->cur->data < stack->cur->next->data)
			stack->cur = stack->cur->next;
		else
			return (false);
	}
	return (true);
}

void	sort_three(t_stack *a_stack, int flag)
{
	while (!already_sorted(a_stack))
	{
		a_stack->cur = a_stack->top;
		if (a_stack->cur->index == 0 + flag)
		{
			sa(a_stack);
			ra(a_stack);
		}
		else if (a_stack->cur->index == a_stack->num_of_data - 1)
		{
			if (a_stack->bottom->index == 0 + flag)
			{
				sa(a_stack);
				rra(a_stack);
			}
			else
				ra(a_stack);
		}
		else
			ra(a_stack);
	}
}

void	sort_four(t_stack *a_stack, t_stack *b_stack)
{
	int	flag;

	flag = 0;
	while (!b_stack->num_of_data)
	{
		a_stack->cur = a_stack->top;
		if (a_stack->cur->index == 0 || a_stack->cur->index == 3)
		{
			if (a_stack->cur->index == 0)
				flag = 1;
			pb(a_stack, b_stack);
		}
		else
			ra(a_stack);
	}
	if (!already_sorted(a_stack))
		sort_three(a_stack, flag);
	pa(a_stack, b_stack);
	if (a_stack->top->index == 2)
		ra(a_stack);
}

void	sort_five(t_stack *a_stack, t_stack *b_stack)
{
	while (b_stack->num_of_data != 2)
	{
		a_stack->cur = a_stack->top;
		if (a_stack->cur->index == 0 || a_stack->cur->index == 4)
			pb(a_stack, b_stack);
		else
			ra(a_stack);
	}
	if (!already_sorted(a_stack))
		sort_three(a_stack, 1);
	while (b_stack->num_of_data)
	{
		pa(a_stack, b_stack);
		if (a_stack->top->index == 4)
			ra(a_stack);
	}
}

void	ft_sort(t_stack *a_stack, t_stack *b_stack)
{
	if (a_stack->num_of_data == 1 || already_sorted(a_stack))
		return ;
	else if (a_stack->num_of_data == 2)
	{
		if (a_stack->top->data > a_stack->bottom->data)
			sa(a_stack);
	}
	else if (a_stack->num_of_data == 3)
		sort_three(a_stack, 0);
	else if (a_stack->num_of_data == 4)
		sort_four(a_stack, b_stack);
	else if (a_stack->num_of_data == 5)
		sort_five(a_stack, b_stack);
	else
		ft_sort_other(a_stack, b_stack);
}