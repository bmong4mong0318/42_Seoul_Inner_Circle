/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:35:07 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:35:09 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

t_print	*init_info_malloc(void)
{
	t_print	*pa_info;

	pa_info = malloc(sizeof(*pa_info));
	pa_info->state = PRINTF_NORMAL;
	pa_info->print_cnt = 0;
	return (pa_info);
}

void	reset_state(t_print *_info)
{
	_info->state = PRINTF_NORMAL;
}
