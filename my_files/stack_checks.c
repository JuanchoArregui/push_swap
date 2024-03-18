/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/18 16:31:50 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_is_sort(t_stack *stk)
{
	t_stack	*stk_current;

	stk_current = stk;
	while (stk_current && stk_current->next)
	{
		if (stk_current->value > stk_current->next->value)
			return (0);
		stk_current = stk_current->next;
	}
	return (1);
}

int	ft_is_rev(t_stack *stk)
{
	t_stack	*stk_current;

	stk_current = stk;
	while (stk_current && stk_current->next)
	{
		if (stk_current->value < stk_current->next->value)
			return (0);
		stk_current = stk_current->next;
	}
	return (1);
}

void	ft_a_check(t_stks *stks)
{
	t_stack	*stk;
	int		counter;

	stk = stks->a;
	counter = 0;
	if (stks->a)
	{
		while (stk && (!ft_is_sort(stk) || !ft_fst_a_ok(stks->a, stk->value)))
		{
			stk = stk->next;
			counter += 1;
		}
		if (stk)
		{
			stks->a_first_srtd = stk->value;
			stks->a_len_pend = counter;
		}
		else
		{
			stks->a_first_srtd = stks->a_last;
			stks->a_len_pend = stks->a_len;
		}
	}
	stks->a_half = stks->a_len_pend / 2;
}

void	ft_b_check(t_stks *stks)
{
	t_stack	*stk;
	int		counter;

	stk = stks->b;
	counter = 0;
	if (stks->b)
	{
		while (stk && !stk->batch_limit)
		{
			stk = stk->next;
			counter += 1;
		}
		if (stk)
		{
			stks->b_first_rev = stk->value;
			stks->b_len_pend = counter + 1;
		}
		else
		{
			stks->b_first_rev = stks->b_last;
			stks->b_len_pend = stks->b_len;
		}
	}
	stks->b_half = stks->b_len_pend / 2;
}

void	ft_check_stks(t_stks *stks)
{
	stks->a_len = ft_stk_size(stks->a);
	stks->a_last = ft_value_last(stks->a);
	ft_a_check(stks);
	ft_a_get_pivot(stks);
	stks->b_len = ft_stk_size(stks->b);
	stks->b_last = ft_value_last(stks->b);
	ft_b_check(stks);
	ft_b_get_pivot(stks);
}
