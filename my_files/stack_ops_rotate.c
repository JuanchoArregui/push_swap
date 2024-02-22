/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/22 16:12:15 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate(t_stack **stack_ptr)
{
	t_stack	*last;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return (0);
	last = *stack_ptr;
	while (last->next != NULL)
		last = last->next;
	last->next = *stack_ptr;
	*stack_ptr = (*stack_ptr)->next;
	last->next->next = NULL;
	return (1);
}

int	ra(t_stack **stack_a)
{
	int	res_a;

	res_a = ft_rotate(stack_a);
	if (!res_a)
		return (0);
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stack **stack_a)
{
	int	res_b;

	res_b = ft_rotate(stack_a);
	if (!res_b)
		return (0);
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stack **stack_a, t_stack **stack_b)
{
	int	res_a;
	int	res_b;

	res_a = ft_rotate(stack_a);
	res_b = ft_rotate(stack_b);
	if (!res_a || !res_b)
		return (0);
	ft_printf("rr\n");
	return (1);
}
