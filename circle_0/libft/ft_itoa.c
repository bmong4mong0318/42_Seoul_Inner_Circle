/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayun <dayun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 21:12:18 by dayun             #+#    #+#             */
/*   Updated: 2022/07/15 21:23:46 by dayun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_len(long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	too_long(long long	*nn, char *result)
{
	if (*nn < 0)
	{
		*nn *= -1;
		result[0] = '-';
	}
}

char	*ft_itoa(int n)
{
	int			len;
	char		*result;
	long long	nn;

	nn = n;
	len = nbr_len(nn);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (result);
	if (nn == 0)
	{
		result[0] = '0';
		result[len] = '\0';
		return (result);
	}
	too_long(&nn, result);
	result[len] = '\0';
	while (nn > 0)
	{
		result[len - 1] = (nn % 10) + '0';
		nn /= 10;
		len--;
	}
	return (result);
}
