/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:55:42 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 15:07:37 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include <fcntl.h>

void init_game(t_game *game, char *file)
{
	game->wall.no = NULL;
	game->wall.so = NULL;
	game->wall.ea = NULL;
	game->wall.we = NULL;
	game->ceiling = NULL;
	game->floor = NULL;
	game->map_fd = ERROR;
	game->line_idx = 0;
	game->player = '\0';
	game->map.height = 0;
	game->map.width = 0;
	game->map.n_cnt = 0;
	game->map.map_array = NULL;
	game->map.is_n_continue = FALSE;
	game->move_speed = 0.05 + 1e-2;
	game->rot_speed = 0.20;
	game->map_fd = open(file, O_RDONLY, 0644);
	ft_bzero(game->buf, WINDOW_WIDTH * WINDOW_HEIGHT);
	game->texture = (int **)malloc(sizeof(int *) * 4);
	game->texture[0] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[1] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[2] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
	game->texture[3] = ft_calloc(TEX_HEIGHT * TEX_WIDTH, sizeof(int));
}

void init_camera_angle(t_game *game)
{
	if (game->player == 'W')
	{
		game->dir = vec_new(-1, 0);
		game->plane = vec_new(0, -0.66);
	}
	else if (game->player == 'E')
	{
		game->dir = vec_new(1, 0);
		game->plane = vec_new(0, 0.66);
	}
	else if (game->player == 'N')
	{
		game->dir = vec_new(0, -1);
		game->plane = vec_new(0.66, 0);
	}
	else if (game->player == 'S')
	{
		game->dir = vec_new(0, 1);
		game->plane = vec_new(-0.66, 0);
	}
}

void init_mlx_setting(t_game *game)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D");
	game->img.img = mlx_new_image(game->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.img, &game->img.bpp,
											  &game->img.size_l, &game->img.endian);
}
