/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:46:15 by dayun             #+#    #+#             */
/*   Updated: 2023/01/10 13:29:56 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/checker.h"

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
	ft_check_op(&a_stack, &b_stack);
	ft_free_stack(&a_stack);
}
