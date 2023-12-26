/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:00 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/27 00:59:16 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_arg_to_i(char **temp_args, unsigned int n, int **arg_num)
{
	long			nb;
	int				sign;
	unsigned int	i;

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
		if (temp_args[n][i] < '0' || temp_args[n][i] > '9')
			return (0);
		nb = (nb * 10) + temp_args[n][i++] - '0';
	}
	if (sign * nb < -2147483648 || sign * nb > 2147483647)
		return (0);

	*arg_num[n] = (int)(sign * nb);
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
		temp_args = (char **)malloc((argc) * sizeof(char *));
		if (!temp_args)
			return (NULL);
		i = 1;
		while (i < argc)
		{
			temp_args[i - 1] = argv[i];
			i++;
		}
		temp_args[i] = NULL;
	}
	ft_printf("Splited array of strings: \n");
	ft_array_str_print(temp_args);
	return (temp_args);
}

int	**ft_args_to_num(char **temp_args)
{
	int				**arg_num;
	int				length;
	unsigned int	n;
	int				check;

	length = 0;
	while (temp_args[length] != NULL)
		length++;
	arg_num = (int **)malloc((length + 1) * sizeof(int *));
	if (!arg_num)
		return (NULL);
	n = 0;
	while (temp_args[n])
	{
		check = ft_arg_to_i(temp_args, n, arg_num);
		if (!check)
			ft_error(temp_args, arg_num);
		n++;
	}
	return (arg_num);
}

int	**ft_args_check(int argc, char **argv)
{
	char	**temp_args;
	int		**arg_num;

	temp_args = ft_args_split(argc, argv);
	if (!temp_args)
		exit (0);
	arg_num = ft_args_to_num(temp_args);
	if (*temp_args != NULL)
	{
		free(*temp_args);
		*temp_args = NULL;
	}
	if (!arg_num)
		exit (0);
	return (arg_num);
}


/////   NOTA
// Falta vr el segmentation que me da el array de números
// Y CHECAR LOS DUPLICADOSSSSSSSSSS!!!!!!!