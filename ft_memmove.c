/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:33:54 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:34:31 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies len bytes from string src to string dst.
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	count;
	char	*str1;
	char	*str2;

	if (dst == 0 && src == 0)
		return (0);
	count = 0;
	str1 = (char *)dst;
	str2 = (char *)src;
	if (str1 < str2)
	{
		while (count < len)
		{
			str1[count] = str2[count];
			count++;
		}
	}
	else
	{
		while (count < len--)
		{
			str1[len] = str2[len];
		}
	}
	return (dst);
}
