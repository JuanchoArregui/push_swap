/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/22 20:07:10 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array_int	arg_num;
	t_stack		*stack_a;
	t_stack		*stack_b;


	stack_a = NULL;
	stack_b = NULL;
	arg_num.length = 0;
	arg_num.array_int = NULL;
	
		ft_printf("\n address stack_b p: %p\n", &stack_b);
		ft_printf("\n address stack_b p: %p\n", stack_b);

	ft_printf("\nargc: %d", argc);
	ft_printf("\nArray of arguments argv:\n");
	ft_print_array_str(argv);
	ft_printf("\n");

	if (argc < 2)
		return (-1);
	ft_args_check(argc, argv, &arg_num);

	ft_printf("Args are ok\n");
	ft_printf("No duplicates found\n");
	ft_printf("Checked Array of numbers: ");
	ft_print_t_array_int(&arg_num);

	stack_a = ft_stack_init(&arg_num);

	ft_stacks_print(stack_a, stack_b);
	ft_stack_sort(&stack_a, &stack_b);
	ft_stacks_print(stack_a, stack_b);


	// ft_stack_is_sorted(stack_a);
	// if (ft_stack_is_sorted(stack_a))
	// {
		// ft_stack_free(&stack_a);
		// ft_stack_free(&stack_b);
	// 	return (0);
	// }

	





	return (0);
}


// POR HACER
// Implementar las funciones permitadas de swap, push etc.
// probar e imprimir los satcks para ver que funcionan.

// Implementar algoritmo de ordenación.




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

