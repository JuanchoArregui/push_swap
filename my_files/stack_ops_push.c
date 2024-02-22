/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/22 16:12:45 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;

	if (*stack_a == NULL)
		return (0);
	temp = *stack_a;
	*stack_a = (*stack_a)->next;
	temp->next = *stack_b;
	*stack_b = temp;
	return (1);
}

int	pa(t_stack **stack_a, t_stack **stack_b)
{
	int	res_a;

	res_a = ft_push(stack_a, stack_b);
	if (!res_a)
		return (0);
	ft_printf("pa\n");
	return (1);
}

int	pb(t_stack **stack_b, t_stack **stack_a)
{
	int	res_b;

	res_b = ft_push(stack_b, stack_a);
	if (!res_b)
		return (0);
	ft_printf("pb\n");
	return (1);
}
