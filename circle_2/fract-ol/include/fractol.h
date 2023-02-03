/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:28:20 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 15:18:31 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define ITERATION	120

# define MAX_X 2
# define MAX_Y 2
# define MIN_X -2
# define MIN_Y -2

# define SIZE_X 700
# define SIZE_Y 700

# include <../mlx/mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	double	x_min;
	double	y_min;
	double	x_max;
	double	y_max;
	double	julia_x;
	double	julia_y;
	int		julia_input_exist;
	int		fractol;
	int		color;
	int		loop_y;
	int		loop_x;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

/*------------------------
	fract-ol
------------------------*/
void	my_mlx_pixel_put(t_data *mlx, int x, int y, int color);
void	ft_run(t_data *mlx, int flag);
void	ft_usage(void);

/*------------------------
	mandelbrot
------------------------*/
void	mandelbrot_set(double x, double y, t_data *mlx);
void	mandelbrot(t_data *mlx);
void	start_mandelbrot(t_data *mlx);

/*------------------------
	julia
------------------------*/
void	julia_set(double x, double y, t_data *mlx);
void	julia(t_data *mlx);
void	start_julia(t_data *mlx);

/*------------------------
	julia_arg
------------------------*/
void	init_julia(t_data *mlx, char **argv);
float	my_pow(int decimal_places);
int		what_sign(char *str, int *sign);
float	ft_strtod(char *str, int decimal_found, int decimal_places, int i);

/*------------------------
	burning_ship
------------------------*/
void	burning_set(double x, double y, t_data *mlx);
void	burning(t_data *mlx);
void	start_burning(t_data *mlx);

/*------------------------
	utils
------------------------*/
int		ft_exit(void);
int		ft_strcmp(char *s1, char *s2);
void	move(int keycode, t_data *mlx);
int		keys(int keycode, t_data *mlx);
int		zoom(int keycode, int x, int y, t_data *mlx);

#endif
