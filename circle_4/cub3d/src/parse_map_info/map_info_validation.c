/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_validation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:26 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 14:00:33 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "utils.h"

static t_bool is_empty_line(char *line)
{
	t_bool result;
	char *trimmed_line;

	result = FALSE;
	trimmed_line = ft_strtrim(line, " \n");
	if (ft_strlen(trimmed_line) == 0)
		result = TRUE;
	free(trimmed_line);
	return (result);
}

static t_bool is_all_map_info_set(t_game *game)
{
	if (game->ceiling == NULL)
		return (FALSE);
	if (game->floor == NULL)
		return (FALSE);
	if (game->wall.no == NULL)
		return (FALSE);
	if (game->wall.so == NULL)
		return (FALSE);
	if (game->wall.ea == NULL)
		return (FALSE);
	if (game->wall.we == NULL)
		return (FALSE);
	return (TRUE);
}

static t_bool is_map_content(char *line)
{
	int idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == '0' || line[idx] == '1')
		{
			while (line[idx] != '\0' && line[idx] != '\n')
			{
				if (line[idx] != '0' && line[idx] != '1')
					return (FALSE);
				else
					idx += 1;
			}
		}
		else if (is_whitespace(line[idx]) == TRUE)
			idx += 1;
		else
			return (FALSE);
	}
	return (TRUE);
}

void map_info_validation(t_game *game)
{
	int count;
	char *line;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(game->map_fd);
		if (line == NULL)
			break;
		if (is_empty_line(line) == FALSE)
		{
			if (is_map_content(line) == TRUE)
			{
				free(line);
				break;
			}
			count += input_line_info(line, game);
		}
		game->line_idx += 1;
		free(line);
	}
	if (count != 6)
		error_exit("Map error", NULL, game);
	if (is_all_map_info_set(game) == FALSE)
		error_exit("Map error", NULL, game);
}
