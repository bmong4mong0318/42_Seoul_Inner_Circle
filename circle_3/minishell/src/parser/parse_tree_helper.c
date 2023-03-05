/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tree_helper.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:40:19 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:40:21 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_tree.h"

bool	is_type_redir_arg(t_list *target_next)
{
	t_token	*tok;

	tok = target_next->content;
	if (tok->type == E_TYPE_REDIR_ARG \
			|| tok->type == E_TYPE_REDIR_ARG_HEREDOC_QUOTED)
		return (true);
	else
		return (false);
}
