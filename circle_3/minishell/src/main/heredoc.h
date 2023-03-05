/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:39:29 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:39:30 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEREDOC_H
# define HEREDOC_H

# include "../lexer/token.h"

void	expand_quote(t_string *str, t_iterator *iter, char quote_type);
bool	is_limiter(const char *line, const char *limiter);
char	*readline_prompt_heredoc(void);
int		set_heredoc(t_list *tokens);

#endif /* HEREDOC_H */
