/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:33:31 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 14:05:05 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia_set(double x, double y, t_data *mlx)
{
	int		i;
	double	xx;
	double	yy;
	double	temp;

	xx = x;
	yy = y;
	i = 1;
	while (i < ITERATION)
	{
		temp = xx;
		xx = (pow(xx, 2) - pow(yy, 2)) + mlx->julia_x;
		yy = (2 * temp * yy) + mlx->julia_y;
		if (pow(xx, 2) + pow(yy, 2) > 4)
		{
			my_mlx_pixel_put(mlx, mlx->loop_x, mlx->loop_y,
				(mlx->color) + 0x3232FF * i);
			return ;
		}
		i++;
	}
	my_mlx_pixel_put(mlx, mlx->loop_x, mlx->loop_y, 0x000E0E0E);
}

void	julia(t_data *mlx)
{
	double	x;
	double	y;

	mlx->loop_y = 0;
	mlx_clear_window(mlx->mlx, mlx->win);
	while (mlx->loop_y < SIZE_Y)
	{
		mlx->loop_x = 0;
		while (mlx->loop_x < SIZE_X)
		{
			x = mlx->x_min
				+ (mlx->loop_x * ((mlx->x_max - mlx->x_min) / SIZE_X));
			y = mlx->y_max
				- (mlx->loop_y * ((mlx->y_max - mlx->y_min) / SIZE_Y));
			julia_set(x, y, mlx);
			++mlx->loop_x;
		}
		++mlx->loop_y;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	start_julia(t_data *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, SIZE_X, SIZE_Y, "Julia");
	mlx->img = mlx_new_image(mlx->mlx, SIZE_X, SIZE_Y);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel,
			&mlx->line_length, &mlx->endian);
	mlx->x_min = MIN_X;
	mlx->x_max = MAX_X;
	mlx->y_min = MIN_Y;
	mlx->y_max = MAX_Y;
	mlx->color = 0;
	julia(mlx);
	mlx_key_hook(mlx->win, keys, mlx);
	mlx_mouse_hook(mlx->win, zoom, mlx);
	mlx_loop(mlx->mlx);
}
