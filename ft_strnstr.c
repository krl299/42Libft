/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:29:46 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 16:23:52 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Locates the first occurrence of the null-terminated string needle 
// in the string haystack, when not more than len characters are searched
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	count;
	size_t	length;

	length = ft_strlen(needle);
	if (!length)
		return ((char *)haystack);
	if (!len)
		return (0);
	count = 0;
	while (haystack[count] && count <= (len - length) && len >= length)
	{
		if (!ft_strncmp(&haystack[count], needle, length))
			return ((char *) &haystack[count]);
		count++;
	}
	return (0);
}
