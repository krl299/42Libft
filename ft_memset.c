/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:30:37 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:31:26 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes len bytes of value c (converted to an unsigned char)
// to the string b.
void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	char	*end;

	str = (char *)b;
	end = str + len;
	while (str < end)
	{
		*str++ = c;
	}
	return (b);
}
