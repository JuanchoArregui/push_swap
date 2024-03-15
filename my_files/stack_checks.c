/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 17:04:02 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sorted(t_stack *stk)
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

int	ft_is_reversed(t_stack *stk)
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

void	ft_a_first_sorted(t_stks *stks)
{
	t_stack	*stk_current;
	int		counter;

	stk_current = stks->a;
	counter = 0;
	stks->a_first_srtd = stks->a_last;
	stks->a_len_pend = stks->a_len;
	if (stks->a)
	{
		while (!ft_is_sorted(stk_current))
		{
			stk_current = stk_current->next;
			counter += 1;
		}
		if (ft_check_first_sort(stks->a, stk_current->value))
		{
			stks->a_first_srtd = stk_current->value;
			if (stk_current->value == stks->a_last)
				stks->a_len_pend = stks->a_len;
			else
				stks->a_len_pend = counter;
		}
	}
	stks->a_half = stks->a_len_pend / 2;
	stks->a_pivot = ft_stk_get_pivot(stks->a, stks->a_half, stks->a_first_srtd);
}

void	ft_b_first_reversed(t_stks *stks)
{
	t_stack	*stk_current;
	int		counter;

	stk_current = stks->b;
	counter = 0;
	stks->b_first_rev = stks->b_last;
	stks->b_len_pend = stks->b_len;
	if (stks->b)
	{
		while (!ft_is_reversed(stk_current))
		{
			stk_current = stk_current->next;
			counter += 1;
		}
		if (ft_check_first_rev(stks->b, stk_current->value))
		{
			stks->b_first_rev = stk_current->value;
			if (stk_current->value == stks->b_last)
				stks->b_len_pend = stks->b_len;
			else
				stks->b_len_pend = counter;
		}
	}
	stks->b_half = stks->b_len_pend / 2;
	stks->b_pivot = ft_stk_get_pivot(stks->b, stks->b_half, stks->b_first_rev);
}

void	ft_check_stks(t_stks *stks)
{
	stks->a_len = ft_stk_size(stks->a);
	stks->a_last = ft_value_last(stks->a);
	ft_a_first_sorted(stks);
	stks->b_len = ft_stk_size(stks->b);
	stks->b_last = ft_value_last(stks->b);
	ft_b_first_reversed(stks);
}
