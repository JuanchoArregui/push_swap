/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/17 19:13:48 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stks_sort(t_stks *stks)
{
	if (ft_is_sort(stks->a) && stks->b == NULL)
	{
		if (stks->debug)
		{
			ft_stks_print(stks);
			ft_printf("\nTotal operaciones efectuadas: %d", stks->ops);
		}
		ft_stk_free(stks->a);
		ft_stk_free(stks->b);
		return (1);
	}
	else
	{
		ft_check_stks(stks);
		if (stks->debug)
		{
			ft_stks_print(stks);
			ft_stks_print_info(stks);
		}
		ft_divide_conquer(stks);
	}
	ft_stks_sort(stks);
	return (0);
}

void	ft_divide_a(t_stks *stks)
{
	int		counter;
	int		to_restore;

	if (stks->debug)
		ft_printf("*************** A no ordenado -> continuamos con divide_a \n");
	counter = 0;
	to_restore = 0;
	if (stks->a_len_pend == 2)
		sa(stks);
	else
	{
		while (counter < stks->a_half)
		{
			if ((stks->a)->value < stks->a_pivot)
			{
				// ft_printf("////////(stks->a)->value: %d - stks->a_pivot: %d\n", (stks->a)->value, stks->a_pivot);
				
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
					to_restore++;
			}
		}
	}
	ft_a_restore(stks, to_restore);
}

void	ft_divide_b(t_stks *stks)
{
	int		counter;
	int		to_restore;

	if (stks->debug)
		ft_printf("*************** A ordenado, pero B desordenado -> con divide_b \n");
	counter = 0;
	to_restore = 0;
	if (stks->b_len_pend == 2)
		pb(stks);
	else
	{
		while (counter < stks->b_half)
		{
			// ft_printf("////////(stks->b)->value: %d - stks->b_pivot: %d\n", (stks->b)->value, stks->b_pivot);
			
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
					to_restore++;
			}
		}
		ft_b_restore(stks, to_restore);
	}
}

void	ft_divide_conquer(t_stks *stks)
{
	if (stks->a && stks->a_len <= 3)
	{
		if (!ft_is_sort(stks->a))
		{
			ft_a_sort_three(stks);
		}
		else
		{
			ft_printf("*************** A3 OK - pasamos a divide_b \n\n\n");
			ft_divide_b(stks);
		}
	}
	else if (stks->b && stks->b_len <= 3)
	{
		if (!ft_is_rev(stks->b))
		{
			ft_b_reverse_three(stks);
		}
		else if (ft_is_sort(stks->a))
		{
			dump_b(stks);
		}
		else
		{
			ft_printf("*************** B3 OK - pasamos a divide_a \n\n\n");
			ft_divide_a(stks);
		}
	}
	else
	{
		if (!ft_is_sort(stks->a))
		{
			ft_divide_a(stks);
		}
		else if (!ft_is_rev(stks->b))
		{
			ft_divide_b(stks);
		} else
		{
			ft_printf("*************** ordenados y solo queda volcar \n\n\n");
			dump_b(stks);
		}
	}
}
