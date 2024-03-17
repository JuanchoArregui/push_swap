/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_restore.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 19:02:16 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_a_restore(t_stks *stks, int to_restore)
{
	int		counter;

	if (to_restore > 0 && stks->a_len_pend != stks->a_len)
	{
		counter = 0;
		while (counter < to_restore)
		{
			rra(stks);
			counter++;
		}
	}
}

void	ft_b_restore(t_stks *stks, int to_restore)
{
	int		counter;

	if (to_restore > 0 && stks->a_len_pend != stks->a_len)
	{
		counter = 0;
		while (counter < to_restore)
		{
			rrb(stks);
			counter++;
		}
	}
}
