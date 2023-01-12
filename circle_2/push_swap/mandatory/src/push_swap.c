/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 10:59:58 by dayun             #+#    #+#             */
/*   Updated: 2023/01/10 16:56:01 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	main(int argc, char **argv)
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
}
