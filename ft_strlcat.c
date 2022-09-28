/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:29:22 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 16:57:58 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Appends string src to the end of dst.
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	len;

	len = 0;
	while (*dst && dstsize)
	{
		len++;
		dst++;
		dstsize--;
	}
	while (*src && dstsize > 1)
	{
		*dst++ = *src++;
		len++;
		dstsize--;
	}
	if (dstsize)
		*dst = '\0';
	while (*src++)
		len++;
	return (len);
}
