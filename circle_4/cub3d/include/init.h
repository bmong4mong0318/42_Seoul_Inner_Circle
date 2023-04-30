/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:49:41 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:49:43 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "cub3D.h"

// init.c
void	init_game(t_game *game, char *file);
void	init_camera_angle(t_game *game);
void	init_texture(t_game *game);
void	init_mlx_setting(t_game *game);

#endif
