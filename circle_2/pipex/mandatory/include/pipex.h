/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:56:59 by dayun             #+#    #+#             */
/*   Updated: 2023/02/03 15:35:18 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* to perror */
# include <stdio.h>

/* to libft */
# include "../../libft/libft.h"

# define FALSE			0
# define TRUE			1
# define FAIL			0
# define SUCCESS		1
# define ERROR			2
# define ERR_INFILE 	"Infile"
# define ERR_OUTFILE 	"Outfile"
# define ERR_INPUT		"Invalid number of arguments.\n"
# define ERR_PIPE		"Pipe"
# define ERR_ENVP		"Environment"
# define ERR_CMD		"Command not found"
# define ERR_HEREDOC	"here_doc"

typedef struct s_cmd
{
	char	**cmd;
	char	*path;
}				t_cmd;

typedef struct s_env
{
	int				*pipe;
	char			**envp;
	char			**path;
	char			**hd_cmd;
	int				here_doc;
	int				result;
	int				n_cmd;
	int				i_fd;
	int				o_fd;
	int				idx;
	pid_t			pid;
	struct s_cmd	*cmd;
}	t_env;

/* fd.c */
int		args_in(char *arg);
void	here_doc(char *limiter, t_env *info);
void	get_fd(t_env *info, int argc, char **argv);
void	parent_free(t_env *info);

/* parse.c */
void	parse_cmd(t_env *info, int argc, char **argv);
void	check_cmd(t_env *info, char **argv);
void	find_awk_sed(char **argv, int i, t_env *info);
void	find_awk_sed2(t_env *info, char **tmp_info, int i, int tmp);
char	*get_cmd_argv(char **path, char *cmd);

/* utils.c */
void	exit_perror(char *msg, int code);
void	split_free(char **to_free);
void	close_pipes(t_env *info);
char	*find_path(char **envp);

#endif
