/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 19:52:06 by jarregui         ###   ########.fr       */
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

int	ft_fst_a_ok(t_stack *stk, int val)
{
	while (stk && stk->value != val)
	{
		if (stk->value > val)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	ft_fst_b_ok(t_stack *stk, int val)
{
	while (stk && stk->value != val)
	{
		if (stk->value < val)
			return (0);
		stk = stk->next;
	}
	return (1);
}
