/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:20:18 by jarregui          #+#    #+#             */
/*   Updated: 2022/11/16 16:10:08 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	x;
	char	c;

	x = n;
	c = '-';
	if (x < 0)
	{
		write(fd, &c, 1);
		x = -x;
	}
	if (x >= 10)
	{
		ft_putnbr_fd((x / 10), fd);
		ft_putnbr_fd((x % 10), fd);
	}
	else
	{
		c = x + 48;
		write(fd, &c, 1);
	}
}
