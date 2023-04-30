/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:55 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:56:58 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec	vec_new(double x, double y)
{
	t_vec	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	return (vec_new(v1.x + v2.x, v1.y + v2.y));
}

t_vec	vec_mul(t_vec v, double n)
{
	return (vec_new(v.x * n, v.y * n));
}

t_pos	double_to_int(t_vec v)
{
	t_pos	pos;

	pos.x = (int)v.x;
	pos.y = (int)v.y;
	return (pos);
}
