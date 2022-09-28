/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:19:20 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:23:30 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Test for any printing character, including space.
int	ft_isprint(int arg)
{
	if (arg >= ' ' && arg <= '~')
		return (1);
	else
		return (0);
}
