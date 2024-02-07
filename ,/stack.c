/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:05:11 by jarregui          #+#    #+#             */
/*   Updated: 2024/01/10 17:13:20 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stack_init(t_stack_node	*stack, t_array_int *arg_num)
{
	int i;

	i = 0;
	while (i < arg_num->length - 1)
	{
		i++;
	}
	printf("dentro de ft_stack_init\n");
}
