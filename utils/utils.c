/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:28 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/27 00:35:15 by jarregui         ###   ########.fr       */
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

void	ft_array_str_print(char **array)
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

void	ft_array_num_print(int **array)
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
		ft_printf("%d", array[i]);
		if (i < length - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}

