/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 15:16:17 by dayun             #+#    #+#             */
/*   Updated: 2023/01/11 15:48:42 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	is_nbr(char *nbr)
{
	while ((9 <= *nbr && *nbr <= 13) || *nbr == ' ')
		nbr++;
	if (*nbr == '-' || *nbr == '+')
		nbr++;
	if (*nbr == '\0')
		return (false);
	while (*nbr)
	{
		if (*nbr < '0' || '9' < *nbr)
			return (false);
		if (*nbr == '\"')
			return (false);
		nbr++;
	}
	return (true);
}

int	is_integer(long long nbr)
{
	if (nbr < -2147483648 || 2147483647 < nbr)
		return (false);
	return (true);
}

int	is_duplicate(int nbr, t_stack *stack)
{
	stack->cur = stack->top;
	while (stack->cur)
	{
		if (stack->cur->data == nbr)
			return (false);
		stack->cur = stack->cur->next;
	}
	return (true);
}

void	ft_validate_param(char *argv, t_stack *stack)
{
	char	**split_argv;
	int		i;

	i = -1;
	split_argv = ft_split(argv, ' ');
	if (!split_argv || !*split_argv)
		ft_error();
	while (split_argv[++i])
	{
		if (!is_nbr(split_argv[i]))
			ft_error();
		if (!is_integer(ft_atoi(split_argv[i])))
			ft_error();
		if (!is_duplicate(ft_atoi(split_argv[i]), stack))
			ft_error();
		ft_push_bottom(stack, ft_init_new_node(ft_atoi(split_argv[i])));
	}
	ft_free(split_argv, i);
}
