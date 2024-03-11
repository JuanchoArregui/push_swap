/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/11 14:54:40 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len ++;
		stack = stack->next;
	}
	return (len);
}

int	ft_stack_half(t_stack *stack)
{
	int	len;
	int	half;
	int	rest;

	len = ft_stack_size(stack);
	rest = len % 2;
	half = ft_stack_size(stack) / 2;
	if (rest == 0)
		return (half - 1);
	return (half);
}

int	ft_stack_get_pivot(t_stack **stack)
{
	int		smaller;
	int		half;
	t_stack	*current;
	t_stack	*temp;

	half = ft_stack_half(*stack);
	current = *stack;
	while (current)
	{
		smaller = 0;
		temp = *stack;
		while (temp)
		{
			if (temp->value > current->value)
				smaller++;
			temp = temp->next;
		}
		if (smaller == half)
			break ;
		current = current->next;
	}
	return (current->value);
}

int	ft_stack_is_sorted(t_stack *st_head)
{
	t_stack	*st_next;

	st_next = st_head;
	while (st_next && st_next->next)
	{
		if (st_next->value > st_next->next->value)
			return (0);
		st_next = st_next->next;
	}
	return (1);
}


int	ft_stack_is_reverse_sorted(t_stack *st_head)
{
	t_stack	*st_next;

	st_next = st_head;
	while (st_next && st_next->next)
	{
		if (st_next->value < st_next->next->value)
			return (0);
		st_next = st_next->next;
	}
	return (1);
}