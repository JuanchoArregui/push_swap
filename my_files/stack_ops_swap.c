/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/22 16:05:34 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_stack **stack_ptr)
{
	t_stack	*first;
	t_stack	*second;

	if (ft_stack_size(*stack_ptr) < 2)
		return (0);
	first = *stack_ptr;
	second = (*stack_ptr)->next;
	first->next = second->next;
	second->next = first;
	*stack_ptr = second;
	return (1);
}

int	sa(t_stack **stack_a)
{
	int	res_a;

	res_a = ft_swap(stack_a);
	if (!res_a)
		return (0);
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stack **stack_b)
{
	int	res_b;

	res_b = ft_swap(stack_b);
	if (!res_b)
		return (0);
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stack **stack_a, t_stack **stack_b)
{
	int	res_a;
	int	res_b;

	res_a = ft_swap(stack_a);
	res_b = ft_swap(stack_b);
	if (!res_a || !res_b)
		return (0);
	ft_printf("ss\n");
	return (1);
}
