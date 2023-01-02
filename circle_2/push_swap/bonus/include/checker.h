/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:45:56 by dayun             #+#    #+#             */
/*   Updated: 2023/01/02 15:40:11 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_node
{
	int				data;
	int				index;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node		*top;
	t_node		*bottom;
	t_node		*cur;
	int			num_of_data;
}				t_stack;

/*------------------------
	doubly linked list
------------------------*/
t_node	*ft_init_new_node(int num);
t_node	*ft_pop_top(t_stack *stack);
t_node	*ft_pop_bottom(t_stack *stack);
void	ft_push_top(t_stack *stack, t_node *node);
void	ft_push_bottom(t_stack *stack, t_node *node);

/*------------------------
	validation functions
------------------------*/
int		is_nbr(char *nbr);
int		is_integer(long long nbr);
int		is_duplicate(int nbr, t_stack *stack);
void	ft_validate_param(char *argv, t_stack *stack);

/*------------------------
	operator functions
------------------------*/
void	sa(t_stack *a_stack);			
void	sb(t_stack *b_stack);	
void	ss(t_stack *a_stack, t_stack *b_stack);
void	pa(t_stack *a_stack, t_stack *b_stack);
void	pb(t_stack *a_stack, t_stack *b_stack);
void	ra(t_stack *a_stack);
void	rb(t_stack *b_stack);
void	rr(t_stack *a_stack, t_stack *b_stack);
void	rra(t_stack *a_stack);
void	rrb(t_stack *b_stack);
void	rrr(t_stack *a_stack, t_stack *b_stack);

/*------------------------
	check functions
------------------------*/
int		ft_strcmp(const char *s1, const char *s2);
int		already_sorted(t_stack *stack);
void	operation(char *op, t_stack *stack_a, t_stack *stack_b);
void	ft_check_op(t_stack *stack_a, t_stack *stack_b);

/*------------------------
	stack_utils
------------------------*/
void	init_stack(t_stack *stack);
void	indexing_stack(t_stack *a_stack);
void	generate_stack(char **argv, t_stack *stack);
void	ft_free_stack(t_stack *stack);

/*------------------------
	utils functions
------------------------*/
void	ft_putstr_fd(char *s, int fd);
void	ft_error(void);
int		ft_atoi(const char *s);
char	**ft_split(char const *str, char c);

#endif
