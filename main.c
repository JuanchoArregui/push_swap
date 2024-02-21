/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/21 13:12:03 by jarregui         ###   ########.fr       */
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

	ft_printf("\nPrinting Stack a inicial: ");
	ft_stack_print(stack_a, NULL);


	ft_stack_is_sorted(stack_a);
	// if (ft_stack_is_sorted(stack_a))
	// {
		ft_stack_free(&stack_a);
		ft_stack_free(&stack_b);
	// 	return (0);
	// }





	return (0);
}


/////   NOTA
// Falta vr el segmentation que me da el array de números

//ESTOY A MEDIAS CON LA ESTRUCTURA DE ARRAY DE ENTEROS. CHECAR TODAS LAS FUNCIONES


// LEAKS: AL LIBERAR TEMP_ARGS FALTA LIBERAR CADA MALLOC DE CADA ELEMNTO DEL ARRAY
// Y CHECAR LOS DUPLICADOSSSSSSSSSS!!!!!!!




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

