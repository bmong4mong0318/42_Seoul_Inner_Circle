/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:50:00 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:50:02 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

typedef struct s_vec {
	double	x;
	double	y;
}	t_vec;

typedef struct s_pos {
	int	x;
	int	y;
}	t_pos;

// vector.c
t_vec	vec_new(double x, double y);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v, double n);
t_pos	double_to_int(t_vec v);

#endif
