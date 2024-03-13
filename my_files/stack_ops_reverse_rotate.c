/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 00:35:08 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_reverse_rotate(t_stack **stack_ptr)
{
	t_stack	*last;
	t_stack	*penultimate;

	if (*stack_ptr == NULL || (*stack_ptr)->next == NULL)
		return (0);
	penultimate = *stack_ptr;
	while (penultimate->next->next != NULL)
		penultimate = penultimate->next;
	last = penultimate->next;
	penultimate->next = NULL;
	last->next = *stack_ptr;
	*stack_ptr = last;
	return (1);
}

int	rra(t_stack **stack_a)
{
	int	res_a;

	res_a = ft_reverse_rotate(stack_a);
	if (!res_a)
		return (0);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stack **stack_b)
{
	int	res_b;

	res_b = ft_reverse_rotate(stack_b);
	if (!res_b)
		return (0);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	res_a;
	int	res_b;

	res_a = ft_reverse_rotate(stack_a);
	res_b = ft_reverse_rotate(stack_b);
	if (!res_a || !res_b)
		return (0);
	ft_printf("rrr\n");
	return (1);
}
