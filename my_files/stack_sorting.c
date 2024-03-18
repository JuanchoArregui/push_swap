/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/18 16:38:55 by jarregui         ###   ########.fr       */
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
			ft_printf("\nTotal operaciones efectuadas: %d\n", stks->ops);
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
			ft_printf("\n\n\n\n\nSITUACION ANTES DE IR A DIVIDE & CONQUER:\n");
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
		ft_printf(">>>>> A no ordenado -> continuamos con divide_a \n");
	counter = 0;
	to_restore = 0;
	if (stks->a_len_pend == 2)
		sa(stks);
	else
	{
		while (counter < stks->a_half)
		{
			if (stks->a->value < stks->a_pivot)
			{
				// ft_printf("////////(stks->a)->value: %d - stks->a_pivot: %d\n", (stks->a)->value, stks->a_pivot);
				pa(stks);
				// if (stks->b->value < ft_value_last(stks->b))
				// {
				// 	ft_printf("WARNING A: hemos pasado algo abajo. REVISAR!!!!!!!!!! \n");
					
				// 	if (stks->a && stks->a->value > ft_value_last(stks->a))
				// 		rr(stks); //// mirar esto
				// 	else
				// 		rb(stks);
				// }
				// else 
				if (stks->b->next && stks->b->value < stks->b->next->value)
				{
					if (stks->a && stks->a->next && stks->a->value > stks->a->next->value)
						ss(stks);
					else
						sb(stks);
				}
				counter++;
				if (counter == stks->a_half - 1)
					stks->b->batch_limit = 1;
			}
			else
			{
				//ra(stks); this main op here
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
		ft_printf(">>>>> A ordenado, pero B desordenado -> con divide_b \n");
	counter = 0;
	to_restore = 0;
	while (counter < stks->b_len_pend)
	{
		if (stks->b->value > stks->b_pivot)
		{
			pb(stks);
			// if (stks->a->value > ft_value_last(stks->a))
			// {
			// 	ft_printf("WARNING B: hemos pasado algo abajo. REVISAR!!!!!!!!!! \n");
				
			// 	if (stks->b && stks->b->value < ft_value_last(stks->b))
			// 		rr(stks); //// mirar esto
			// 	else
			// 		ra(stks);
			// }
			// else 
			if (stks->a->next && stks->a->value > stks->a->next->value)
			{
				if (stks->b && stks->b->next && stks->b->value < stks->b->next->value)
					ss(stks);
				else
					sa(stks);
			}
		}
		else
		{
			rb(stks);
			to_restore++;
		}
		counter++;
	}
	ft_b_restore(stks, to_restore);

}

void	ft_divide_conquer(t_stks *stks)
{
	if (stks->debug)
		ft_printf("\nDECISION A TOMAR: \n");
	if (stks->a && stks->a_len <= 3 && !ft_is_sort(stks->a))
	{
		ft_a_sort_three(stks);
	}
	else if (stks->b && stks->b_len <= 3 && !ft_is_rev(stks->b))
	{
		ft_b_reverse_three(stks);
	}
	else if (ft_is_rev(stks->b) && (ft_is_sort(stks->a) || !stks->a))
	{
		ft_dump_b(stks);
	}
	else if (!ft_is_sort(stks->a))
	{
		ft_divide_a(stks);
	}
	else if (ft_batch_is_rev(stks->b))
	{
		ft_dump_batch(stks);
	}
	else
	{
		ft_divide_b(stks);
	}
}
