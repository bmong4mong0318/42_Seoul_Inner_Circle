/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:55:36 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 15:16:58 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "hooks.h"
#include <stdio.h>

int	exit_hook(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	close(game->map_fd);
	printf("👋 Exit the game. Thanks for playing!\n");
	exit(EXIT_SUCCESS);
}

int	key_press(int key, t_game *game)
{
	if (key == KEY_W || key == KEY_A || key == KEY_S || key == KEY_D)
		handle_player_move(key, game);
	else if (key == KEY_RIGHT || key == KEY_LEFT)
		handle_camera_rotation(key, game);
	else if (key == KEY_ESC)
		exit_hook(game);
	// mlx_clear_window(game->mlx, game->win);
	// main_loop(game);
	return (0);
}
