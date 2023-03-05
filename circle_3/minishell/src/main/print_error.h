/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 20:39:56 by dayun             #+#    #+#             */
/*   Updated: 2023/03/05 20:39:57 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_ERROR_H
# define PRINT_ERROR_H

void	print_error_syntax_char(char err_char);
void	print_error_syntax_str(char *err_str);
void	print_error_redir(char *filename);
void	ft_perror(char *message);
void	print_error_cd(char *filename);
void	print_error_command(char *command);

#endif