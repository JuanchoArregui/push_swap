/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/11 15:15:57 by jarregui         ###   ########.fr       */
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

	if (ft_stack_is_sorted(*stack_a) && *stack_b == NULL)
	{
	ft_printf("\nORDENADO\n");
	ft_printf("STACKS ORDENADOS AL FINALIZAR:\n");
	ft_stacks_print(*stack_a, *stack_b);
		ft_stack_free(stack_a);
		ft_stack_free(stack_b);
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
		{
			//DO RECURSION HERE;
			ft_stack_divide_conquer(stack_a, stack_b);
			ft_stack_sort(stack_a, stack_b);
		}
		return (0);
	}
}

void	divide_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		half;
	int		pivot;
	int		counter;

	half = ft_stack_half(*stack_a);
	pivot = ft_stack_get_pivot(stack_a);
	counter = 0;

	current = *stack_a;
	while (counter < half)
	{
		if ((*stack_a)->value <= pivot)
		{
			pa(stack_a, stack_b);
			counter++;
		}
		else
		{
			ra(stack_a);
		}
	}
}

void	divide_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*current;
	int		half;
	int		pivot;
	int		counter;

	half = ft_stack_half(*stack_b);
	pivot = ft_stack_get_pivot(stack_b);
	counter = 0;

	current = *stack_a;
	while (counter < half)
	{
		if ((*stack_b)->value <= pivot)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
		{
			rb(stack_b);
		}
	}
}

void	ft_stack_divide_conquer(t_stack **stack_a, t_stack **stack_b)
{
	int		len_a;
	int		len_b;

	len_a = ft_stack_size(*stack_a);
	len_b = ft_stack_size(*stack_b);
	if (*stack_a && !ft_stack_is_sorted(*stack_a) && len_a > 3)
	{
		divide_a(stack_a, stack_b);
	}
	else if (*stack_b && !ft_stack_is_reverse_sorted(*stack_b) && len_b > 3)
	{
		divide_b(stack_a, stack_b);
	}
	else if (*stack_b && ft_stack_is_reverse_sorted(*stack_b))
	{
		while (*stack_b)
		{
			pb(stack_b, stack_a);
		}
	}
}