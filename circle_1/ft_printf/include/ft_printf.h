/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/20 16:56:37 by dayun             #+#    #+#             */
/*   Updated: 2022/09/03 14:10:08 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>  // delete soon

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
	int			cnt;
	int			flags;
	int			field_width;
	int			precision;
	int			flag_width;
	int			flag_prec;
	int			flag_percent;
	int			flag_num;
	int			flag_putstr;
	int			base_len;
	int			prec_len;
	int			base;
	int 		preczero;
	int			precin;
	int			flag_final;
}				t_tag;

/*------------------------
	  format_functions
------------------------*/
void			ft_format_c(va_list ap, t_tag *tag);
void			ft_format_s(va_list ap, t_tag *tag);
void			ft_format_p(va_list ap, t_tag *tag);
void			ft_format_d(va_list ap, t_tag *tag);
void			ft_format_i(va_list ap, t_tag *tag);
void			ft_format_u(va_list ap, t_tag *tag);
void			ft_format_lowerx(va_list ap, t_tag *tag);
void			ft_format_upperx(va_list ap, t_tag *tag);
void			ft_format_percent(va_list ap, t_tag *tag);

/*------------------------
	   utils_functions
------------------------*/
size_t			ft_strnlen(const char *s, t_tag *tag);
void			check_percent(char *str, t_tag *tag);

/*------------------------
	   put_functions
------------------------*/
size_t			ft_putstr(const char *s, t_tag *tag);
void			ft_putchar_int(char c, t_tag *tag);
void			ft_putnbr_uint(unsigned int n, t_tag *tag);
void			ft_putnbr_int(int n, t_tag *tag);

/*------------------------
	   print_functions
------------------------*/
int				do_div(long long *n, int base);
static void		print_sign(t_tag *tag);
static void		print_special(t_tag *tag);
void			ft_put_num(long long num, t_tag *tag);
static void		print_num(t_tag *tag, long long num, int width, char *tmp);

/*------------------------
	   ptr_functions
------------------------*/
int				div_ptr(unsigned long *n, int base);
void			ft_put_ptr(unsigned long num, t_tag	*tag);
static void		print_ptr(t_tag *tag, unsigned long num, int width, char *tmp);

/*------------------------
	   main_functions
------------------------*/
static void		init_tag(t_tag *tag);
static void		check_flags(va_list ap, const char *fmt, t_tag *tag);
static void		parsing_specifier(va_list ap, const char *fmt, t_tag *tag);
static int		count_tag(va_list ap, const char *fmt);
int				ft_printf(const char *fmt, ...);

#endif
