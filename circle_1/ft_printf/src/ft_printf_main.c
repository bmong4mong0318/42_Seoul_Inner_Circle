/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:44:20 by dayun             #+#    #+#             */
/*   Updated: 2022/09/03 20:47:57 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

static void	init_tag(t_tag *tag)
{
	tag->flags = 0;
	tag->field_width = 0;
	tag->precision = -1;
	tag->flag_width = 0;
	tag->flag_prec = 0;
	tag->flag_percent = 0;
	tag->flag_putstr = 0;
	tag->base_len = 0;
	tag->base = 10;
	tag->preczero = 0;
	tag->flag_final = 0;
}

static void	check_flags(va_list ap, const char *fmt, t_tag *tag)
{
	if (*fmt == '-')
		tag->flags |= LEFT;
	else if (*fmt == '+')
		tag->flags |= PLUS;
	else if (*fmt == ' ')
		tag->flags |= SPACE;
	else if (*fmt == '0' && !tag->flag_width)
		tag->flags |= ZEROPAD;
	else if (*fmt == '#')
		tag->flags |= SPECIAL;
	else if (ft_isdigit(*fmt) && tag->precision == -1)
	{
		tag->field_width = tag->field_width * 10 + *fmt - '0';
		tag->flag_width = 1;
	}
	else if (*fmt == '.')
	{
		tag->precision = 0;
		tag->flag_width = 1;
		tag->flag_prec = 1;
		tag->flags &= ~ZEROPAD;
	}
	else if (ft_isdigit(*fmt) && tag->precision != -1)
	{
		tag->precision = tag->precision * 10 + *fmt - '0';
		if (tag->precision == 0)
			tag->preczero = 1;
		else
			tag->preczero = 2;
	}
}

static void	parsing_specifier(va_list ap, const char *fmt, t_tag *tag)
{
	if (*fmt == 'c')
		ft_format_c(ap, tag);
	else if (*fmt == 's')
		ft_format_s(ap, tag);
	else if (*fmt == 'p')
		ft_format_p(ap, tag);
	else if (*fmt == 'd')
		ft_format_d(ap, tag);
	else if (*fmt == 'i')
		ft_format_i(ap, tag);
	else if (*fmt == 'u')
		ft_format_u(ap, tag);
	else if (*fmt == 'x')
		ft_format_lowerx(ap, tag);
	else if (*fmt == 'X')
		ft_format_upperx(ap, tag);
	else if (*fmt == '%')
		ft_format_percent(ap, tag);
}

static int	count_tag(va_list ap, const char *fmt)
{
	t_tag	tag;

	tag.cnt = 0;
	while (*fmt)
	{
		if (*fmt == '%')
		{
			init_tag(&tag);
			while (*++fmt && !ft_strchr(TYPE, *fmt))
				check_flags(ap, fmt, &tag);
			parsing_specifier(ap, fmt, &tag);
		}
		else
		{
			tag.flag_percent = 0;
			fmt += ft_putstr(fmt, &tag) - 1;
		}
		fmt++;
	}
	return (tag.cnt);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, fmt);
	printed = count_tag(ap, fmt);
	va_end(ap);
	return (printed);
}

// int	main()
// {
//   	int a, b;
//  	char	*c;



	// a = printf("1::%+0.1d::%02.0d//%.d::", 0, 0, 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%+0.1d::%02.0d//%.d::", 0, 0, 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%+7.d:", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%+7.d:", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%02.2x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%02.2x::", 0);
	// ft_printf("\n%d\n\n", b);
	
	// a = printf("1::%01.1x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%01.1x::", 0);
	// ft_printf("\n%d\n\n", b);
	
	// a = printf("1::%-10.d::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-10.d::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%-10.x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-10.x::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%01.0x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%01.0x::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%02.0x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%02.0x::", 0);
	// ft_printf("\n%d\n\n", b);
	
	// a = printf("1::%01x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%01x::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%02x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%02x::", 0);
	// ft_printf("\n%d\n\n", b);


// 	a = printf("1::%7d::", 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%7d::", 0);
// 	ft_printf("\n%d\n\n", b);

// 	a = printf("1::%7u::", 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%7u::", 0);
// 	ft_printf("\n%d\n\n", b);

	// a = printf("1::%7x::%.0x//%x::", 34, 0, 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%7x::%.0x//%x::", 34, 0, 0);
	// ft_printf("\n%d\n\n", b);

// 		a = printf("1::%+7d::%.0d::%.d::", 1, 0, 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%+7d::%.0d::%.d::", 1, 0, 0);
// 	ft_printf("\n%d\n\n", b);

// 	a = printf("1::%-15.2d::%.d::", -123456, 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%-15.2d::%.d::", -123456, 0);
// 	ft_printf("\n%d\n\n", b);

// 	a = printf("1::%-15.2u::%.u::", 123456, 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%-15.2u::%.u::", 123456, 0);
// 	ft_printf("\n%d\n\n", b);

// 	a = printf("1::%-15.2u::%.0u::", 123456, 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%-15.2u::%.0u::", 123456, 0);
// 	ft_printf("\n%d\n\n", b);


// // 	// a = printf("1::%15c::", 'c');
// // 	// printf("\n%d\n\n", a);
// // 	// b = ft_printf("2::%15c::", 'c');
// // 	// ft_printf("\n%d\n\n", b);
//40 

	// a = printf("^.^/%-44.39s:^.^/:", "Do you want to print 333.5K chars? (y/N)");
	// printf("\n%d\n\n", a);
	// b = ft_printf("^.^/%-44.39s:^.^/:", "Do you want to print 333.5K chars? (y/N)");
	// ft_printf("\n%d\n\n", b);

	

	// a = printf("\\!/%-1.46s\\!/", "");
	// printf("\n%d\n\n", a);
	// b = ft_printf("\\!/%-1.46s\\!/", "");
	// ft_printf("\n%d\n\n", b);


	// a = printf("1::%1s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%1s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%2s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%2s::", NULL);
	// ft_printf("\n%d\n\n", b);


	// a = printf("1::%3.6s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%3.6s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%1.3s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%1.3s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%1.7s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%1.7s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%10s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%10s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%.7s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%.7s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%10.1s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%10.1s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%10.7s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%10.7s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%-15.10s::", "string");
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-15.10s::", "string");
	// ft_printf("\n%d\n\n", a);

	// a = printf("1::%.x::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%.x::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%3.00s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%3.00s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%7.5s::", "tubular");
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%7.5s::", "tubular");
	// ft_printf("\n%d\n\n", b); 

	// a = printf("!%-6.1s!", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("!%-6.1s!", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("!%-6.2s!", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("!%-6.2s!", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%-3.8s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-3.8s::", NULL);
	// ft_printf("\n%d\n\n", b);


	// a = printf("1::%#X::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%#X::", 0);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::--.%#Xs::", 0);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::--.%#Xs::", 0);
	// ft_printf("\n%d\n\n", b);


	// a = printf("1::%p is even stranger::", (void *)-1);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%p is even stranger::", (void *)-1);
	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%30.5X::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%30.5X::", 431);
// 	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%.5X::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%.5X::", 431);
// 	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%30.5d::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%30.5d::", 431);
// 	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%#30.5X::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%#30.5X::", 431);
// 	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%-30.5X::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%-30.5X::", 431);
// 	// ft_printf("\n%d\n\n", b);

// 	// a = printf("1::%030X::", 431);
// 	// printf("\n%d\n\n", a);
// 	// b = ft_printf("2::%030X::", 431);
// 	// ft_printf("\n%d\n\n", b);

// a = printf("1::%i::", 0);
// 	printf("\n%d\n\n", a);
// 	b = ft_printf("2::%i::", 0);
// 	ft_printf("\n%d\n\n", b);
	
//  ft_printf("%.3i\n", 0);
//  printf("%.3i\n\n", 0);

//  ft_printf("%8.5i\n", 0);
//  printf("%8.5i\n\n", 0);

//  ft_printf("%-8.5i\n", 0);
//  printf("%-8.5i\n\n", 0);

//  ft_printf("%08.5i\n", 0);
//  printf("%08.5i\n\n", 0);

//  ft_printf("%5.0i:\n", 0);
//  printf("%5.0i:\n\n", 0);

//  ft_printf("%-5.0i:\n", 0);
//  printf("%-5.0i:\n\n", 0);

//  ft_printf("%5.i:\n", 0);
//  printf("%5.i:\n\n", 0);

//  ft_printf("%-5.i:\n", 0);
//  printf("%-5.i:\n\n", 0);


// from here //
	// a = printf("1::%-3s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-3s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%-32s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%-32s::", NULL);
	// ft_printf("\n%d\n\n", b);

	// a = printf("1::%3.1s::", NULL);
	// printf("\n%d\n\n", a);
	// b = ft_printf("2::%3.1s::", NULL);
	// ft_printf("\n%d\n\n", b);

// }
