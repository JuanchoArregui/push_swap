/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:14:15 by jarregui          #+#    #+#             */
/*   Updated: 2021/07/14 23:15:26 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char			*result;
	long int		nb;
	int				is_neg;
	unsigned int	len;

	is_neg = n < 0;
	nb = n;
	if (is_neg)
		nb = -nb;
	len = 1;
	while (n / 10 != 0 && len++)
		n = n / 10;
	result = malloc(sizeof(char) * (len + 1 + is_neg));
	if (!result)
		return (NULL);
	result[len + is_neg] = '\0';
	while (len--)
	{
		result[len + is_neg] = nb % 10 + '0';
		nb /= 10;
	}
	if (is_neg)
		result[0] = '-';
	return (result);
}
