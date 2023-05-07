/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yundaehyeok <yundaehyeok@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:49:36 by dayun             #+#    #+#             */
/*   Updated: 2023/05/07 15:04:31 by yundaehyeok      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOKS_H
# define HOOKS_H

// hooks.c
int		exit_hook(t_game *game);
int		move_player(int key, t_game *game);

// handle_camera_rotation.c
void	handle_camera_rotation(int key, t_game *game);

// handle_player_move.c
void	handle_player_move(int key, t_game *game);

#endif
