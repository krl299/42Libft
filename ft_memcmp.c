/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:32:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:33:19 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Compares byte string s1 against byte string s2. 
// Both strings are assumed to be n bytes long.
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			count;
	unsigned char	*str1;
	unsigned char	*str2;

	count = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (count < n)
	{
		if (str1[count] == str2[count])
			count++;
		else
			return (str1[count] - str2[count]);
	}
	return (0);
}
