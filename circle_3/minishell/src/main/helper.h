/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:39:12 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:39:14 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPER_H
# define HELPER_H

# include <stdio.h>
# include "../../include/lexer.h"
# include "../../include/parse.h"

const char	*get_token_type(t_token_type type);
void		print_tokens(t_list *tokens);
void		print_tree(t_tree *root);
void		print_tree_node(t_list *token);

#endif /* HELPER_H */
