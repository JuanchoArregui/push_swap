/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 15:44:18 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stk_size(t_stack *stk)
{
	int	len;

	len = 0;
	while (stk)
	{
		len ++;
		stk = stk->next;
	}
	return (len);
}

int	ft_value_last(t_stack *stk)
{
	t_stack	*stk_current;
	int		value_last;

	if (!stk)
		return (0);
	stk_current = stk;
	while (stk_current)
	{
		value_last = stk_current->value;
		stk_current = stk_current->next;
	}
	return (value_last);
}

int	ft_stk_get_pivot(t_stack *stk, int half)
{
	int		smaller;
	t_stack	*stk_current;
	t_stack	*stk_temp;

	stk_current = stk;
	while (stk_current)
	{
		smaller = 0;
		stk_temp = stk;
		while (stk_temp)
		{
			if (stk_temp->value > stk_current->value)
				smaller++;
			stk_temp = stk_temp->next;
		}
		if (smaller == half)
			break ;
		stk_current = stk_current->next;
	}
	return (stk_current->value);
}

int	ft_stk_a_is_sorted(t_stack *stk)
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

int	ft_stk_b_is_reversed(t_stack *stk)
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
