/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 16:17:32 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 15:18:14 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_length + x * (mlx->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	ft_run(t_data *mlx, int flag)
{
	if (mlx->fractol == 1)
	{
		if (flag)
			mandelbrot(mlx);
		else
			start_mandelbrot(mlx);
	}
	if (mlx->fractol == 2)
	{
		if (flag)
			julia(mlx);
		else
			start_julia(mlx);
	}
	if (mlx->fractol == 3)
	{
		if (flag)
			burning(mlx);
		else
			start_burning(mlx);
	}
}

void	ft_usage(void)
{
	printf("::: The parameters is invalid! :::\n");
	printf("::: Usage: ./fractol <name>    :::\n");
	printf("::: List of available fractals :::\n");
	printf("::: - Mandelbrot               :::\n");
	printf("::: - Julia                    :::\n");
	printf("::: - Burning ship             :::\n");
	ft_exit();
}

int	main(int argc, char *argv[])
{
	t_data	mlx;

	if (argc < 2)
		ft_usage();
	if (argc == 4)
		mlx.julia_input_exist = 1;
	if (argc >= 2)
	{
		if (!ft_strcmp(argv[1], "Mandelbrot"))
			mlx.fractol = 1;
		else if (!ft_strcmp(argv[1], "Julia"))
		{
			mlx.fractol = 2;
			init_julia(&mlx, argv);
		}
		else if (!ft_strcmp(argv[1], "Burning Ship"))
			mlx.fractol = 3;
		else
			ft_usage();
		ft_run(&mlx, 0);
	}
}
