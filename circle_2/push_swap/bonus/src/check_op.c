/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:55:13 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:39:02 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"
#include "../include/get_next_line.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

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

void	operation(char *op, t_stack *stack_a, t_stack *stack_b)
{
	if (!ft_strcmp(op, "sa\n"))
		sa(stack_a);
	else if (!ft_strcmp(op, "sb\n"))
		sb(stack_b);
	else if (!ft_strcmp(op, "ss\n"))
		ss(stack_a, stack_a);
	else if (!ft_strcmp(op, "pa\n"))
		pa(stack_a, stack_b);
	else if (!ft_strcmp(op, "pb\n"))
		pb(stack_a, stack_b);
	else if (!ft_strcmp(op, "ra\n"))
		ra(stack_a);
	else if (!ft_strcmp(op, "rb\n"))
		rb(stack_b);
	else if (!ft_strcmp(op, "rr\n"))
		rr(stack_a, stack_b);
	else if (!ft_strcmp(op, "rra\n"))
		rra(stack_a);
	else if (!ft_strcmp(op, "rrb\n"))
		rrb(stack_b);
	else if (!ft_strcmp(op, "rrr\n"))
		rrr(stack_a, stack_b);
	else
		ft_error();
}

void	ft_check_op(t_stack *stack_a, t_stack *stack_b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(STDIN_FILENO);
		if (!op)
			break ;
		operation(op, stack_a, stack_b);
		free(op);
	}
	if (already_sorted(stack_a) && !(stack_b->num_of_data))
		write(1, "OK\n", 3);
	else if (!already_sorted(stack_a) || stack_b->num_of_data)
		write(1, "KO\n", 3);
	else
		write(1, "Error\n", 6);
}
