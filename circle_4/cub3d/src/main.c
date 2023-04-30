/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:57:00 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 15:01:02 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"
#include "parsing.h"
#include "hooks.h"
#include "execute.h"
#include "vector.h"

void	paint_grid(t_game *game, int y, int x, int color)
{
	int	i;
	int	j;

	i = y - 1;
	while (++i < y + game->gridh)
	{
		j = x - 1;
		while (++j < x + game->gridw)
		{
			game->minimap_data[i * game->miniw + j] = color;
		}
	}
}

void	paint_minimap(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->map.height)
	{
		j = -1;
		while (++j < game->map.width)
		{

			if (i == (int)game->pos.x && j == (int)game->pos.y)
				paint_grid(game, i * game->gridh, j * game->gridw, RGB_RED);
			else if (game->map.map_array[i][j] == '\0')
				break ;
			else if (game->map.map_array[i][j] == '0')
				paint_grid(game, i * game->gridh, j * game->gridw, RGB_WHITE);
			else if (game->map.map_array[i][j] == '1')
				paint_grid(game, i * game->gridh, j * game->gridw, 0);
			else
				paint_grid(game, i * game->gridh, j * game->gridw, 0);
		}
	}
	mlx_put_image_to_window(game->mlx, game->win, game->minimap.img, 0, 0);
}

int	main_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	game->minimap_data = (t_ui *)mlx_get_data_addr(game->minimap.img, \
		&(game->minimap.bpp), &(game->minimap.size_l), &(game->minimap.endian));
	calc(game);
	draw(game);
	paint_minimap(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game, argv[1]);
	if (argc != 2)
		throw_error(INVALID_ARGUMENT, NULL, &game);
	if (is_valid_file_extension(argv[1]) == FALSE)
		throw_error(INVALID_FILE_EXTENSION, argv[1], &game);
	if (is_file_openable(argv[1]) == FALSE)
		throw_error(NOT_OPENABLE_FILE, argv[1], &game);
	check_map_info_validation(&game);
	check_map_validation(&game, argv[1]);
	game.gridw = game.miniw / game.map.width;
	game.gridh = game.minih / game.map.height; // TODO:  fix
	init_mlx_setting(&game);
	init_camera_angle(&game);
	init_texture(&game);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
