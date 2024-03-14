/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_printing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 15:53:38 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 15:45:19 by jarregui         ###   ########.fr       */
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

void	ft_stk_print(t_stack *head, const char *mode)
{
	t_stack	*tmp;
	int		brackets;

	if (mode && ft_strcmp(mode, "detalle") == 0)
		brackets = 1;
	else
		brackets = 0;
	tmp = head;
	while (tmp != NULL)
	{
		if (brackets)
			ft_printf("\n{\n value: %d, \n next: %p\n}", tmp->value, tmp->next);
		else
		{
			ft_printf("%d", tmp->value);
			if (tmp->next != NULL)
				ft_printf(" -> ");
		}
		tmp = tmp->next;
	}
}
