/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_floor_ceiling_info.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:40 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 16:39:47 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "utils.h"
#include "parsing.h"

t_bool is_valid_separator_count(char *line)
{
	int idx;
	int count;
	char *trimmed_line;

	idx = 0;
	count = 0;
	trimmed_line = ft_strtrim(line, " \n");
	while (trimmed_line[idx] != '\0')
	{
		if (trimmed_line[idx] == ',')
			count += 1;
		idx += 1;
	}
	free(trimmed_line);
	if (count == 2)
		return (TRUE);
	return (FALSE);
}

void check_space_in_value(char *value, t_game *game)
{
	char **value_split;

	value_split = ft_split(value, ' ');
	if (number_of_str(value_split) != 1)
		error_exit("Invalid RGB format", value, game);
	free_all(value_split);
}

t_bool is_valid_rgb_value(char **values, t_game *game)
{
	int idx;
	int value_idx;
	int result;
	char *value;

	idx = 0;
	while (values[idx] != NULL)
	{
		value = ft_strtrim(values[idx], " ");
		check_space_in_value(value, game);
		value_idx = 0;
		while (value[value_idx] != '\0')
		{
			if (ft_isdigit(value[value_idx]) == FALSE)
				return (free_and_return_false(value));
			value_idx += 1;
		}
		result = ft_atoi(values[idx]);
		if (result < 0 || result > 255)
			return (free_and_return_false(value));
		idx += 1;
		free(value);
	}
	return (TRUE);
}

unsigned char save_rgb_value(char *line)
{
	int result;
	char *trimmed_line;

	trimmed_line = ft_strtrim(line, " ");
	result = ft_atoi(trimmed_line);
	free(trimmed_line);
	return ((unsigned char)result);
}

void save_floor_ceiling_info(t_info *info, t_game *game)
{
	t_rgb *rgb;
	char **values;

	values = error_check_and_split(info, game);
	rgb = malloc(sizeof(t_rgb));
	if (rgb == NULL)
		error_exit("malloc fail", NULL, game);
	rgb->r = save_rgb_value(values[0]);
	rgb->g = save_rgb_value(values[1]);
	rgb->b = save_rgb_value(values[2]);
	rgb->color = (rgb->r << 16) | (rgb->g << 8) | rgb->b;
	if (ft_strcmp(info->name, "F") == 0)
		game->floor = rgb;
	else if (ft_strcmp(info->name, "C") == 0)
		game->ceiling = rgb;
	free_all(values);
}
