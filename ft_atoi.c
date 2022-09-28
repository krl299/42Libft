/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:08:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 12:19:12 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_result(const long n, int neg)
{
	if (n != (int)n)
	{
		if (neg < 0)
			return (0);
		if (neg > 0)
			return (-1);
	}
	return (n);
}

// Converts the initial portion of the string pointed
// to by str to int representation.
int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	result;

	i = 0;
	neg = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i + 1] == '+' || str[i + 1] == '-')
			return (0);
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9' && str[i] != 0)
	{
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (ft_result(result * neg, neg));
}
