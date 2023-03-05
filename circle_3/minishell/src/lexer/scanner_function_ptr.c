/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scanner_function_ptr.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:29:52 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:29:54 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scanner.h"

int	scanner_has_next(t_scanner *scan)
{
	return (scan->iter.f_has_next(&(scan->iter)));
}

char	scanner_next(t_scanner *scan)
{
	return (scan->iter.f_next(&(scan->iter)));
}

void	scanner_unget(t_scanner *scan)
{
	scan->iter.f_unget(&(scan->iter));
}

char	scanner_peek(t_scanner *scan)
{
	return (scan->iter.f_peek(&(scan->iter)));
}

void	scanner_skip_white_space(t_scanner *scan)
{
	scan->iter.f_skip_white_space(&(scan->iter));
}
