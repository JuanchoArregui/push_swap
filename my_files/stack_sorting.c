/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 18:20:38 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_a_sort_three(t_stks *stks)
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
	stks->current_stk = 'b';
	return (1);
}

int	ft_b_reverse_three(t_stks *stks)
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
	stks->current_stk = 'a';
	return (1);
}

int	ft_stks_sort(t_stks *stks)
{
	if (ft_is_sorted(stks->a) && stks->b == NULL)
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
			ft_printf("////////(stks->a)->value: %d - stks->a_pivot: %d\n", (stks->a)->value, stks->a_pivot);
			
			pa(stks);
			// if (stks->b && (stks->b)->value < ft_value_last(stks->b) && stks->a && (stks->a)->value > ft_value_last(stks->a))
			// 	rr(stks);
			// else if (stks->b && (stks->b)->value < ft_value_last(stks->b))
			// 	rb(stks);
			// else if (stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value && stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value)
			// 	ss(stks);
			// else if (stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value)
			// 	sb(stks);
			counter++;
		}
		else
		{
			// if (stks->b && (stks->b)->value < ft_value_last(stks->b))
			// 	rr(stks);
			// else
				ra(stks);
		}
	}
	stks->current_stk = 'a';
}

void	ft_divide_b(t_stks *stks)
{
	int		counter;

	ft_printf("ENTRANDO EN ft_divide_b");
	counter = 0;
	if (stks->b_half == 0)
		pb(stks);
	while (counter < stks->b_half)
	{
		ft_printf("////////(stks->b)->value: %d - stks->b_pivot: %d\n", (stks->b)->value, stks->b_pivot);
		
		if ((stks->b)->value > stks->b_pivot)
		{
			pb(stks);
			// if (stks->a && (stks->a)->value > ft_value_last(stks->a) && stks->b && (stks->b)->value < ft_value_last(stks->b))
			// 	rr(stks);
			// else if (stks->a && (stks->a)->value > ft_value_last(stks->a))
			// 	ra(stks);
			// else if (stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value && stks->b && (stks->b)->next && (stks->b)->value < (stks->b)->next->value)
			// 	ss(stks);
			// else if (stks->a && (stks->a)->next && (stks->a)->value > (stks->a)->next->value)
			// 	sb(stks);
			counter++;
		}
		else
		{
			// if (stks->a && (stks->a)->value > ft_value_last(stks->a))
			// 	rr(stks);
			// else
				rb(stks);
		}
	}
}

void	ft_divide_conquer(t_stks *stks)
{
	ft_check_stks(stks);


	ft_printf("\nSTACKS:\n");
	ft_printf("stks->current_stk: '%c'\n", stks->current_stk);
	ft_printf("stks->counter: %d\n", stks->counter);

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

	if (stks->a && stks->a_len <= 3 && !ft_is_sorted(stks->a))
	{
		ft_printf("*************** ordenamos A3 \n\n\n");
		ft_a_sort_three(stks);
	}
	else if (stks->b && stks->b_len <= 3 && !ft_is_reversed(stks->b))
	{
		ft_printf("*************** revertimos B3 \n\n\n");
		ft_b_reverse_three(stks);
	}
	else if (!stks->b && stks->a)
	{
		if (ft_is_reversed(stks->a))
		{
			ft_printf("*************** hacer función reverse!!!! \n\n\n");
		}
		else
		{
			ft_printf("*************** No B - continuamos con divide_a \n\n\n");
			ft_divide_a(stks);
		}
	}
	else if (!stks->a && stks->b)
	{
		if (ft_is_reversed(stks->b))
		{
			ft_printf("*************** ordenado rev B y solo queda volcar \n\n\n");
			dump_b(stks);
		}
		else if (ft_is_sorted(stks->b))
		{
			//hacer función reverse dump
			ft_printf("*************** hacer función reverse dumpppppppp!!!! \n\n\n");
		}
		else
		{
			ft_printf("*************** No A - continuamos con divide_b \n\n\n");
			ft_divide_b(stks);
		}
	}
	else if (stks->a && ft_is_sorted(stks->a) && stks->b && ft_is_reversed(stks->b))
	{
		if (stks->a->value > stks->b->value)
		{
			ft_printf("*************** ordenados y solo queda volcar \n\n\n");
			dump_b(stks);
		}
		else if (stks->b_last > stks->a_last)
		{
			ft_printf("*************** hacer función reverse dump!!!! \n\n\n");
		} 
		else if (stks->current_stk == 'a')
		{
			ft_printf("*************** continuamos con divide_a \n\n\n");
			ft_divide_a(stks);
		}
		else
		{
			ft_printf("*************** continuamos con divide_b \n\n\n");
			ft_divide_b(stks);
		}
	}
	else
	{
		if (stks->current_stk == 'a')
		{
			ft_printf("*************** aqui continuamos con divide_a \n\n\n");
			ft_divide_a(stks);
		}
		else{
			ft_printf("*************** aqui continuamos con divide_b \n\n\n");
			ft_divide_b(stks);
		}
	}

	// else if (!stks->current_stk || (stks->current_stk == 'a' && stks->a) || (stks->a && !stks->b))
	// {
	// 	ft_printf("BBBBBBBBB \n");
		
	// 	ft_divide_a(stks);
	// }
	// else if (stks->b && stks->b_len <= 3 && !ft_is_reversed(stks->b))
	// {
	// 	ft_printf("CCCCCCC \n");
		
	// 	ft_b_reverse_three(stks);
	// 	stks->current_stk = 'b';
	// }
	// else if (!stks->a || (stks->current_stk == 'b' && stks->b))
	// {
	// 	ft_printf("DDDDDDDDD \n");
		
	// 	ft_divide_b(stks);
	// 	stks->current_stk = 'b';
	// }
	// else if (stks->a && ft_is_sorted(stks->a) && stks->b && ft_is_reversed(stks->b) && (stks->a)->value > (stks->b)->value)
	// {
	// 	ft_printf("EEEEEEEEE \n");
		
	// 	dump_b(stks);
	// 	stks->current_stk = 0;
	// }
	// else
	// {
	// 	ft_printf("\nCHECAR ESTO AQUI NO DEBERIA LLEGAR CREO\n");
	// 	ft_stks_print(stks);
	// }
}
