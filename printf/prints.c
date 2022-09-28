/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:09 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:33:10 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	print the conversion done
void	ft_do_print(t_formatted *f)
{
	if (f->left_justify == 0)
		ft_putspace(f->spaces, ' ');
	ft_putchar(f->sign);
	if (f->prefix == 'x')
		ft_putstr("0x");
	if (f->prefix == 'X')
		ft_putstr("0X");
	ft_putspace(f->zeroes, '0');
	if (f->c_null == 1)
		write(1, "\0", 1);
	else
		ft_putstr(f->content);
	if (f->left_justify == 1)
		ft_putspace(f->spaces, ' ');
}

//	count the numbers of char are printed
int	ft_count_printed(t_formatted *f)
{
	int	count;

	if (f->c_null == 1)
		count = 1;
	else
		count = ft_print_strlen(f->content);
	count += f->zeroes;
	count += f->spaces;
	if (f->sign != '\0')
		count += 1;
	if (f->prefix != '\0')
		count += 2;
	return (count);
}

//	check to start printing
int	ft_print_arg(t_printf *pr, t_arg *arg)
{
	int			count;
	t_formatted	f;

	ft_t_formatted_init(&f);
	ft_handle_specifier(pr, arg, &f);
	ft_handle_flags(arg, &f);
	ft_handle_width(arg, &f);
	ft_do_print(&f);
	count = ft_count_printed(&f);
	ft_t_formatted_free(&f);
	return (count);
}
