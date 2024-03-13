/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 23:14:00 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array_int	arg_num;
	t_stack		*stack_a;
	t_stack		*stack_b;	
	t_stuff		stuff;

	stack_a = NULL;
	stack_b = NULL;
	arg_num.length = 0;
	arg_num.array_int = NULL;
	if (argc < 2)
		return (-1);
	ft_args_check(argc, argv, &arg_num);
	stack_a = ft_stack_init(&arg_num);


	ft_stuff_init(&stuff);
	stuff.debug = 1;
	ft_printf("\nstuff.debug: %d\n", stuff.debug);
	ft_printf("\nstuff.counter: %d\n", stuff.counter);



	ft_stack_sort(&stack_a, &stack_b, 0);

	return (0);
}


// 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 