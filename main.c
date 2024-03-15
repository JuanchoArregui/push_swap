/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 19:00:26 by jarregui         ###   ########.fr       */
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
	stks.current_stk = 'a';
	stks.debug = 1;
	stks.counter = 0;
	ft_stks_sort(&stks);
	return (0);
}
// CNTINUAR PROBANDO CN ESTE:
// ./push_swap 3 5 8 9 1 2 88 77 11 -3 678 99 878 934 231 0

//Y revisar en los divide si tiene sentido parar después del último push 
//o si hay que seguir para dar la vuelta y dejar el stack como estaba 
//o incluso hacer un reverse y voverlos a poner arriba para dejarlo como estaba


//
// 5 1 9 8 99 88 77 666 65 -33 -34443 -343 -333 9999999 0 6636 -223 