/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:56:31 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:56:33 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
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

int	get_count_of_kv_pair(char **kv_pair)
{
	int	count;

	count = 0;
	while (kv_pair[count] != NULL)
		count += 1;
	return (count);
}
