/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 23:57:15 by juancho          ###   ########.fr       */
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

int	ft_stk_get_pivot(t_stack *stk, int half, int first_srtd)
{
	int		smallers;
	t_stack	*stk_current;
	t_stack	*stk_temp;

	if (!stk)
		return (0);
	stk_current = stk;
	while (stk_current && stk_current->value != first_srtd)
	{
		smallers = 0;
		stk_temp = stk;
		while (stk_temp && stk_temp->value != first_srtd)
		{
			if (stk_temp->value > stk_current->value)
				smallers++;
			stk_temp = stk_temp->next;
		}
		if (smallers == half)
			break ;
		stk_current = stk_current->next;
	}
	return (stk_current->value);
}
