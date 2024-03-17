/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 18:50:40 by juancho          ###   ########.fr       */
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
	stks.a = ft_stk_init(&arg_num);
	stks.b = NULL;
	stks.debug = 0;
	stks.ops = 0;
	ft_stks_sort(&stks);
	return (0);
}

// CNTINUAR PROBANDO CN ESTE:
// ./push_swap -1 2 1 4 5 6
// ./push_swap 3 5 8 9 1 2 88 77 11 -3 678 99 878 934 231 0
// ./push_swap 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 
// ./push_swap 3 5 8 9 1 2 88 77 11 -3 678 99 878 934 231 0 78 687 7476 8473 
// 1111111 -34 -566 -23 -346 -46 -89 -90 8769 -12222 3444
