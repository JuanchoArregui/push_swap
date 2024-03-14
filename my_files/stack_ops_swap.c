/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 16:39:59 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_swap(t_stack **stk)
{
	t_stack	*stk_first;
	t_stack	*stk_second;

	if (ft_stk_size(*stk) < 2)
		return (0);
	stk_first = *stk;
	stk_second = (*stk)->next;
	stk_first->next = stk_second->next;
	stk_second->next = stk_first;
	*stk = stk_second;
	return (1);
}

int	sa(t_stks *stks)
{
	int	res_a;

	res_a = ft_swap(&stks->a);
	if (!res_a)
		return (0);
	stks->counter += 1;
	ft_printf("sa\n");
	return (1);
}

int	sb(t_stks *stks)
{
	int	res_b;

	res_b = ft_swap(&stks->b);
	if (!res_b)
		return (0);
	stks->counter += 1;
	ft_printf("sb\n");
	return (1);
}

int	ss(t_stks *stks)
{
	int	res_a;
	int	res_b;

	res_a = ft_swap(&stks->a);
	res_b = ft_swap(&stks->b);
	if (!res_a || !res_b)
		return (0);
	stks->counter += 1;
	ft_printf("ss\n");
	return (1);
}
