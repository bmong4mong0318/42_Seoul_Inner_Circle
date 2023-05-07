/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:57:00 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 16:08:51 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"
#include "utils.h"
#include "parsing.h"
#include "hooks.h"
#include "execute.h"
#include "vector.h"

int main_loop(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	calculation(game);
	paint(game);
	// paint_minimap(game);
	return (0);
}

int main(int argc, char **argv)
{
	t_game game;

	init_game(&game, argv[1]);
	if (argc != 2)
		error_exit("Invalid argument", NULL, &game);
	if (is_valid_file_extension(argv[1]) == FALSE)
		error_exit("Invalid file format(.cub)", argv[1], &game);
	if (is_file_openable(argv[1]) == FALSE)
		error_exit("File open error", argv[1], &game);

	map_info_validation(&game); // !!
	map_validation(&game, argv[1]);
	// 헤더파일 한번씩 바꾸기
	// 벽충돌 어디서 했는지?
	init_mlx_setting(&game);
	init_camera_angle(&game);
	init_texture(&game);
	mlx_hook(game.win, X_EVENT_move_player, 0, &move_player, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &exit_hook, &game);
	mlx_loop_hook(game.mlx, &main_loop, &game);
	mlx_loop(game.mlx);
	return (0);
}
