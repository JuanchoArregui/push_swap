/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:48:36 by jarregui          #+#    #+#             */
/*   Updated: 2022/11/16 16:15:37 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	destlen;
	size_t	srclen;
	size_t	i;

	i = 0;
	if (!dst && size == 0)
		return (0);
	destlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < destlen || size == 0)
		return (srclen + size);
	while (src[i] && i + destlen < size - 1)
	{
		dst[destlen + i] = src[i];
		i ++;
	}
	dst[destlen + i] = '\0';
	return (destlen + srclen);
}
