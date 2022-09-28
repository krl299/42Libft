/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_length_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:44:52 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/22 13:44:52 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	check the length prefix
void	ft_parse_length(t_printf *pr, t_arg *arg)
{
	char	length;

	length = '\0';
	if (ft_corresponding(pr->fmt[pr->i], "hljztL"))
	{
		length = pr->fmt[pr->i];
		pr->i += 1;
	}
	arg->length = length;
}
