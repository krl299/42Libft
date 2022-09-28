/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:18:02 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:23:00 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Test for any character for which isalpha or isdigit is true.
int	ft_isalnum(int argument)
{
	if (ft_isalpha(argument) || ft_isdigit(argument))
		return (1);
	else
		return (0);
}
