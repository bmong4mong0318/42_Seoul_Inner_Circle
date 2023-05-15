/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:49:53 by dayun             #+#    #+#             */
/*   Updated: 2023/05/15 16:42:18 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3D.h"

// error.c
void	print_error(char *msg, char *arg);
void	error_exit(char *msg, char *arg, t_game *game);

// free.c
t_bool	free_and_return_false(void *arg);
void	free_args(int count, ...);

#endif
