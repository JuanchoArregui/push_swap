/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:21 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 00:32:26 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_stack_sort_three(t_stack **stk)
{
	int	len;
	
	len = ft_stack_size(*stk);
	if (len == 2 && (*stk)->value > (*stk)->next->value)
		sa(stk);
	else if (len == 3 && (*stk)->value > (*stk)->next->value)
	{
		if ((*stk)->next->value > (*stk)->next->next->value)
			rasa(stk);
		else if ((*stk)->value > (*stk)->next->next->value)
			ra(stk);
		else
			sa(stk);
	}
	else if (len == 3 && (*stk)->next->value > (*stk)->next->next->value)
	{	
		if ((*stk)->value > (*stk)->next->next->value)
			rra(stk);
		else
			sara(stk);
	}
	return (1);
}

int	ft_stack_sort_three_reversed(t_stack **stk)
{
    int	len;
    
    len = ft_stack_size(*stk);
    if (len == 2 && (*stk)->value < (*stk)->next->value)
        sb(stk);
	else if (len == 3 && (*stk)->value < (*stk)->next->value)
	{
		if ((*stk)->next->value < (*stk)->next->next->value)
			rbsb(stk);
		else if ((*stk)->value < (*stk)->next->next->value)
			rb(stk);
		else
			sb(stk);
	}
	else if (len == 3 && (*stk)->next->value < (*stk)->next->next->value)
	{
		if ((*stk)->value < (*stk)->next->next->value)
			rrb(stk);
		else
			sbrb(stk);
	}
    return (1);
}

int	ft_stack_sort(t_stack **stack_a, t_stack **stack_b, char last)
{
	if (ft_stack_is_sorted(*stack_a) && *stack_b == NULL)
	{
		ft_printf("\nORDENADO\n");
		ft_printf("\nSTACKS ORDENADOS AL FINALIZAR:");
		ft_stacks_print(*stack_a, *stack_b);
		
		ft_stack_free(stack_a);
		ft_stack_free(stack_b);
		return (1);
	}
	else
	{
		ft_printf("\nAntes de divide and conquer:");
		ft_stacks_print(*stack_a, *stack_b);
		last = ft_divide_conquer(stack_a, stack_b, last);
	}
	ft_stack_sort(stack_a, stack_b, last);
	return (0);
}

void	divide_a(t_stack **stack_a, t_stack **stack_b)
{
	int		half;
	int		pivot;
	int		counter;

	half = ft_stack_size(*stack_a) / 2;
	pivot = ft_stack_get_pivot(stack_a, half);
	counter = 0;
	ft_printf("\ndivide_A. length: %d  half: %d\n", ft_stack_size(*stack_a), half);
	if (half == 0)
		pa(stack_a, stack_b);
	while (counter < half)
	{
		if ((*stack_a)->value <= pivot)
		{
			pa(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}

void	divide_b(t_stack **stack_a, t_stack **stack_b)
{
	int		half;
	int		pivot;
	int		counter;

	half = ft_stack_size(*stack_b) / 2;
	pivot = ft_stack_get_pivot(stack_b, half);
	counter = 0;
	ft_printf("\ndivide_B. length: %d  half: %d  pivot: %d\n", ft_stack_size(*stack_b), half, pivot);
	if (half == 0)
		pb(stack_a, stack_b);
	while (counter < half)
	{
		
		if ((*stack_b)->value >= pivot)
		{
			ft_printf("\nen el bucle while PB");
			pb(stack_a, stack_b);
			counter++;
		}
		else
		{

			rb(stack_b);
			ft_printf("\nen el bucle while PB");
		}
	}
}

char	ft_divide_conquer(t_stack **stack_a, t_stack **stack_b, char last)
{
	int		len_a;
	int		len_b;

	len_a = ft_stack_size(*stack_a);
	len_b = ft_stack_size(*stack_b);
	ft_printf("\nlen_a: %d\n", len_a);
	ft_printf("\nlen_b: %d\n", len_b);
	ft_printf("\nlast: %c\n", last);

	if (!last || (last == 'a' && *stack_a))
		return (divide_a(stack_a, stack_b), 'a');
	else if (!*stack_a || (last == 'b' && *stack_b))
		return (divide_b(stack_a, stack_b), 'b');
	// if (*stack_a && len_a <= 3 && !ft_stack_is_sorted(*stack_a))
	// 	ft_stack_sort_three(stack_a);
	// else if (*stack_a && !ft_stack_is_sorted(*stack_a) && len_a > 3)
	// 	divide_a(stack_a, stack_b);
	// else if (*stack_b && len_b <= 3 && !ft_stack_is_reverse_sorted(*stack_b))
	// 	ft_stack_sort_three_reversed(stack_b);
	// else if (*stack_b && !ft_stack_is_reverse_sorted(*stack_b) && len_b > 3)
	// 	divide_b(stack_a, stack_b);
	// else if (*stack_a && ft_stack_is_sorted(*stack_a) && *stack_b && !ft_stack_is_reverse_sorted(*stack_b))
	// 	dump_b(stack_a, stack_b);
	else
	{
		ft_printf("\nCHECAR ESTO AQUI NO DEBERIA LLEGAR CREO\n");
		ft_stacks_print(*stack_a, *stack_b);
		return (0);
	}

}

