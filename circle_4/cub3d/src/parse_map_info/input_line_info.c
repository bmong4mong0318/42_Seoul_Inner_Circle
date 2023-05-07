/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_line_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:36 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 15:15:40 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static char *strjoin_values(char *name, char *line, t_info_type type,
							t_game *game)
{
	char *start;
	char *buffer;
	char **argv;

	start = ft_strnstr(line, name, ft_strlen(line));
	if (type == FLOOR_OR_CEILING)
		start += 1;
	else
		start += 2;
	buffer = ft_strtrim(start, " ");
	if (type == FLOOR_OR_CEILING)
	{
		argv = ft_split(buffer, ',');
		if (number_of_str(argv) != 3)
			error_exit("RGB format error", line, game);
	}
	else
	{
		argv = ft_split(buffer, ' ');
		if (number_of_str(argv) != 1)
			error_exit("Image file error", line, game);
	}
	free_all(argv);
	return (buffer);
}

static void filter_info_type(t_info *info, char **info_value, t_game *game)
{
	if (ft_strcmp(info_value[NAME], "F") == 0 ||
		ft_strcmp(info_value[NAME], "C") == 0)
		info->type = FLOOR_OR_CEILING;
	else if (ft_strcmp(info_value[NAME], "NO") == 0)
		info->type = NO;
	else if (ft_strcmp(info_value[NAME], "SO") == 0)
		info->type = SO;
	else if (ft_strcmp(info_value[NAME], "WE") == 0)
		info->type = WE;
	else if (ft_strcmp(info_value[NAME], "EA") == 0)
		info->type = EA;
	else
		error_exit("Map character error", info_value[NAME], game);
}

static t_info *check_info(char *line, t_game *game)
{
	t_info *info;
	char *trimmed_line;
	char **info_value;

	trimmed_line = ft_strtrim(line, " \n");
	info_value = ft_split(trimmed_line, ' ');
	info = malloc(sizeof(t_info));
	filter_info_type(info, info_value, game);
	info->name = ft_strdup(info_value[NAME]);
	if (number_of_str(info_value) != 2)
		info->value = strjoin_values(info_value[NAME],
									 trimmed_line, info->type, game);
	else
		info->value = ft_strdup(info_value[VALUE]);
	free(trimmed_line);
	free_all(info_value);
	return (info);
}

static void save_wall_info(t_info *info, t_game *game)
{
	char *trimmed_line;

	trimmed_line = ft_strtrim(info->value, " \n");
	if (ft_strcmp(trimmed_line + (ft_strlen(trimmed_line) - 4), ".xpm") != 0)
		error_exit("Invalid file format(.xpm)", trimmed_line, game);
	if (is_file_openable(trimmed_line) == FALSE)
		error_exit("File open error", trimmed_line, game);
	if (info->type == SO && game->wall.so == NULL)
		game->wall.so = trimmed_line;
	else if (info->type == WE && game->wall.we == NULL)
		game->wall.we = trimmed_line;
	else if (info->type == NO && game->wall.no == NULL)
		game->wall.no = trimmed_line;
	else if (info->type == EA && game->wall.ea == NULL)
		game->wall.ea = trimmed_line;
	else
		error_exit("Map error", trimmed_line, game);
}

int input_line_info(char *line, t_game *game)
{
	t_info *info;

	info = check_info(line, game);
	if (info != NULL)
	{
		if (info->type == FLOOR_OR_CEILING)
			save_floor_ceiling_info(info, game);
		else
			save_wall_info(info, game);
		free_args(3, info->name, info->value, info);
	}
	return (1);
}
