/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 12:12:26 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/06/08 12:33:23 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
// Computes the length of the string.
size_t	ft_strlen(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

// Locates the first occurrence od c in the string pointed to by str.
char	*ft_strchr(const char *str, int c)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr)
	{
		if (*ptr == (char)c)
			return (ptr);
		ptr++;
	}
	if (*ptr == c)
		return (ptr);
	return (0);
}

//
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

// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of s1 and s2.
char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	size;
	char	*ptr;
	int		count;

	size = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	ptr = (char *)malloc(sizeof(char) * size);
	if (!ptr)
		return (ptr);
	count = 0;
	while (*s1)
		ptr[count++] = *s1++;
	while (*s2)
		ptr[count++] = *s2++;
	ptr[count] = 0;
	return (ptr);
}

// Computes the length of a line on a string.
size_t	ft_len_line(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	return (i);
}
