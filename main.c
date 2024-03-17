/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/18 00:11:59 by jarregui         ###   ########.fr       */
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
	stks.debug = 0;
	arg_num.debug = stks.debug;
	ft_args_check(argc, argv, &arg_num);
	stks.a = ft_stk_init(&arg_num);
	stks.b = NULL;
	stks.ops = 0;
	ft_stks_sort(&stks);
	return (0);
}

// -1 2 1 4 5 6
// 3 5 8 9 1 2 88 77 11 -3 678 99 878 934 231 0
// 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 
// 3 5 8 9 1 2 88 77 11 -3 6 99 8 934 231 0 78 687 7476 8473  0 -1 -2
// TESTER
// https://github.com/julien-ctx/push-swap-tester
