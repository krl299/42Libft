/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:28:30 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:29:02 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies up to dstsize -1 characters from the string src to dst.
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	count;
	size_t	length;

	length = ft_strlen(src);
	if (dstsize != 0)
	{
		count = 0;
		while (src[count] && count < (dstsize - 1))
		{
			dst[count] = src[count];
			count++;
		}
		dst[count] = '\0';
	}
	return (length);
}
