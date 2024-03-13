/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_mix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/12 23:02:50 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	rasa(t_stack **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	return (1);
}

int	sara(t_stack **stack_a)
{
	sa(stack_a);
	ra(stack_a);
	return (1);
}

int	rbsb(t_stack **stack_b)
{
	rb(stack_b);
	sb(stack_b);
	return (1);
}

int	sbrb(t_stack **stack_b)
{
	sb(stack_b);
	rb(stack_b);
	return (1);
}

void	dump_b(t_stack **stack_a, t_stack **stack_b)
{
	while (stack_b)
	{
		pb(stack_a, stack_b);
	}
}
