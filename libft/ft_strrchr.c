/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:42:46 by jarregui          #+#    #+#             */
/*   Updated: 2022/11/16 16:16:26 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	x;
	int	y;

	x = 0;
	y = -1;
	while (s[x] != '\0')
	{
		if ((s[x] == (char)c))
			y = x;
		x++;
	}
	if (s[x] == (char)c)
		y = x;
	if (y != -1)
		return ((char *)s + y);
	return (NULL);
}
