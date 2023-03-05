/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:26:00 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:26:02 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "../src/parser/parse_tree.h"

/* @ Convert tokens lists to Abstract Syntax tree 
 *
 * NOTE : must use 'delete_tree_node()' while traversing each node!
 *
 * */
extern t_tree	*parse(t_list *tokens);

#endif /* PARSE_H */
