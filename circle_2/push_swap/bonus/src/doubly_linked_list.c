/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubly_linked_list.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 17:42:01 by dayun             #+#    #+#             */
/*   Updated: 2023/01/12 13:03:12 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

t_node	*ft_init_new_node(int num)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
		ft_error();
	new_node->data = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_node	*ft_pop_top(t_stack *stack)
{
	t_node	*node_tmp;

	node_tmp = stack->top;
	if (stack->num_of_data == 0)
		return (NULL);
	if (stack->num_of_data == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		stack->num_of_data--;
		return (node_tmp);
	}
	stack->top->next->prev = NULL;
	stack->top = stack->top->next;
	node_tmp->next = NULL;
	stack->num_of_data--;
	return (node_tmp);
}

t_node	*ft_pop_bottom(t_stack *stack)
{
	t_node	*node_tmp;

	node_tmp = stack->bottom;
	if (stack->num_of_data == 0)
		return (NULL);
	if (stack->num_of_data == 1)
	{
		stack->top = NULL;
		stack->bottom = NULL;
		stack->num_of_data--;
		return (node_tmp);
	}
	stack->bottom->prev->next = NULL;
	stack->bottom = stack->bottom->prev;
	node_tmp->prev = NULL;
	stack->num_of_data--;
	return (node_tmp);
}

void	ft_push_top(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->top != NULL)
	{
		stack->top->prev = node;
		node->next = stack->top;
	}
	stack->top = node;
	if (stack->bottom == NULL)
		stack->bottom = node;
	stack->num_of_data++;
}

void	ft_push_bottom(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return ;
	if (stack->top != NULL)
	{
		stack->bottom->next = node;
		node->prev = stack->bottom;
	}
	stack->bottom = node;
	if (stack->top == NULL)
		stack->top = node;
	stack->num_of_data++;
}
