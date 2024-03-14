/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 14:25:43 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_array_int	arg_num;
	t_stks		stks;

	arg_num.length = 0;
	arg_num.array_int = NULL;
	if (argc < 2)
		return (-1);
	ft_args_check(argc, argv, &arg_num);
	ft_stks_init(&stks);
	stks.a = ft_stk_init(&arg_num);
	stks.debug = 1;

ft_stks_print(&stks);
	ra(&stks);
	ra(&stks);
	ft_stks_print(&stks);


	// ft_stks_sort(&stks);
	return (0);
}


// 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 