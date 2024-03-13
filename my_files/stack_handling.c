/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 17:41:22 by juancho          ###   ########.fr       */
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

int	ft_value_last(t_stack **stk)
{
	t_stack	*current;
	int		value_last;

	if (!*stk)
		return (0);
	current = *stk;
	while (current){
		value_last = current->value;
		current = current->next;
	}
	return (value_last);
}

int	ft_stack_get_pivot(t_stack **stack, int half)
{
	int		smaller;
	t_stack	*current;
	t_stack	*temp;

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

int	ft_stack_is_sorted(t_stack *stk)
{
	t_stack	*st_next;

	st_next = stk;
	while (st_next && st_next->next)
	{
		if (st_next->value > st_next->next->value)
			return (0);
		st_next = st_next->next;
	}
	return (1);
}


int	ft_stack_is_reverse_sorted(t_stack *stk)
{
	t_stack	*st_next;

	st_next = stk;
	while (st_next && st_next->next)
	{
		if (st_next->value < st_next->next->value)
			return (0);
		st_next = st_next->next;
	}
	return (1);
}