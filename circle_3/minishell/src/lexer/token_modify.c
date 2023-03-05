/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_modify.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:30:32 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:30:34 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "token.h"

void	token_reset(t_token *token)
{
	t_string	*string;

	string = token->str;
	string->f_clear(string);
	token->type = E_TYPE_DEFAULT;
}

void	token_push_back(t_token *token, char c)
{
	t_string	*string;

	string = token->str;
	string->f_push_back(string, c);
}

void	token_pop_back(t_token *token)
{
	t_string	*string;

	string = token->str;
	string->f_pop_back(string);
}

void	token_append(t_token *token, const char *str_in)
{
	t_string	*string;

	string = token->str;
	string->f_append(string, str_in);
}

void	delete_token(void *_token)
{
	t_token	*token;

	token = _token;
	if (token->heredoc_fd != -1)
		close(token->heredoc_fd);
	if (token->str != NULL)
		delete_string(&token->str);
	free(token);
}
