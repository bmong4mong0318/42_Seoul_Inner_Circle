/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:38:23 by dayun             #+#    #+#             */
/*   Updated: 2023/05/15 16:39:54 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "cub3D.h"
# include "vector.h"

enum
{
	HORIZONTAL,
	VERTICAL,
};

typedef struct s_calc
{
	int		side;
	int		tex_num;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	camera_x;
	double	perp_wall_dist;
	t_pos	map;
	t_pos	step;
	t_pos	tex;
	t_vec	ray_dir;
	t_vec	delta_dist;
	t_vec	side_dist;
}	t_calc;

// calculation.c
void	calculation(t_game *game);

// paint.c
void	paint_background(t_game *game);
void	paint_wall(t_game *game, t_calc calc, int x);
void	paint_floor_and_ceiling(t_game *game, t_calc calc, int x);
void	paint(t_game *game);

// set_wall_dist.c
double	set_wall_dist(t_calc *calc, t_game *game, t_vec pos);

#endif
