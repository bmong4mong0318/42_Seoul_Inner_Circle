/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ_helper2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:26:26 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:26:27 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environ.h"
#include "../main/helper.h"

/** while copying, add declare -x and quote " "  */
void	copy_strs_for_export(char **dst, char **src, size_t strs_count)
{
	size_t		i;
	t_string	*str;

	i = 0;
	str = new_string(64);
	while (i < strs_count)
	{
		str->f_clear(str);
		str->f_append(str, "declare -x ");
		str->f_append(str, src[i]);
		str->f_replace(str, ft_strchr(str->text, '=') - str->text, 1, "=\"");
		str->f_push_back(str, '\"');
		dst[i] = ft_strdup(str->text);
		i++;
	}
	delete_string(&str);
	dst[strs_count] = NULL;
}
