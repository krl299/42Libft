/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:33:35 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:33:46 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies n bytes from memory area src to memory area dst.
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*str1;
	char	*str2;

	if (dst == 0 && src == 0)
		return (0);
	count = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	while (count < n)
	{
		str1[count] = str2[count];
		count++;
	}
	return (dst);
}
