/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/16 02:21:20 by juancho          ###   ########.fr       */
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






void	ft_a_get_pivot(t_stks *stks)
{
	int		smallers;
	t_stack	*stk;
	t_stack	*stk_temp;
	int		all;

	// ft_printf("\nGET PIVOT - half = %d", stks->a_half);
	all = (stks->a_last == stks->a_first_srtd);
	stk = stks->a;
	while (stk && (all || stk->value != stks->a_first_srtd))
	{
		smallers = 0;
		stk_temp = stks->a;
		while (stk_temp && (all || stk->value != stks->a_first_srtd))
		{
			if (stk_temp->value < stk->value)
			{
				// ft_printf("\n stk_temp->value: %d - stk->value: %d", stk_temp->value, stk->value);

				smallers++;
			}
			stk_temp = stk_temp->next;
		}
		// ft_printf("\n stk->value: %d - smallers: %d", stk->value, smallers);
		if (smallers == stks->a_half)
			break ;
		stk = stk->next;
	}
	stks->a_pivot = 0;
	if (stk)
		stks->a_pivot = stk->value;
}

void	ft_b_get_pivot(t_stks *stks)
{
	int		smallers;
	t_stack	*stk;
	t_stack	*stk_temp;
	int		all;

	all = (stks->b_last == stks->b_first_rev);
	stk = stks->b;
	while (stk && (all || stk->value != stks->b_first_rev))
	{
		smallers = 0;
		stk_temp = stks->b;
		while (stk_temp && (all || stk->value != stks->b_first_rev))
		{
			if (stk_temp->value > stk->value)
				smallers++;
			stk_temp = stk_temp->next;
		}
		if (smallers == stks->b_half)
			break ;
		stk = stk->next;
	}
	stks->b_pivot = 0;
	if (stk)
		stks->b_pivot = stk->value;
}