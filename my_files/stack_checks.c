/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 00:28:10 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_a_is_sorted(t_stack *stk)
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

int	ft_b_is_reversed(t_stack *stk)
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

	stks->a_len = ft_stk_size(stks->a);
	stks->a_last = ft_value_last(stks->a);
	stk_current = stks->a;
	counter = 0;
	while (stk_current && !ft_a_is_sorted(stk_current))
	{
		stk_current = stk_current->next;
		counter += 1;
	}
	// if (stk_current)
	// {
	// 	ft_printf("\n 11111111111");
	// 	stks->a_first_srtd = stk_current->value;
	// 	stks->a_len_pend = counter;
	// }
	// else
	// {
	// 	ft_printf("\n 222222222222");
	// 	stks->a_first_srtd = first_sorted;
	// 	stks->a_len_pend = counter + 1;
	// }
	stks->a_first_srtd = stk_current->value;
	if (stk_current->value == stks->a_last)
		stks->a_len_pend = stks->a_len;
	else
		stks->a_len_pend = counter;
	stks->a_half = stks->a_len_pend / 2;
}

void	ft_b_first_reversed(t_stks *stks)
{
	t_stack	*stk_current;
	int		last_reversed;
	int		counter;

	stks->b_len = ft_stk_size(stks->b);
	stks->b_last = ft_value_last(stks->b);
	stk_current = stks->b;
	last_reversed = 0;
	counter = 0;
	while (stk_current && !ft_b_is_reversed(stk_current))
	{
		last_reversed = stk_current->value;
		stk_current = stk_current->next;
		counter += 1;
	}
	if (stk_current)
	{
		stks->b_first_rev = stk_current->value;
		stks->b_len_pend = counter;
	}
	else
	{
		stks->b_first_rev = last_reversed;
		stks->b_len_pend = counter + 1;
	}
	stks->b_half = counter / 2;
}

void	ft_check_stks(t_stks *stks)
{
	ft_a_first_sorted(stks);
	stks->a_pivot = ft_stk_get_pivot(stks->a, stks->a_half, stks->a_first_srtd);

	ft_b_first_reversed(stks);
	stks->b_pivot = ft_stk_get_pivot(stks->b, stks->b_half, stks->b_first_rev);
}
