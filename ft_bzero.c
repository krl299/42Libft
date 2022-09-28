/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:34:45 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:35:17 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Writes n zeroed bytes to the string s.
void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	count;

	str = (char *)s;
	if (n != 0)
	{
		count = 0;
		while (count < n)
		{
			str[count++] = 0;
		}
	}
}
