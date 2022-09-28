/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:42:28 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:42:39 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		count;

	if (!s)
		return (0);
	str = ft_strdup(s);
	if (!str)
		return (0);
	count = 0;
	while (s[count])
	{
		str[count] = f(count, s[count]);
		count++;
	}
	return (str);
}
