/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:19:51 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:23:48 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert a lower-case letter to the corresponding upper-case letter.
int	ft_toupper(int ch)
{
	if (ft_islower(ch))
		return (ch - 32);
	else
		return (ch);
}
