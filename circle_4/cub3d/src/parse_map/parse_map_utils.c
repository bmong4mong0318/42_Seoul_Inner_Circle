/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:16 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:56:18 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

int	open_file(char *file, int line_idx)
{
	int		i;
	int		map_fd;
	char	*line;

	i = 0;
	map_fd = open(file, O_RDONLY, 0644);
	while (i < line_idx)
	{
		line = get_next_line(map_fd);
		free(line);
		i++;
	}
	return (map_fd);
}
