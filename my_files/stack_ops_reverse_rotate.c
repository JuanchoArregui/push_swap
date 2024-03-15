/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 14:02:15 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_reverse_rotate(t_stack **stk)
{
	t_stack	*stk_last;
	t_stack	*stk_penultimate;

	if (stk == NULL || (*stk)->next == NULL)
		return (0);
	stk_penultimate = *stk;
	while (stk_penultimate->next->next != NULL)
		stk_penultimate = stk_penultimate->next;
	stk_last = stk_penultimate->next;
	stk_penultimate->next = NULL;
	stk_last->next = *stk;
	*stk = stk_last;
	return (1);
}

int	rra(t_stks *stks)
{
	int	res_a;

	res_a = ft_reverse_rotate(&stks->a);
	if (!res_a)
		return (0);
	stks->counter += 1;
	stks->a_last = ft_value_last(stks->a);
	ft_printf("rra\n");
	return (1);
}

int	rrb(t_stks *stks)
{
	int	res_b;

	res_b = ft_reverse_rotate(&stks->b);
	if (!res_b)
		return (0);
	stks->counter += 1;
	stks->a_last = ft_value_last(stks->a);
	ft_printf("rrb\n");
	return (1);
}

int	rrr(t_stks *stks)
{
	int	res_a;
	int	res_b;

	res_a = ft_reverse_rotate(&stks->a);
	res_b = ft_reverse_rotate(&stks->b);
	if (!res_a || !res_b)
		return (0);
	stks->counter += 1;
	stks->a_last = ft_value_last(stks->a);
	stks->b_last = ft_value_last(stks->b);
	ft_printf("rrr\n");
	return (1);
}
