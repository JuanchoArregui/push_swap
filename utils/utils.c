/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:28 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/27 23:02:33 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char **ptr_char, int **ptr_int)
{
	if (*ptr_char != NULL)
	{
		free(*ptr_char);
		*ptr_char = NULL;
	}
	if (*ptr_int != NULL)
	{
		free(*ptr_int);
		*ptr_int = NULL;
	}
	ft_printf("Error\n");
	exit(0);
}

void	ft_print_array_str(char **array)
{
	int	i;
	int	length;

	length = 0;
	while (array[length] != NULL)
		length++;
	i = 0;
	ft_printf("[");
	while (array[i] != NULL)
	{
		ft_printf("%s", array[i]);
		if (i < length - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}

void	ft_print_t_array_int(t_array_int *arg_num)
{
	unsigned int	i;

	i = 0;
	ft_printf("[");
	if (arg_num->length == 0)
		ft_printf("NULL");
	else
	{
		while (i < arg_num->length)
		{
			ft_printf("%d", arg_num->array_int[i]);
			if (i < arg_num->length - 1)
				ft_printf(", ");
			i++;
		}
	}
	ft_printf("]\n");
}

