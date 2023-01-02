/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:59:58 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:28:35 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	a_stack;
	t_stack	b_stack;

	if (argc < 2)
		return (false);
	if (!argv[1][0])
		ft_error();
	init_stack(&a_stack);
	init_stack(&b_stack);
	generate_stack(argv, &a_stack);
	indexing_stack(&a_stack);
	ft_sort(&a_stack, &b_stack);
	ft_free_stack(&a_stack);
	ft_free_stack(&b_stack);
}

	// b_stack->cur = b_stack->top;
	// while (b_stack->cur){
	// 	printf("::::data:%d", b_stack->cur->data);
	// 	printf("::::index:%d\n", b_stack->cur->index);
	// 	b_stack->cur = b_stack->cur->next;
	// }

	// void	efficient_ra(t_stack *a_stack, int idx, int chunk)
// {
// 	int	push_idx;

// 	push_idx = 0;
// 	a_stack->cur = a_stack->top;
// 	while (a_stack->cur->next)
// 	{
// 		if (a_stack->cur->index <= idx + chunk)
// 			break ;
// 		++push_idx;
// 		a_stack->cur = a_stack->cur->next;
// 	}
// 	if (push_idx < a_stack->num_of_data / 2)
// 		ra(a_stack);
// 	else
// 		rra(a_stack);
// }
