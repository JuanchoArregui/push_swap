/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/08 17:03:03 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array_int	arg_num;
	t_stack		*stack_a;
	// t_stack		*stack_b;


	arg_num.length = 0;
	arg_num.array_int = NULL;
	
	ft_printf("argc: %d\n", argc);
	ft_printf("Array of arguments argv:\n");
	ft_print_array_str(argv);
	ft_printf("\n");

	if (argc < 2)
		return (-1);
	ft_args_check(argc, argv, &arg_num);

	ft_printf("Args are ok\n");
	ft_printf("No duplicates found\n");
	ft_printf("Checked Array of numbers: ");
	ft_print_t_array_int(&arg_num);

	stack_a = ft_init_stack(&arg_num);

	ft_printf("\nPrinting Stack linked structures: ");
	ft_print_stack(stack_a);



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

