/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:37:28 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:40:13 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a new string,
// which is the result of the concatenation of s1 and s2.
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(len);
	if (!str)
		return (0);
	ft_bzero((void *)str, len);
	str = ft_strcat(ft_strcat(str, s1), s2);
	return (str);
}

//	Concatenate s2 to s1.
char	*ft_strcat(char *s1, const char *s2)
{
	size_t	count;
	size_t	len1;
	size_t	len2;

	count = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (count < len2 && s2)
	{
		s1[len1 + count] = s2[count];
		count ++;
	}
	s1[len1 + count] = 0;
	return (s1);
}
