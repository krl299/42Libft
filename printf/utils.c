/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:40 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:35:44 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	write a char
void	ft_putchar(char c)
{
	if (c != '\0')
		write(1, &c, 1);
}

//	calculate the length of a string
int	ft_print_strlen(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

//	write a string
void	ft_putstr(char *s)
{
	write(1, s, ft_print_strlen(s));
}

//	write char l, len times
void	ft_putspace(int len, char l)
{
	if (len <= 0)
		return ;
	while (len > 0)
	{
		ft_putchar(l);
		len--;
	}
	return ;
}

//	check if exist char on a string
//	used to check the flags,specs,width and other on parsers functions
int	ft_corresponding(char c, char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}
