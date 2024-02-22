/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/22 20:45:15 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


int	ft_stack_sort_three(t_stack **stack_a)
{
	if ((*stack_a)->value > (*stack_a)->next->value)
	{
		if ((*stack_a)->value > (*stack_a)->next->next->value)
			ra(stack_a);
		else
			sa(stack_a);
	}
	else if ((*stack_a)->next->next->value < (*stack_a)->next->value)
	{
		if ((*stack_a)->value < (*stack_a)->next->next->value)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		return (1);
	}
	return (ft_stack_sort_three(stack_a));
}

int	ft_stack_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	stack_size;

	if (*stack_b == NULL && ft_stack_is_sorted(*stack_a))
	{
		ft_stack_free(stack_a);
		ft_stack_free(stack_b);
		ft_printf("\nORDENADO\n");
		return (1);
	}
	else
	{
		stack_size = ft_stack_size(*stack_a);
		if (stack_size <= 2)
			sa(stack_a);
		else if (stack_size <= 3)
			ft_stack_sort_three(stack_a);
		else
			ft_printf("\nHay que ordenar y desarrollar programa con recursión\n");
		//DO RECURSION HERE;
		// if (*stack_a->value > *stack_a->next>value)
		return (0);
	}
}

