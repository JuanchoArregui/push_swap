/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 18:56:47 by jarregui         ###   ########.fr       */
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
	ft_printf("\nGET PIVOT - half = %d", half);
	
	while (stk_current && stk_current->value != first_srtd)
	{
		
		smallers = 0;
		stk_temp = stk;
		while (stk_temp && stk_temp->value != first_srtd)
		{
			//creo que hay q cambiar el signo dependiendoe de si es A o B
			//Y luego revisar en divide a y b que uno de los quité un >= y lo puso soo >
			if (stk_temp->value > stk_current->value)
			{
				ft_printf("\n stk_temp->value: %d - stk_current->value: %d", stk_temp->value, stk_current->value);

				smallers++;
			}
			stk_temp = stk_temp->next;
		}
		ft_printf("\n stk_current->value: %d - smallers: %d", stk_current->value, smallers);
		if (smallers == half)
			break ;
		stk_current = stk_current->next;
	}
	return (stk_current->value);
}

int	ft_check_first_sort(t_stack *stk, int val)
{

	while (stk && stk->value != val)
	{
		if (stk->value > val)
			return (0);
		stk = stk->next;
	}
	return (1);
}

int	ft_check_first_rev(t_stack *stk, int val)
{

	while (stk && stk->value != val)
	{
		if (stk->value < val)
			return (0);
		stk = stk->next;
	}
	return (1);
}
