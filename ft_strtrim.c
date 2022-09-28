/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:48:01 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:49:06 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

//	Find a char in to string.
static int	ft_strfind(char c, const char *str)
{
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

// Allocates (with malloc(3)) and returns a copy of s1 with the characters
// specified in set removed from the beginning and the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	count;

	start = 0;
	while (ft_strfind(s1[start], set))
		start++;
	end = 0;
	count = 0;
	while (s1[start + count])
	{
		if (!ft_strfind(s1[start + count], set))
			end = count + 1;
		count++;
	}
	return (ft_substr(s1, start, end));
}
