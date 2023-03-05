/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:28:02 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:28:03 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIRECTION_H
# define REDIRECTION_H

# include "../main/minishell.h"
# include "../lexer/token.h"

char	*expand_line_each(char *line, t_shell_config *config);
int		expand_file(t_token *tok, t_shell_config *config);

#endif/* REDIRECTION_H */
