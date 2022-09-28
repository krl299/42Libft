/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:26:48 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 10:35:19 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the last occurrence of c in the string pointed to by str.
char	*ft_strrchr(const char *str, int c)
{
	char	*ptr;

	ptr = 0;
	while (*str)
	{
		if (*str == (char)c)
			ptr = (char *)str;
		str++;
	}
	if (*str == (char)c)
		ptr = (char *)str;
	return (ptr);
}
