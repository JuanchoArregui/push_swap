/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 18:38:26 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_stks_print(t_stks *stks)
{
	t_stack	*stk_a_temp;
	t_stack	*stk_b_temp;

	stk_a_temp = stks->a;
	stk_b_temp = stks->b;
	while (stk_a_temp || stk_b_temp)
	{
		if (stk_a_temp)
		{
			ft_printf("\n%d", stk_a_temp->value);
			stk_a_temp = stk_a_temp->next;
		}
		else
			ft_printf("\n   ");
		if (stk_b_temp)
		{
			ft_printf("    %d", stk_b_temp->value);
			stk_b_temp = stk_b_temp->next;
		}
		else
			ft_printf("");
	}
	ft_printf("\n___   ___");
	ft_printf("\n A     B \n\n");
}

void	ft_stks_print_info(t_stks *stks)
{
	ft_printf("\n NUM OPS: %d\n", stks->ops);
	ft_printf("stks->a_len:        %d  -  %d\n", stks->a_len, stks->b_len);
	ft_printf("stks->a_first_srtd: %d  -  %d\n", stks->a_first_srtd, stks->b_first_rev);
	ft_printf("stks->a_len_pend:   %d  -  %d\n", stks->a_len_pend, stks->b_len_pend);
	ft_printf("stks->a_half:       %d  -  %d\n", stks->a_half, stks->b_half);
	ft_printf("stks->a_pivot:      %d  -  %d\n", stks->a_pivot, stks->b_pivot);
	ft_printf("stks->a_last:       %d  -  %d\n", stks->a_last, stks->a_last);
}
