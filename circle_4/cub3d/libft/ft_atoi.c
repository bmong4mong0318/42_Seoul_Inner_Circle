/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 14:50:23 by dayun             #+#    #+#             */
/*   Updated: 2023/04/30 14:50:25 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_bool	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f' || c == '\t')
		return (TRUE);
	return (FALSE);
}

static int	is_sign_symbol(char c)
{
	if (c == '+' || c == '-')
		return (1);
	return (0);
}

static int	is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long long	calculate_result(const char *str, int i, int sign)
{
	long long	result;
	long long	temp;

	result = 0;
	while (*(str + i) != '\0' && is_numeric(*(str + i)))
	{
		temp = result;
		result = (result * 10) + (*(str + i) - '0');
		i += 1;
		if (sign == -1 && temp > result)
			result = 0;
		else if (sign == 1 && temp > result)
			result = -1;
		if (temp > 0 && result <= 0)
			break ;
	}
	return (result);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	int			sign_cnt;
	long long	result;

	i = 0;
	sign = 1;
	sign_cnt = 0;
	while (is_whitespace(*(str + i)))
		i += 1;
	while (is_sign_symbol(*(str + i)))
	{
		if (*(str + i) == '-')
			sign = -1;
		i += 1;
		sign_cnt += 1;
		if (sign_cnt >= 2)
			return (0);
	}
	result = calculate_result(str, i, sign);
	return ((int)result * sign);
}
