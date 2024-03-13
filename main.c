/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/12 23:59:01 by juancho          ###   ########.fr       */
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

	
	// ft_printf("STACKS AL INICIO:\n");
	// ft_stacks_print(stack_a, stack_b);


	ft_stack_sort(&stack_a, &stack_b, 0);

	return (0);
}

//Me falta hacer un función de sort 3
//otra de sorte 3 reverse
//Y checar la lógica de ft_stack_divide_conquer para asegurar que no hay bucle infinito


//Corregir ft_strlncpy cabeceras en printf
// Y modificar ejecutable printf para mac


// 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 