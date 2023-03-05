/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:25:41 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:25:45 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTE_H
# define EXECUTE_H

# include "../src/executer/executer.h"

/* @ Traverse tokens lists, then execute each node's simple command.
 * returns (0) on error. 
 * else, function returns (1):success
 * */

extern int	execute(t_tree *syntax_tree, t_shell_config *config);

#endif /* EXECUTE_H */
