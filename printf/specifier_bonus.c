/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:16 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/22 13:45:16 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	conversion for spec 'n'
void	ft_spec_n(t_printf *pr)
{
	int	*n;

	n = va_arg(pr->args, int *);
	*n = pr->count;
}
