/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handle.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:40:14 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:40:15 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIGNAL_HANDLE_H
# define SIGNAL_HANDLE_H

# include "signal_handle.h"
# include "minishell.h"

void	*new_pid(pid_t pid);
void	del_pid(void *content);

/* Waits every pids in config->pid_list.
 * then saves wstatus of last_cmd_pid to config->last_cmd_wstatus */
void	wait_every_pid(t_shell_config *config);

#endif /* SIGNAL_HANDLE_H */
