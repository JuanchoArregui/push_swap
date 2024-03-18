/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:00 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/18 17:08:37 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_unique(int num_to_check, unsigned int n, t_array_int *arg_num)
{
	unsigned int	i;

	i = arg_num->length - 1;
	if (n == i)
		return (1);
	while (i > n)
	{
		if (arg_num->array_int[i] == num_to_check)
			return (0);
		i--;
	}
	return (1);
}

int	ft_arg_to_i(char **temp_args, unsigned int n, t_array_int *arg_num)
{
	long			nb;
	int				sign;
	unsigned int	i;

	nb = 0;
	i = 0;
	sign = 1 - (2 * (temp_args[n][0] == '-'));
	if (i == 0 && (temp_args[n][i] == '-' || temp_args[n][i] == '+'))
	{
		if (ft_strlen(temp_args[n]) == 1)
			return (0);
		else
			i = 1;
	}
	while (temp_args[n][i])
	{
		if (temp_args[n][i] < '0' || temp_args[n][i] > '9')
			return (0);
		nb = (nb * 10) + temp_args[n][i++] - '0';
	}
	if (sign * nb < -2147483648 || sign * nb > 2147483647)
		return (0);
	if (!ft_unique((int)(sign * nb), n, arg_num))
		return (-1);
	return (arg_num->array_int[n] = (int)(sign * nb), 1);
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
			temp_args[i - 1] = (char *)malloc(ft_arg_size(argv[i]));
			ft_strcpy(argv[i], temp_args[i - 1], 0);
			i++;
		}
		temp_args[i - 1] = 0;
	}
	return (temp_args);
}

int	ft_args_to_num(char **temp_args, t_array_int *arg_num)
{
	unsigned int	len;
	int				check;

	len = 0;
	while (temp_args[len] != 0)
		len++;
	arg_num->length = len;
	arg_num->array_int = (int *)malloc((len) * sizeof(int));
	if (!arg_num->array_int)
		return (0);
	while (len > 0)
	{
		check = ft_arg_to_i(temp_args, len - 1, arg_num);
		if (arg_num->debug && check < 0)
			ft_printf("\nDuplicado:");
		if (arg_num->debug && check < 1)
			ft_printf("\nArg invalid pos: %d: %s\n", len, temp_args[len - 1]);
		if (check < 1)
			ft_error(temp_args, arg_num);
		len--;
	}
	return (1);
}

void	ft_args_check(int argc, char **argv, t_array_int *arg_num)
{
	char		**temp_args;
	int			check;

	temp_args = ft_args_split(argc, argv);
	if (arg_num->debug)
	{
		ft_printf("Array de strings a Evaluar:\n");
		ft_print_array_str(temp_args);
	}
	check = ft_args_to_num(temp_args, arg_num);
	if (arg_num->debug)
	{
		ft_printf("Array de ints:\n");
		ft_print_t_array_int(arg_num);
	}
	ft_free_array_str(temp_args);
	if (!check)
		ft_error(temp_args, arg_num);
}
