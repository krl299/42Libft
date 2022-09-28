/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 13:45:34 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/09/28 16:36:44 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//	Calculate the length of a pointer
int	ft_len_ptr(long int nb)
{
	int					i;
	long unsigned int	unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (0);
	while (unb > 0)
	{
		unb = unb / 16;
		i++;
	}
	return (i);
}

//	Calculate the length of base
int	ft_len_base(int nb, int b)
{
	int				i;
	unsigned int	unb;

	unb = nb;
	i = 0;
	if (unb == 0)
		return (1);
	while (unb > 0)
	{
		unb = unb / b;
		i++;
	}
	return (i);
}

//	integrer to array pointer
char	*ft_itoa_base_ptr(long int value, int base)
{
	int						size;
	long unsigned int		nbr;
	char					*result;
	char					*ref_base;

	nbr = value;
	ref_base = "0123456789abcdef";
	if (base < 2 || base > 16)
		return (NULL);
	size = ft_len_ptr(nbr);
	size += 2;
	result = malloc(sizeof(char) * (size + 1));
	if (!result)
		return (NULL);
	result[size--] = '\0';
	result[0] = '0';
	result[1] = 'x';
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

//	integrer to array base
char	*ft_itoa_base(int value, const char *ref_base, char spec)
{
	int					size;
	unsigned int		nbr;
	char				*result;
	int					base;

	base = ft_print_strlen(ref_base);
	if (value < 0 && (spec == 'd' || spec == 'i'))
		value = -value;
	nbr = value;
	size = ft_len_base(nbr, base);
	result = malloc(sizeof(char) * (size + 1));
	if (!result || base < 2 || base > 16)
		return (NULL);
	result[size--] = '\0';
	if (value < 0)
		result[0] = '-';
	else
		result[0] = '0';
	while (nbr > 0)
	{
		result[size--] = ref_base[nbr % base];
		nbr /= base;
	}
	return (result);
}

size_t	ft_print_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (!src)
		return (0);
	while (src[i])
		i++;
	if (dstsize <= 0)
		return (i);
	if (dstsize > i)
		dstsize = i + 1;
	while (*src && dstsize-- - 1)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}
