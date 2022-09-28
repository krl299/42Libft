/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:37:07 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 15:12:00 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Allocates (with malloc(3)) and returns a substring from the string ’s’.
// The substring begins at index ’start’ and is of maximum size ’len’.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	count;
	size_t	size;
	size_t	length_s;

	if (!s || start > ft_strlen(s))
		return (ft_strdup(""));
	length_s = ft_strlen(s);
	if ((length_s - start) > len)
		size = len + 1;
	else
		size = length_s - start + 1;
	if (start >= length_s)
		size = 1;
	substr = (char *)malloc(sizeof(char) * size);
	if (!substr)
		return (substr);
	count = 0;
	while (s[start + count] && count < len && start < length_s)
	{
		substr[count] = s[count + start];
		count++;
	}
	substr[count] = 0;
	return (substr);
}
