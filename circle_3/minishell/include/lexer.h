/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:25:48 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:25:50 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
# define LEXER_H

/* Libft functions */
# include "./libft.h"

/* t_string header */
# include "../src/string/string.h"
# include "../src/iterator/iterator.h"
# include "../src/lexer/token.h"
# include "../src/lexer/scanner.h"

/* @ Returns t_token list.
 * @ NOTE : doesn't check synstax error!
 * */
extern t_list	*tokenize(char *line);

#endif /* LEXER_H */
