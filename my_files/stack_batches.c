/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_batches.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:44:34 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/18 16:30:40 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_batch_is_rev(t_stack *stk)
{
	t_stack	*stk_current;
	int		inside_batch;

	stk_current = stk;
	inside_batch = 1;
	while (stk_current && stk_current->next && inside_batch)
	{
		if (stk_current->value < stk_current->next->value)
			return (0);
		if (stk_current->batch_limit)
			inside_batch = 0;
		stk_current = stk_current->next;
	}
	return (1);
}

void	ft_dump_batch(t_stks *stks)
{
	int		inside_batch;

	inside_batch = 1;
	if (stks->debug)
		ft_printf(">>>>> B Batch rev OK. volcamos batch \n");
	while (stks->b && inside_batch)
	{
		if (stks->b->batch_limit)
			inside_batch = 0;
		pb(stks);
	}
}

void	ft_dump_b(t_stks *stks)
{
	if (stks->debug)
		ft_printf(">>>>> A OK y rev B OK y solo queda volcar \n");
	while (stks->b)
	{
		pb(stks);
	}
}