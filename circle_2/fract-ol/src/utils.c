/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:26:56 by dayun             #+#    #+#             */
/*   Updated: 2023/01/28 21:26:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"
#include "../include/keycode.h"

int	ft_exit(void)
{
	exit(1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s2[i] && s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	move(int keycode, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->x_max - mlx->x_min);
	dy = (mlx->y_max - mlx->y_min);
	if (keycode == KEYCODE_ESC)
		exit(0);
	if (keycode == KEYCODE_RIGHT || keycode == KEYCODE_LEFT)
	{
		if (keycode == KEYCODE_LEFT)
			dx *= -1;
		mlx->x_min += dx / 7.5;
		mlx->x_max += dx / 7.5;
	}
	if (keycode == KEYCODE_DOWN || keycode == KEYCODE_UP)
	{
		if (keycode == KEYCODE_DOWN)
			dy *= -1;
		mlx->y_min += dy / 7.5;
		mlx->y_max += dy / 7.5;
	}
}

int	keys(int keycode, t_data *mlx)
{
	if (keycode == KEYCODE_ESC
		|| keycode == KEYCODE_UP || keycode == KEYCODE_DOWN
		|| keycode == KEYCODE_LEFT || keycode == KEYCODE_RIGHT)
		move(keycode, mlx);
	if (keycode == Q_CHANGE_COLOR_UP)
		mlx->color += 10;
	if (keycode == W_CHANGE_COLOR_DOWN)
		mlx->color -= 10;
	ft_run(mlx, 1);
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *mlx)
{
	float	dx;
	float	dy;

	dx = (mlx->x_max - mlx->x_min) / SIZE_X;
	dy = (mlx->y_max - mlx->y_min) / SIZE_Y;
	if (keycode == MOUSE_DOWN_ZOOM_OUT)
	{
		mlx->x_min = (mlx->x_min + ((dx * x) * 0.5));
		mlx->x_max = (mlx->x_max - ((dx * (SIZE_X - x)) * 0.5));
		mlx->y_max = (mlx->y_max - ((dy * y) * 0.5));
		mlx->y_min = (mlx->y_min + ((dy * (SIZE_Y - y)) * 0.5));
	}
	if (keycode == MOUSE_UP_ZOOM_IN)
	{
		mlx->x_min = (mlx->x_min - ((dx * x) * 0.5));
		mlx->x_max = (mlx->x_max + ((dx * (SIZE_X - x)) * 0.5));
		mlx->y_max = (mlx->y_max + ((dy * y) * 0.5));
		mlx->y_min = (mlx->y_min - ((dy * (SIZE_Y - y)) * 0.5));
	}
	ft_run(mlx, 1);
	return (0);
}
