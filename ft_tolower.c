/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:21:11 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:21:38 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Convert a upper-case letter to the corresponding lower-case letter.
int	ft_tolower(int ch)
{
	if (ft_isupper(ch))
		return (ch + 32);
	else
		return (ch);
}
