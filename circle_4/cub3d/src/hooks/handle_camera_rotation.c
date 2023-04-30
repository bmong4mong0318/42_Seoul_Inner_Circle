/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_camera_rotation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:55:23 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:55:25 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <math.h>

static void	left_rotation(t_game *game, t_vec dir, t_vec plane)
{
	double	rot_speed;

	rot_speed = -game->rot_speed;
	game->dir.x = dir.x * cos(rot_speed) - dir.y * sin(rot_speed);
	game->dir.y = dir.x * sin(rot_speed) + dir.y * cos(rot_speed);
	game->plane.x = plane.x * cos(rot_speed) - plane.y * sin(rot_speed);
	game->plane.y = plane.x * sin(rot_speed) + plane.y * cos(rot_speed);
}

static void	right_rotation(t_game *game, t_vec dir, t_vec plane)
{
	double	rot_speed;

	rot_speed = game->rot_speed;
	game->dir.x = dir.x * cos(rot_speed) - dir.y * sin(rot_speed);
	game->dir.y = dir.x * sin(rot_speed) + dir.y * cos(rot_speed);
	game->plane.x = plane.x * cos(rot_speed) - plane.y * sin(rot_speed);
	game->plane.y = plane.x * sin(rot_speed) + plane.y * cos(rot_speed);
}

void	handle_camera_rotation(int key, t_game *game)
{
	t_vec	dir;
	t_vec	plane;

	dir = game->dir;
	plane = game->plane;
	if (key == KEY_RIGHT)
		right_rotation(game, dir, plane);
	else if (key == KEY_LEFT)
		left_rotation(game, dir, plane);
}
