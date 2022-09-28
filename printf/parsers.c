/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:00 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/07/22 13:45:00 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	check to do correctly the conversions
t_arg	ft_parse_arg(t_printf *pr)
{
	t_arg	arg;

	ft_t_arg_init(&arg);
	ft_parse_flags(pr, &arg);
	ft_parse_width(pr, &arg);
	ft_parse_precision(pr, &arg);
	ft_parse_length(pr, &arg);
	ft_parse_specifier(pr, &arg);
	return (arg);
}

//	check for what type of flags has the conversion
void	ft_parse_flags(t_printf *pr, t_arg *arg)
{
	long int	flags;

	flags = 0;
	while (ft_corresponding(pr->fmt[pr->i], "-+ #0"))
	{
		if (pr->fmt[pr->i] == '-')
			flags |= LEFT_JUSTIFY;
		if (pr->fmt[pr->i] == '+')
			flags |= SHOW_SIGN;
		if (pr->fmt[pr->i] == ' ')
			flags |= NO_SIGN;
		if (pr->fmt[pr->i] == '#')
			flags |= SHOW_PREFIX;
		if (pr->fmt[pr->i] == '0')
			flags |= PAD_ZERO;
		pr->i += 1;
	}
	arg->flags = flags;
}

//	check the width of conversion
void	ft_parse_width(t_printf *pr, t_arg *arg)
{
	int			width;
	long int	flags;

	width = 0;
	flags = arg->flags;
	while (ft_corresponding(pr->fmt[pr->i], "*0123456789"))
	{
		if (pr->fmt[pr->i] == '*')
		{
			width = va_arg(pr->args, int);
			if (width < 0)
			{
				flags |= LEFT_JUSTIFY;
				width = width * (-1);
			}
		}
		else
			width = width * 10 + (pr->fmt[pr->i] - '0');
		pr->i += 1;
	}
	arg->width = width;
	arg->flags = flags;
}

//	check the presicion of conversion
void	ft_parse_precision(t_printf *pr, t_arg *arg)
{
	int	precision;

	if (pr->fmt[pr->i] == '.')
	{
		arg->has_precision = 1;
		pr->i += 1;
	}
	precision = 0;
	while (ft_corresponding(pr->fmt[pr->i], "*0123456789"))
	{
		if (pr->fmt[pr->i] == '*')
			precision = va_arg(pr->args, int);
		else
			precision = precision * 10 + (pr->fmt[pr->i] - '0');
		pr->i += 1;
	}
	arg->precision = precision;
}

//	check the type of conversion need to do
void	ft_parse_specifier(t_printf *pr, t_arg *arg)
{
	char	specifier;

	specifier = '\0';
	if (ft_corresponding(pr->fmt[pr->i], "diuxXpcs%nfge"))
	{
		specifier = pr->fmt[pr->i];
		pr->i += 1;
	}
	arg->specifier = specifier;
}
