/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:41:43 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:42:03 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Funtion aux itoa
static char	*ft_auxitoa(char *str, int n, int size)
{
	str[size - 1] = 0;
	size--;
	if (n == 0)
		str[size - 1] = '0';
	while ((size) > 0 && n != 0)
	{
		if (n < 0)
		{
			if (n == -2147483648)
			{
				str[size - 1] = '8';
				n = n / 10;
				size--;
			}
			str[0] = '-';
			n *= -1;
		}
		else
		{
			str[size - 1] = (n % 10) + '0';
			n = n / 10;
			size--;
		}
	}
	return (str);
}

// Allocates (with malloc(3)) and returns a string
// representing the integer received as an argument.
// Negative numbers must be handled.
char	*ft_itoa(int n)
{
	char	*str;
	int		num;
	int		size;

	size = 1;
	num = n;
	while (num != 0)
	{
		num = num / 10;
		size++;
	}
	if (n < 0 || n == 0)
		size++;
	str = (char *)malloc(size * sizeof(char));
	if (!str)
		return (0);
	return (ft_auxitoa(str, n, size));
}
