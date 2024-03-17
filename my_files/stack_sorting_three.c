/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting_three.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 19:07:42 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_a_sort_three(t_stks *stks)
{
	int	len;

	if (stks->debug == 1)
		ft_printf("*************** ordenamos A3 \n");
	len = ft_stk_size(stks->a);
	if (len == 2 && (stks->a)->value > (stks->a)->next->value)
		sa(stks);
	else if (len == 3 && (stks->a)->value > (stks->a)->next->value)
	{
		if ((stks->a)->next->value > (stks->a)->next->next->value)
			rasa(stks);
		else if ((stks->a)->value > (stks->a)->next->next->value)
			ra(stks);
		else
			sa(stks);
	}
	else if (len == 3 && (stks->a)->next->value > (stks->a)->next->next->value)
	{
		if ((stks->a)->value > (stks->a)->next->next->value)
			rra(stks);
		else
			sara(stks);
	}
	return (1);
}

int	ft_b_reverse_three(t_stks *stks)
{
	int	len;

	if (stks->debug == 1)
		ft_printf("*************** Ordenamos inverso B3 \n");
	len = ft_stk_size(stks->b);
	if (len == 2 && (stks->b)->value < (stks->b)->next->value)
		sb(stks);
	else if (len == 3 && (stks->b)->value < (stks->b)->next->value)
	{
		if ((stks->b)->next->value < (stks->b)->next->next->value)
			rbsb(stks);
		else if ((stks->b)->value < (stks->b)->next->next->value)
			rb(stks);
		else
			sb(stks);
	}
	else if (len == 3 && (stks->b)->next->value < (stks->b)->next->next->value)
	{
		if ((stks->b)->value < (stks->b)->next->next->value)
			rrb(stks);
		else
			sbrb(stks);
	}
	return (1);
}
