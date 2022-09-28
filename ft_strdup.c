/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:35:36 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:36:05 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates sufficient memory for a copy of the str s1,
// does the copy, and returns a pointer to it.
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	size_t	len;
	size_t	count;

	len = ft_strlen(s1) + 1;
	ptr = malloc(len);
	if (!ptr)
		return (0);
	count = 0;
	while (s1 && count < len)
	{
		ptr[count] = s1[count];
		count++;
	}
	return (ptr);
}
