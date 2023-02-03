/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 21:02:51 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 15:18:54 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.'))
			return (0);
		i++;
	}
	return (1);
}

void	init_julia(t_data *mlx, char **argv)
{
	if (mlx->julia_input_exist == 1 && is_number(argv[2]) && is_number(argv[3]))
	{
		mlx->julia_x = ft_strtod(argv[2], 0, 0, 0);
		mlx->julia_y = ft_strtod(argv[3], 0, 0, 0);
	}
	else
	{	
		mlx->julia_x = 0.285;
		mlx->julia_y = 0.01;
	}
}

float	my_pow(int decimal_places)
{
	int		i;
	float	result;

	i = 0;
	result = 1;
	while (decimal_places != i)
	{
		result *= 10;
		i++;
	}
	return (result);
}

int	what_sign(char *str, int *sign)
{
	int	i;

	i = 0;
	if (str[i] == '-')
	{
		*sign *= -1;
		i++;
	}
	if (str[i] == '+')
		i++;
	return (i);
}

float	ft_strtod(char *str, int decimal_found, int decimal_places, int i)
{
	int		sign;
	float	result;

	sign = 1;
	result = 0;
	i = what_sign(str, &sign);
	while (str[i])
	{
		if (!(('0' <= str[i] && str[i] <= '9') || str[i] == '.'))
			exit(1);
		if (str[i] == '.')
		{
			if (decimal_found == 1)
				exit(1);
			i++;
			decimal_found = 1;
			continue ;
		}
		if (!decimal_found)
			result = result * 10 + (str[i++] - '0');
		else
			result = result + ((float)(str[i++] - '0')
					/ my_pow(++decimal_places));
	}
	return (result * sign);
}
