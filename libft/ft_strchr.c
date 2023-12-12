/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:14:49 by jarregui          #+#    #+#             */
/*   Updated: 2022/11/16 16:15:00 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	x;

	x = 0;
	while (s[x] != '\0')
	{
		if (s[x] == (char)c)
			return ((char *) s + x);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)(s + x));
	return (NULL);
}
