/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:54:45 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:54:49 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# define ERROR			-1
# define BUFFER_SIZE   100

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef enum bool {
	FALSE,
	TRUE
}	t_bool;

typedef struct s_node
{
	int				fd;
	char			*backup;
	char			buf[BUFFER_SIZE];
	struct s_node	*next;
}	t_node;

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}	t_list;

int			ft_atoi(const char *str);
t_bool		is_whitespace(char c);
void		ft_bzero(void *dest, size_t size);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
char		*ft_itoa(int n);
void		*ft_memchr(const void *src, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_memcpy(void *dest, const void *src, ssize_t n);
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memset(void *ptr, int c, size_t len);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr_fd(char *s, int fd);
char		**ft_split(char const *s, char d);
char		**free_all(char **arr);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *src);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlcat(char *dest, const char *src, size_t destsize);
size_t		ft_strlcpy(char *dest, const char *src, size_t destsize);
ssize_t		ft_strlen(const char *s);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strnstr(const char *big, const char *small, size_t len);
char		*ft_strrchr(const char *src, int c);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_substr(char const *s, unsigned int start, size_t len);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_lstsize(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst);
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *),
				void (*del)(void *));
t_list		*ft_lstnew(void *content);
int			ft_strcmp(char *s1, char *s2);

char		*get_next_line(int fd);

int			ft_printf_va_c(char c);
int			ft_printf_va_d(int n);
int			ft_printf_va_p(void *p);
int			ft_printf_va_s(char *s);
int			ft_printf_va_u(unsigned int n);
int			ft_printf_va_x(unsigned int n, char c);
int			ft_printf(const char *str, ...);

#endif