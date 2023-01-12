/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 11:00:19 by dayun             #+#    #+#             */
/*   Updated: 2023/01/11 16:07:28 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

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
	sort functions
------------------------*/
int		already_sorted(t_stack *stack);
void	sort_three(t_stack *a_stack, int flag);
void	sort_four(t_stack *a_stack, t_stack *b_stack);
void	sort_five(t_stack *a_stack, t_stack *b_stack);
void	ft_sort(t_stack *a_stack, t_stack *b_stack);

/*------------------------
	sort_sandglass
------------------------*/
void	efficient_ra(t_stack *a_stack, int idx);
void	ft_stack_atob(t_stack *a_stack, t_stack *b_stack, int chunk);
void	put_to_the_top(t_stack *stack);
void	ft_stack_btoa(t_stack *a_stack, t_stack *b_stack);
void	ft_sort_other(t_stack *a_stack, t_stack *b_stack);

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
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(void);
long	ft_atoi(const char *s);
int		ft_free(char **str, int i);
char	**ft_split(char const *str, char c);

#endif
