/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:16:35 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:22:38 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Test for any lower-case letters.
int	ft_islower(int arg)
{
	if (arg >= 'a' && arg <= 'z')
		return (1);
	else
		return (0);
}

//Test for any upper-case letters.
int	ft_isupper(int arg)
{
	if (arg >= 'A' && arg <= 'Z')
		return (1);
	else
		return (0);
}

// Test for any character for which isupper or islower is true.
int	ft_isalpha(int argument)
{
	if (ft_islower(argument) || ft_isupper(argument))
		return (1);
	else
		return (0);
}
