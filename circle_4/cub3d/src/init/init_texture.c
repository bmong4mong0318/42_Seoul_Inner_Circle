/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 16:48:07 by dayun             #+#    #+#             */
/*   Updated: 2023/05/15 17:00:04 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"cub3D.h"

static void	load_image(t_game *game, int *texture, char *path, t_img *img)
{
	int	x_t;
	int	x_d;
	int	y;

	y = 0;
	img->img = mlx_xpm_file_to_image(game->mlx, path, \
		&img->img_width, &img->img_height);
	img->data = (int *)mlx_get_data_addr(img->img, \
		&img->bpp, &img->size_l, &img->endian);
	while (y < img->img_height)
	{
		x_t = 0;
		x_d = img->img_height - 1;
		while (x_t < img->img_width)
		{
			texture[img->img_width * y + x_t] \
				= img->data[img->img_width * y + x_d];
			x_t += 1;
			x_d -= 1;
		}
		y += 1;
	}
	mlx_destroy_image(game->mlx, img->img);
}

void	init_texture(t_game *game)
{
	t_img	img;

	load_image(game, game->texture[WALL_EA], game->wall.ea, &img);
	load_image(game, game->texture[WALL_WE], game->wall.we, &img);
	load_image(game, game->texture[WALL_SO], game->wall.so, &img);
	load_image(game, game->texture[WALL_NO], game->wall.no, &img);
}
