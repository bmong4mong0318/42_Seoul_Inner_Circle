/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:31 by dayun             #+#    #+#             */
/*   Updated: 2023/05/15 16:56:20 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "parsing.h"
#include "utils.h"
#include <fcntl.h>

t_bool	is_valid_file_extension(char *str)
{
	int	str_len;

	str_len = ft_strlen(str);
	if (ft_strcmp(&str[str_len - 4], ".cub") != 0)
		return (FALSE);
	else
		return (TRUE);
}

t_bool	is_file_openable(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY, 0644);
	if (fd == ERROR)
		return (FALSE);
	close(fd);
	return (TRUE);
}

int	number_of_str(char **info_value)
{
	int	count;

	count = 0;
	while (info_value[count] != NULL)
		count += 1;
	return (count);
}

char	**error_check_and_split(t_info *info, t_game *game)
{
	char	**values;

	if (is_valid_separator_count(info->value) == FALSE)
		error_exit("Invalid RGB format", info->value, game);
	values = ft_split(info->value, ',');
	if (number_of_str(values) != 3)
		error_exit("Invalid RGB format", info->value, game);
	if (is_valid_rgb_value(values, game) == FALSE)
		error_exit("Invalid RGB value", info->value, game);
	if (ft_strcmp(info->name, "F") == 0 && game->floor != NULL)
		error_exit("Map error", info->name, game);
	if (ft_strcmp(info->name, "C") == 0 && game->ceiling != NULL)
		error_exit("Map error", info->name, game);
	return (values);
}
