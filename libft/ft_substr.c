/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 13:00:53 by jarregui          #+#    #+#             */
/*   Updated: 2022/11/16 16:17:01 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ns;
	size_t	nlen;

	if (!s)
		return (0);
	if (*s == '\0')
		return (ft_strdup(""));
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	nlen = ft_strlen(s + start);
	if (nlen < len)
		len = nlen;
	ns = (char *)malloc(sizeof(char) * len + 1);
	if (!ns)
		return (0);
	ft_strlcpy(ns, s + start, len + 1);
	return (ns);
}
