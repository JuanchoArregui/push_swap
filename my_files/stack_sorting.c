/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 00:20:02 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stk_a_sort_three(t_stks *stks)
{
	int	len;

	len = ft_stk_size(stks->a);
	if (len == 2 && (stks->a)->value > (stks->a)->next->value)
		sa(stks);
	else if (len == 3 && (stks->a)->value > (stks->a)->next->value)
	{
		if ((stks->a)->next->value > (stks->a)->next->next->value)
			rasa(stks);
		else if ((stks->a)->value > (stks->a)->next->next->value)
			ra(stks);
		else
			sa(stks);
	}
	else if (len == 3 && (stks->a)->next->value > (stks->a)->next->next->value)
	{
		if ((stks->a)->value > (stks->a)->next->next->value)
			rra(stks);
		else
			sara(stks);
	}
	return (1);
}

int	ft_stk_b_sort_three_reversed(t_stks *stks)
{
	int	len;

	len = ft_stk_size(stks->b);
	if (len == 2 && (stks->b)->value < (stks->b)->next->value)
		sb(stks);
	else if (len == 3 && (stks->b)->value < (stks->b)->next->value)
	{
		if ((stks->b)->next->value < (stks->b)->next->next->value)
			rbsb(stks);
		else if ((stks->b)->value < (stks->b)->next->next->value)
			rb(stks);
		else
			sb(stks);
	}
	else if (len == 3 && (stks->b)->next->value < (stks->b)->next->next->value)
	{
		if ((stks->b)->value < (stks->b)->next->next->value)
			rrb(stks);
		else
			sbrb(stks);
	}
	return (1);
}

int	ft_stks_sort(t_stks *stks)
{
	if (ft_a_is_sorted(stks->a) && stks->b == NULL)
	{
		if (stks->debug)
		{
			ft_stks_print(stks);
			ft_printf("\nTotal operaciones efectuadas: %d", stks->counter);
		}
		ft_stk_free(stks->a);
		ft_stk_free(stks->b);
		return (1);
	}
	else
	{
		if (stks->debug)
			ft_stks_print(stks);
			
		ft_divide_conquer(stks);
	}
	ft_stks_sort(stks);
	return (0);
}

void	ft_divide_a(t_stks *stks)
{
	int		counter;

	counter = 0;
	if (stks->a_half == 0)
		pa(stks);
	while (counter < stks->a_half)
	{
		if ((stks->a)->value <= stks->a_pivot)
		{
			pa(stks);
			if (stks->b && (stks->b)->value < ft_value_last(stks->b) && stks->a && (stks->a)->value > ft_value_last(stks->a))
				rr(stks);
			else if (stks->b && (stks->b)->value < ft_value_last(stks->b))
				rb(stks);
			else if (stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value && stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value)
				ss(stks);
			else if (stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value)
				sb(stks);
			counter++;
		}
		else
		{
			if (stks->b && (stks->b)->value < ft_value_last(stks->b))
				rr(stks);
			else
				ra(stks);
		}
	}
	stks->last_stk = 'a';
}

void	ft_divide_b(t_stks *stks)
{
	int		counter;

	counter = 0;
	if (stks->b_half == 0)
		pb(stks);
	while (counter < stks->b_half)
	{
		if ((stks->b)->value >= stks->b_pivot)
		{
			pb(stks);
			if (stks->a && (stks->a)->value > ft_value_last(stks->a) && stks->b && (stks->b)->value < ft_value_last(stks->b))
				rr(stks);
			else if (stks->a && (stks->a)->value > ft_value_last(stks->a))
				ra(stks);
			else if (stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value && stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value)
				ss(stks);
			else if (stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value)
				sb(stks);
			counter++;
		}
		else
		{
			if (stks->a && (stks->a)->value > ft_value_last(stks->a))
				rr(stks);
			else
				rb(stks);
		}
	}
}

void	ft_divide_conquer(t_stks *stks)
{
	ft_check_stks(stks);

	ft_printf("\nSTACK A settings:\n");
	ft_printf("stks->a_len: %d\n", stks->a_len);
	ft_printf("stks->a_first_srtd: %d\n", stks->a_first_srtd);
	ft_printf("stks->a_len_pend: %d\n", stks->a_len_pend);
	ft_printf("stks->a_half: %d\n", stks->a_half);
	ft_printf("stks->a_pivot: %d\n", stks->a_pivot);
	ft_printf("stks->a_last: %d\n", stks->a_last);


	ft_printf("\nSTACK B settings:\n");
	ft_printf("stks->b_len: %d\n", stks->b_len);
	ft_printf("stks->b_first_rev: %d\n", stks->b_first_rev);
	ft_printf("stks->b_len_pend: %d\n", stks->b_len_pend);
	ft_printf("stks->b_half: %d\n", stks->b_half);
	ft_printf("stks->b_pivot: %d\n\n", stks->b_pivot);
	ft_printf("stks->b_last: %d\n\n", stks->b_last);


	if (stks->a && stks->a_len <= 3 && !ft_a_is_sorted(stks->a))
	{
		ft_printf("AAAAAAAAAA \n");
		ft_stk_a_sort_three(stks);
		stks->last_stk = 0;
	}
	else if (!stks->last_stk || (stks->last_stk == 'a' && stks->a) || (stks->a && !stks->b))
	{
		ft_printf("BBBBBBBBB \n");
		
		ft_divide_a(stks);
	}
	else if (stks->b && stks->b_len <= 3 && !ft_b_is_reversed(stks->b))
	{
		ft_printf("CCCCCCC \n");
		
		ft_stk_b_sort_three_reversed(stks);
		stks->last_stk = 'b';
	}
	else if (!stks->a || (stks->last_stk == 'b' && stks->b))
	{
		ft_printf("DDDDDDDDD \n");
		
		ft_divide_b(stks);
		stks->last_stk = 'b';
	}
	else if (stks->a && ft_a_is_sorted(stks->a) && stks->b && ft_b_is_reversed(stks->b) && (stks->a)->value > (stks->b)->value)
	{
		ft_printf("EEEEEEEEE \n");
		
		dump_b(stks);
		stks->last_stk = 0;
	}
	else
	{
		ft_printf("\nCHECAR ESTO AQUI NO DEBERIA LLEGAR CREO\n");
		ft_stks_print(stks);
	}
}
