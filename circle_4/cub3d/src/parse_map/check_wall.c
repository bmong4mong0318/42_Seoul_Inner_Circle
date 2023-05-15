/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:02 by dayun             #+#    #+#             */
/*   Updated: 2023/05/15 16:51:00 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "cub3D.h"

static t_bool	check_right(int height_idx, int width_idx, t_game *game)
{
	int	h_cur_idx;
	int	w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (width_idx == game->map.width - 1)
		return (FALSE);
	w_cur_idx += 1;
	while (w_cur_idx <= game->map.width - 1)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			w_cur_idx += 1;
		else
			w_cur_idx += 1;
	}
	return (FALSE);
}

static t_bool	check_left(int height_idx, int width_idx, t_game *game)
{
	int	h_cur_idx;
	int	w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (width_idx == 0)
		return (FALSE);
	w_cur_idx -= 1;
	while (w_cur_idx >= 0)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			w_cur_idx -= 1;
		else
			w_cur_idx -= 1;
	}
	return (FALSE);
}

static t_bool	check_down(int height_idx, int width_idx, t_game *game)
{
	int	h_cur_idx;
	int	w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (height_idx == game->map.height - 1)
		return (FALSE);
	h_cur_idx += 1;
	while (h_cur_idx <= game->map.height - 1)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			h_cur_idx += 1;
		else
			h_cur_idx += 1;
	}
	return (FALSE);
}

static t_bool	check_up(int height_idx, int width_idx, t_game *game)
{
	int	h_cur_idx;
	int	w_cur_idx;

	h_cur_idx = height_idx;
	w_cur_idx = width_idx;
	if (height_idx == 0)
		return (FALSE);
	h_cur_idx -= 1;
	while (h_cur_idx >= 0)
	{
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '\0')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == ' ')
			return (FALSE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '1')
			return (TRUE);
		if (game->map.map_array[h_cur_idx][w_cur_idx] == '0')
			h_cur_idx -= 1;
		else
			h_cur_idx -= 1;
	}
	return (FALSE);
}

t_bool	check_wall(int height_idx, int width_idx, t_game *game)
{
	if (check_up(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_down(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_left(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	if (check_right(height_idx, width_idx, game) == FALSE)
		return (FALSE);
	else
		return (TRUE);
}
