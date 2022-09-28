/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:22 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:35:03 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	conversion for specs "diuxX"
void	ft_spec_number(t_printf *pr, t_arg *arg, t_formatted *f)
{
	int	nbr;

	nbr = va_arg(pr->args, int);
	if (nbr < 0 && ft_corresponding(arg->specifier, "di"))
	{
		f->sign = '-';
		nbr = -nbr;
	}
	if (nbr == 0 && arg->precision == 0 && arg->has_precision == 1)
		return ;
	if (ft_corresponding(arg->specifier, "diu"))
		f->content = ft_itoa_base(nbr, "0123456789", arg->specifier);
	if (arg->specifier == 'x')
		f->content = ft_itoa_base(nbr, "0123456789abcdef", arg->specifier);
	if (arg->specifier == 'X')
		f->content = ft_itoa_base(nbr, "0123456789ABCDEF", arg->specifier);
}

//	conversion to string
void	ft_spec_string(t_printf *pr, t_arg *arg, t_formatted *f)
{
	char	*str;
	int		len;

	str = va_arg(pr->args, char *);
	if (str == NULL)
	{
		if (arg->precision >= 6 || arg->precision < 0
			|| arg->has_precision == 0)
			len = ft_print_strlen("(null)");
		else
			len = arg->precision;
		f->content = malloc(sizeof(char) * (len + 1));
		ft_print_strlcpy(f->content, "(null)", len + 1);
		return ;
	}
	if (arg->precision == 0 && arg->has_precision == 1)
		return ;
	len = ft_print_strlen(str);
	if (arg->precision > len || arg->precision < 0 || arg->has_precision == 0)
		len = ft_print_strlen(str);
	else
		len = arg->precision;
	f->content = malloc(sizeof(char) * (len + 1));
	ft_print_strlcpy(f->content, str, len + 1);
}

//	conversion to char
void	ft_spec_char(t_printf *pr, t_formatted *f)
{
	char	c;

	c = va_arg(pr->args, int);
	f->content = malloc(sizeof(char) * 2);
	if (c == 0)
	{
		f->c_null = 1;
		return ;
	}
	f->content[0] = c;
	f->content[1] = '\0';
	return ;
}

//	conversion to %
void	ft_spec_percent(t_arg *arg, t_formatted *f)
{
	f->content = malloc(sizeof(char) * 2);
	f->content[0] = '%';
	f->content[1] = '\0';
	f->prefix = '\0';
	f->sign = '\0';
	f->zeroes = 0;
	arg->precision = 0;
}

//	conversion to pointer
void	ft_spec_pointer(t_printf *pr, t_formatted *f)
{
	long int	ptr;
	int			len;

	ptr = va_arg(pr->args, long int);
	if (ptr == 0)
	{
		len = ft_print_strlen("0x0");
		f->content = malloc(sizeof(char) * (len + 1));
		ft_print_strlcpy(f->content, "0x0", len + 1);
	}
	else
		f->content = ft_itoa_base_ptr(ptr, 16);
}
