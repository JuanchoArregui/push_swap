/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:36:28 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/29 00:38:33 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char **ptr_char, t_array_int *arg_num)
{
	ft_free_array_str(ptr_char);
	if (arg_num->array_int != NULL)
	{
		free(arg_num->array_int);
		arg_num->array_int = NULL;
	}
	ft_printf("Error\n");
	exit(0);
}

void	ft_print_array_str(char **array)
{
	int	i;
	int	length;

	length = 0;
	while (array[length] != 0)
		length++;
	i = 0;
	ft_printf("[");
	while (array[i] != 0)
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

void	ft_free_array_str(char **temp_args)
{
	int	i;
	if	(*temp_args)
	{
		i = 0;
		while (temp_args[i] != 0)
		{
			free(temp_args[i]);
			temp_args[i] = NULL;
			i++;
		}
		free(temp_args);
		temp_args = NULL;
	}
}