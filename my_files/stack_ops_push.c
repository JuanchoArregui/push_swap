/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_ops_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:54 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 12:51:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_push(t_stks *stks, char source)
{
	t_stack	*temp;

	if (source == 'a')
	{
		if (stks->a == NULL)
			return (0);
		temp = stks->a;
		stks->a = (stks->a)->next;
		temp->next = stks->b;
		stks->b = temp;
	}
	else
	{
		if (stks->b == NULL)
			return (0);
		temp = stks->b;
		stks->b = (stks->b)->next;
		temp->next = stks->a;
		stks->a = temp;
	}
	return (1);
}

int	pa(t_stks *stks)
{
	int	res_a;

	res_a = ft_push(stks, 'a');
	if (!res_a)
		return (0);
	stks->counter += 1;
	ft_printf("pb\n");
	return (1);
}

int	pb(t_stks *stks)
{
	int	res_b;

	res_b = ft_push(stks, 'b');
	if (!res_b)
		return (0);
	stks->counter += 1;
	ft_printf("pa\n");
	return (1);
}
