/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:23:05 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:19:55 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

void	init_stack(t_stack *stack)
{
	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		ft_error();
	stack->top = NULL;
	stack->bottom = NULL;
	stack->cur = NULL;
	stack->num_of_data = 0;
}

void	indexing_stack(t_stack *a_stack)
{
	t_node	*cursor;

	a_stack->cur = a_stack->top;
	while (a_stack->cur)
	{
		cursor = a_stack->top;
		while (cursor)
		{
			if (a_stack->cur->data > cursor->data)
			{
				a_stack->cur->index++;
			}
			cursor = cursor->next;
		}
		a_stack->cur = a_stack->cur->next;
	}
}

void	generate_stack(char **argv, t_stack *stack)
{
	int	idx;

	idx = 0;
	while (argv[++idx])
	{
		if (argv[idx][0] == '\0')
			ft_error();
		else
			ft_validate_param(argv[idx], stack);
	}
}

void	ft_free_stack(t_stack *stack)
{
	int	idx;

	idx = -1;
	while (++idx < stack->num_of_data)
	{
		stack->cur = ft_pop_top(stack);
		free(stack->cur);
	}
	free(stack->top);
	free(stack->bottom);
}
