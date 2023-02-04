/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmoran-l <cmoran-l@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:45:21 by cmoran-l          #+#    #+#             */
/*   Updated: 2022/05/21 09:45:32 by cmoran-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Outputs the integer ’n’ to the given file descriptor.
void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	if (n <= 2147483647 || n >= -2147483647)
	{
		if (n < 0)
		{
			write(fd, "-", 1);
			n *= -1;
			ft_putnbr_fd(n, fd);
		}
		else if (n == 0)
		{
			write(fd, "0", 1);
		}
		else if (n > 0)
		{
			if (n >= 10)
				ft_putnbr_fd((n / 10), fd);
			n = (n % 10) + '0';
			write(fd, &n, 1);
		}
	}
}
