/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fts_save_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 14:34:53 by jarregui          #+#    #+#             */
/*   Updated: 2023/08/09 18:29:05 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	buffer_overflow_protec(t_print **struc)
{
	ft_put_string((*struc)->print, (*struc)->buff_position);
	(*struc)->length += (*struc)->buff_position;
	(*struc)->buff_position = 0;
}

void	ft_save_char(char c, t_print **struc)
{
	if ((*struc)->buff_position >= MAX_LENGTH - 1)
		buffer_overflow_protec(struc);
	(*struc)->print[(*struc)->buff_position] = c;
	(*struc)->print[(*struc)->buff_position + 1] = '\0';
	(*struc)->buff_position += 1;
}

void	ft_save_string(char *s, t_print **struc)
{
	int		i;

	if (!s)
	{
		ft_save_string("(null)", struc);
	}
	else
	{
		i = 0;
		while (s[i])
		{
			if ((*struc)->buff_position >= MAX_LENGTH - 1)
				buffer_overflow_protec(struc);
			(*struc)->print[(*struc)->buff_position] = s[i];
			(*struc)->buff_position++;
			i++;
		}
		(*struc)->print[(*struc)->buff_position] = '\0';
	}
}
