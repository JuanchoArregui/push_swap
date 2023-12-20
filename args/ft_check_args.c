/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 10:37:00 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/20 16:56:58 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_array_print(void **array, char array_type)
{
	int	i;
	int	length;

	length = ft_array_length(array);

	i = 0;
	ft_printf("[");
	while (array[i])
	{
		ft_printf("%s", array[i]);
		if (i < length - 1)
			ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}

int	ft_array_length(void **array)
{
	int	length;

	length = sizeof(array) / sizeof(array[0]);
	return (length);
}

int	ft_contains(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_isnum(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}


int	**ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**temp_args;
	int		**args;

	i = 0;
	if (argc == 2)
		temp_args = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		temp_args = argv;
	}
	while (temp_args[i])
	{
		tmp = ft_atoi(temp_args[i]);
		if (!ft_isnum(temp_args[i]))
			ft_error("Error");
		if (ft_contains(tmp, temp_args, i))
			ft_error("Error");
		if (tmp < -2147483648 || tmp > 2147483647)
			ft_error("Error");
		i++;
	}
	if (argc == 2)
		ft_free(temp_args);
}
