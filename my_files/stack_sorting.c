/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 14:26:21 by jarregui         ###   ########.fr       */
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
	if (ft_stk_a_is_sorted(stks->a) && stks->b == NULL)
	{
		if (stks->debug)
		{
			ft_stks_print(stks);
			ft_printf("Total operaciones efectuadas: %d", stks->counter);
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
		ft_printf("hemos terminado ft_divide_conquer");

	}
	ft_stks_sort(stks);
	return (0);
}

void	ft_divide_a(t_stks *stks)
{
	int		half;
	int		pivot;
	int		counter;

	half = ft_stk_size(stks->a) / 2;
	pivot = ft_stk_get_pivot(stks->a, half);
	counter = 0;


	ft_printf("\ndentro de ft_divide_a half: %d  pivot: %d", half, pivot);
	ft_printf("\n stks->a : %p", stks->a);
	ft_printf("\n stks->b : %p", stks->b);
	ft_printf("\n stks->debug : %d", stks->debug);
	ft_printf("\n stks->last_stk : %c", stks->last_stk);
	
	
	if (half == 0)
		pa(stks);
	while (counter < half)
	{
		ft_printf("\n en el while (stks->a)->value: %d", (stks->a)->value);
		
		if ((stks->a)->value <= pivot)
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
}

void	ft_divide_b(t_stks *stks)
{
	int		half;
	int		pivot;
	int		counter;

	half = ft_stk_size(stks->b) / 2;
	pivot = ft_stk_get_pivot(stks->b, half);
	counter = 0;
	ft_printf("\nft_divide_b. length: %d  half: %d  pivot: %d\n", ft_stk_size(stks->b), half, pivot);
	if (half == 0)
		pb(stks);
	while (counter < half)
	{
		if ((stks->b)->value >= pivot)
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
	int		len_a;
	int		len_b;

	len_a = ft_stk_size(stks->a);
	len_b = ft_stk_size(stks->b);

	ft_printf("\n\n entrando en divide and conquer");
	ft_printf("\n stks->a : %p", stks->a);
	ft_printf("\n stks->b : %p", stks->b);
	ft_printf("\n stks->debug : %d", stks->debug);
	ft_printf("\n stks->last_stk : %c", stks->last_stk);

	if (stks->a && len_a <= 3 && !ft_stk_a_is_sorted(stks->a))
	{
		ft_printf("\n AAAAAAA");
		ft_stk_a_sort_three(stks);
		stks->last_stk = 0;
	}
	else if (!stks->last_stk || (stks->last_stk == 'a' && stks->a) || (stks->a && !stks->b))
	{
		ft_printf("\n BBBBB");
		ft_divide_a(stks);
		stks->last_stk = 'a';
	}
	else if (stks->b && len_b <= 3 && !ft_stk_b_is_reversed(stks->b))
	{
		ft_printf("\n CCCCC");
		ft_stk_b_sort_three_reversed(stks);
		stks->last_stk = 'b';
	}
	else if (!stks->a || (stks->last_stk == 'b' && stks->b))
	{
		ft_printf("\n DDDDD");
		ft_divide_b(stks);
		stks->last_stk = 'b';
	}
	else if (stks->a && ft_stk_a_is_sorted(stks->a) && stks->b && ft_stk_b_is_reversed(stks->b) && (stks->a)->value > (stks->b)->value)
	{
		ft_printf("\n EEEEE");
		dump_b(stks);
		stks->last_stk = 0;
	}
	else
	{
		ft_printf("\nCHECAR ESTO AQUI NO DEBERIA LLEGAR CREO\n");
		ft_stks_print(stks);
	}
}
