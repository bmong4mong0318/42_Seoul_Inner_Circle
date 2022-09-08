/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:56:37 by dayun             #+#    #+#             */
/*   Updated: 2022/09/08 20:45:57 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"

# define ZEROPAD	1				/* pad with zero */
# define SIGN		2				/* negative num */
# define PLUS		4				/* show sign */
# define SPACE		8				/* space if plus */
# define LEFT		16				/* left justified */
# define SMALL		32				/* small alphabet */
# define SPECIAL	64				/* 0x and 0X */
# define TYPE 		"csdpdiuxX%" 	/* specifier */

typedef struct s_tag
{
	char		sign;
	int			flags;
	int			field_width;
	int			precision;
	int			prec;
	int			flag_width;
	int			base;
	int			base_len;
	int			size;
	int			locase;
	int			flag_num;
	int			flag_dot;
	int			flag_p;
	int			flag_c;
}				t_tag;

/*------------------------
	  format_functions
------------------------*/
char			*ft_format_c(char *buf, va_list ap, t_tag *tag);
char			*ft_format_s(char *buf, va_list ap, t_tag *tag);
char			*ft_format_p(char *buf, va_list ap, t_tag *tag);
char			*ft_format_d(char *buf, va_list ap, t_tag *tag);
char			*ft_format_i(char *buf, va_list ap, t_tag *tag);
char			*ft_format_u(char *buf, va_list ap, t_tag *tag);
char			*ft_format_lowerx(char *buf, va_list ap, t_tag *tag);
char			*ft_format_upperx(char *buf, va_list ap, t_tag *tag);
char			*ft_format_percent(char *buf, va_list ap, t_tag *tag);

/*------------------------
	   utils_functions
------------------------*/
int				do_div(long long *n, int base);
int				do_div_hex(unsigned long *n, int base);
size_t			ft_strnlen(const char *s, t_tag *tag);
int				check_null_size(const char *s, t_tag *tag);

/*------------------------
	   print_functions
------------------------*/
long long		fill_sign(long long num, t_tag *tag);
char			*fill_special(char *buf, long long num, t_tag *tag);
char			*fill_special_hex(char *buf, unsigned long num, t_tag *tag);
char			*fill_num(char *buf, long long num, t_tag *tag);
char			*fill_num2(char *buf, long long num, t_tag *tag, char *tmp);
char			*fill_hex(char *buf, unsigned long num, t_tag *tag);
char			*fill_hex2(char *buf, unsigned long num, t_tag *tag, char *tmp);
char			*fill_hex3(char *buf, unsigned long num, t_tag *tag, char *tmp);
int				print_buf(char *str, int len);

/*------------------------
	   main_functions
------------------------*/
static char		*parse_spc(char *buf, va_list ap, const char *fmt, t_tag *tag);
static void		check_flags(va_list ap, const char *fmt, t_tag *tag);
static void		init_tag(t_tag *tag);
static int		parse_buf(char *buf, va_list ap, const char *fmt, t_tag *tag);
int				ft_printf(const char *fmt, ...);

#endif