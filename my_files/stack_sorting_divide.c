/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting_divide.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/19 10:59:43 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_a_do_pa(t_stks *stks, int counter)
{
	pa(stks);
	if (stks->b->next && stks->b->value < stks->b->next->value)
	{
		if (stks->a && stks->a->next && stks->a->value > stks->a->next->value)
			ss(stks);
		else
			sb(stks);
	}
	counter++;
	if (counter == stks->a_half - 1)
		stks->b->batch_limit = 1;
	return (counter);
}

void	ft_b_do_pb(t_stks *stks)
{
	pb(stks);
	if (stks->a->next && stks->a->value > stks->a->next->value)
	{
		if (stks->b && stks->b->next && stks->b->value < stks->b->next->value)
			ss(stks);
		else
			sa(stks);
	}
}
