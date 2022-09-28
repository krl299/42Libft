/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:43:19 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:39:42 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "../libft.h"
//	Look if the next position is null or not
int	ft_t_printf_peek(t_printf *pr, char *next)
{
	*next = pr->fmt[pr->i];
	if (*next != '\0')
		return (1);
	return (0);
}

//	Main function
int	ft_printf(const char *format, ...)
{
	t_printf	pr;
	t_arg		arg;
	char		next;

	ft_t_printf_init(&pr, format);
	va_start(pr.args, format);
	while (ft_t_printf_peek(&pr, &next))
	{
		pr.i += 1;
		if (next == '%')
		{
			arg = ft_parse_arg(&pr);
			pr.count += ft_print_arg(&pr, &arg);
		}
		else
		{
			write(1, &next, 1);
			pr.count++;
		}
	}
	va_end(pr.args);
	return (pr.count);
}
/*
#include <stdio.h>
int	main()
{
	//ft_printf("%s", "");
	//printf("%s\n", "");
	//printf("|% s\n", "");
}
*/
