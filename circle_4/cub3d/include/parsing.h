/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:49:48 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 16:41:53 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include "libft.h"
#include "cub3D.h"

enum
{
	NAME,
	VALUE
};

// map_info_utils.c
t_bool is_valid_file_extension(char *str);
t_bool is_file_openable(char *file);
int number_of_str(char **info_value);
char **error_check_and_split(t_info *info, t_game *game);

// map_info_validation.c
void map_info_validation(t_game *game);

// input_line_info.c
int input_line_info(char *line, t_game *game);

// save_floor_ceiling_info.c
void save_floor_ceiling_info(t_info *info, t_game *game);
t_bool is_valid_separator_count(char *line);
t_bool is_valid_rgb_value(char **values, t_game *game);
void check_space_in_value(char *value, t_game *game);
unsigned char save_rgb_value(char *line);

// map_validation.c
void map_validation(t_game *game, char *file);

// is_valid_line.c
t_bool is_valid_line(int map_fd);

// is_one_player.c
t_bool is_one_player(int map_fd, t_game *game);

// save_map.c
void get_width_and_height(t_game *game, int map_fd);
void save_map(t_game *game, int map_fd);

// check_wall.c
t_bool check_wall(int height_idx, int width_idx, t_game *game);

// parse_utils.c
int open_file(char *file, int line_idx);

#endif
