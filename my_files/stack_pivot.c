/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pivot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 19:51:23 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_a_get_pivot(t_stks *stks)
{
	int		smallers;
	t_stack	*stk;
	t_stack	*stk_temp;
	int		all;

	all = (stks->a_last == stks->a_first_srtd);
	stk = stks->a;
	while (stk && (all || stk->value != stks->a_first_srtd))
	{
		smallers = 0;
		stk_temp = stks->a;
		while (stk_temp && (all || stk->value != stks->a_first_srtd))
		{
			if (stk_temp->value < stk->value)
				smallers++;
			stk_temp = stk_temp->next;
		}
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
