/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 15:15:36 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_rotate(t_stack *stk)
{
	t_stack	*stk_first;
	t_stack	*stk_second;
	t_stack	*stk_last;

	if (stk == NULL || stk->next == NULL)
		return (0);
	stk_first = stk;
	stk_second = stk->next;
	stk_last = stk;
	while (stk_last->next != NULL)
		stk_last = stk_last->next;
	stk = stk_second;
	stk_last->next = stk_first;
	stk_first->next = NULL;
	return (1);
}

int	ra(t_stks *stks)
{
	int	res_a;

	res_a = ft_rotate(stks->a);
	if (!res_a)
		return (0);
	stks->counter += 1;
	ft_printf("ra\n");
	return (1);
}

int	rb(t_stks *stks)
{
	int	res_b;

	res_b = ft_rotate(stks->b);
	if (!res_b)
		return (0);
	stks->counter += 1;
	ft_printf("rb\n");
	return (1);
}

int	rr(t_stks *stks)
{
	int	res_a;
	int	res_b;

	res_a = ft_rotate(stks->a);
	res_b = ft_rotate(stks->b);
	if (!res_a || !res_b)
		return (0);
	stks->counter += 1;
	ft_printf("rr\n");
	return (1);
}
