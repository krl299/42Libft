/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:44:39 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:32:35 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	handle how much width has the string
void	ft_handle_width(t_arg *arg, t_formatted *f)
{
	int	len;

	len = ft_count_printed(f);
	if (arg->width > len && ft_corresponding(arg->specifier, "n") != 1)
		f->spaces = arg->width - len;
	if ((arg->flags & PAD_ZERO) != 0 && arg->has_precision == 0
		&& f->left_justify != 1)
	{
		if (ft_corresponding(arg->specifier, "diuxX%"))
		{
			f->zeroes = f->spaces;
			f->spaces = 0;
		}
	}
}

//	handle what flags has the string
void	ft_handle_flags(t_arg *arg, t_formatted *f)
{
	if ((arg->flags & LEFT_JUSTIFY) != 0)
		f->left_justify = 1;
	if ((arg->flags & SHOW_SIGN) != 0 && f->sign != '-')
		f->sign = '+';
	if ((arg->flags & NO_SIGN) != 0 && f->sign == '\0')
		f->sign = ' ';
	if ((arg->flags & SHOW_PREFIX) != 0)
		if (ft_corresponding(arg->specifier, "xX"))
			if (f->content != NULL && f->content[0] != '0')
				f->prefix = arg->specifier;
}

//	handle precision of 0 flag
void	ft_handle_zeroes(t_arg *arg, t_formatted *f)
{
	int	len;

	len = ft_print_strlen(f->content);
	if (arg->precision > 0 && arg->precision > len)
		f->zeroes = arg->precision - len;
}

//	handle the conversion
void	ft_handle_specifier(t_printf *pr, t_arg *arg, t_formatted *f)
{
	if (ft_corresponding(arg->specifier, "diuxX"))
	{
		ft_spec_number(pr, arg, f);
		ft_handle_zeroes(arg, f);
	}
	else if (arg->specifier == 's')
		ft_spec_string(pr, arg, f);
	else if (arg->specifier == 'c')
		ft_spec_char(pr, f);
	else if (arg->specifier == 'p')
		ft_spec_pointer(pr, f);
	else if (arg->specifier == '%')
		ft_spec_percent(arg, f);
	else if (arg->specifier == 'n')
		ft_spec_n(pr);
}
