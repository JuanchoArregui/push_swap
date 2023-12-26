/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/26 22:08:37 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int	**arg_num;


	ft_printf("argc: %d\n", argc);
	ft_printf("Array of arguments argv: ");
	ft_array_str_print(argv);

	if (argc < 2)
		return (-1);
	arg_num = ft_args_check(argc, argv);

	ft_printf("Args are ok\n");
	ft_printf("Checked Array of numbers: ");
	ft_array_num_print(arg_num);

	ft_printf("No duplicates found\n");
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack_node	**stack_a;
// 	t_stack_node	**stack_b;

// 	if (argc < 2)
// 		return (-1);
// 	ft_args_check;(argc, argv);
	// stack_a = (t_stack_node **)malloc(sizeof(t_stack_node));
	// stack_b = (t_stack_node **)malloc(sizeof(t_stack_node));
	// *stack_a = NULL;
	// *stack_b = NULL;
	// ft_stack_init(stack_a, argc, argv);
	// if (is_sorted(stack_a))
	// {
	// 	free_stack(stack_a);
	// 	free_stack(stack_b);
	// 	return (0);
	// }
	// ft_stack_sort(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);
// 	return (0);
// }

