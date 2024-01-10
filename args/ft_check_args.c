/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:00 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/29 01:09:32 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_arg_to_i(char **temp_args, unsigned int n, t_array_int *arg_num)
{
	long			nb;
	int				sign;
	unsigned int	i;

	printf("ft_arg_to_i n: %d\n", n);
	nb = 0;
	sign = 1;
	i = 0;
	if (temp_args[n][i] == '-' || temp_args[n][i] == '+')
	{
		if (temp_args[n][i++] == '-')
			sign *= -1;
	}
	while (temp_args[n][i])
	{
	printf("ft_arg_to_i i: %d\n", i);
		if (temp_args[n][i] < '0' || temp_args[n][i] > '9')
			return (0);
		nb = (nb * 10) + temp_args[n][i++] - '0';
	}
	if (sign * nb < -2147483648 || sign * nb > 2147483647)
		return (0);
	arg_num->array_int[n] = (int)(sign * nb);

	printf("ft_arg_to_i arg_num->array_int[n]: %d\n", arg_num->array_int[n]);

	return (1);
}

char	**ft_args_split(int argc, char **argv)
{
	char	**temp_args;
	int		i;

	if (argc == 2)
	{
		temp_args = ft_split(argv[1], ' ');
		if (!temp_args)
			return (NULL);
	}
	else
	{
		temp_args = (char **)malloc(sizeof(char *) * (argc));
		if (!temp_args)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			temp_args[i - 1] = (char *)malloc(sizeof(char) * (ft_strlen(argv[i]) + 1));
			ft_strcpy(argv[i], temp_args[i - 1], 0);
			i++;
		}
		temp_args[i-1] = 0;
	}






	ft_printf("Splited array of strings: \n");
	ft_print_array_str(temp_args);
	ft_printf("\n");
	return (temp_args);
}

int	ft_args_to_num(char **temp_args, t_array_int *arg_num)
{
	unsigned int	length;
	int				check;

	length = 0;
	while (temp_args[length] != 0)
		length++;

	printf("ft_args_to_num length: %d\n", length);
	arg_num->length = length;
	arg_num->array_int = (int *)malloc((length) * sizeof(int));
	if (!arg_num->array_int)
		return (0);
	while (length > 0)
	{
		check = ft_arg_to_i(temp_args, length - 1, arg_num);
		printf("ft_args_to_num CHECK: %d\n\n\n", check);

		if (!check)
			ft_error(temp_args, arg_num);
		length--;
	}
	return (1);
}

void	ft_args_check(int argc, char **argv, t_array_int *arg_num)
{
	char		**temp_args;
	int			check;

	temp_args = ft_args_split(argc, argv);
	// if (!temp_args)
	// 	exit (0);
	check = ft_args_to_num(temp_args, arg_num);
	ft_free_array_str(temp_args);
	if (!check)
		ft_error(temp_args, arg_num);
}


/////   NOTA
// Falta vr el segmentation que me da el array de números

//ESTOY A MEDIAS CON LA ESTRUCTURA DE ARRAY DE ENTEROS. CHECAR TODAS LAS FUNCIONES


// LEAKS: AL LIBERAR TEMP_ARGS FALTA LIBERAR CADA MALLOC DE CADA ELEMNTO DEL ARRAY
// Y CHECAR LOS DUPLICADOSSSSSSSSSS!!!!!!!