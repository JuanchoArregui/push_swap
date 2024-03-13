/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 23:17:49 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stack_init(t_array_int *arg_num)
{
	int		i;
	t_stack	*next;

	i = arg_num->length - 1;
	next = NULL;
	while (i >= 0)
		next = ft_stack_elem_new(arg_num->array_int[i--], next);
	if (arg_num->array_int != NULL)
	{
		free(arg_num->array_int);
		arg_num->array_int = NULL;
	}
	return (next);
}

t_stack	*ft_stack_elem_new(int value, t_stack	*next)
{
	t_stack	*stack_elem;

	stack_elem = malloc(sizeof(t_stack));
	if (!stack_elem)
		return (NULL);
	stack_elem->value = value;
	stack_elem->next = next;
	return (stack_elem);
}

void	ft_stack_free(t_stack **stack_ptr)
{
	t_stack	*st_current;
	t_stack	*st_next;

	st_next = NULL;
	st_current = *stack_ptr;
	*stack_ptr = NULL;
	while (st_current)
	{
		st_next = st_current->next;
		free(st_current);
		st_current = st_next;
	}
}

void	ft_stuff_init(t_stuff	*stuff)
{
	if (stuff)
	{
		stuff->debug = 0;
		stuff->last_a_sorted = 0;
		stuff->last_stk = 'a';
		stuff->counter = 0;
	}
}