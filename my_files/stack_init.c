/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/15 14:10:03 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_stk_init(t_array_int *arg_num)
{
	int		i;
	t_stack	*next;

	i = arg_num->length - 1;
	next = NULL;
	while (i >= 0)
		next = ft_stk_elem_new(arg_num->array_int[i--], next);
	if (arg_num->array_int != NULL)
	{
		free(arg_num->array_int);
		arg_num->array_int = NULL;
	}
	return (next);
}

t_stack	*ft_stk_elem_new(int value, t_stack	*next)
{
	t_stack	*stack_elem;

	stack_elem = malloc(sizeof(t_stack));
	if (!stack_elem)
		return (NULL);
	stack_elem->value = value;
	stack_elem->next = next;
	return (stack_elem);
}

void	ft_stk_free(t_stack *stk)
{
	t_stack	*stk_current;
	t_stack	*stk_next;

	stk_next = NULL;
	stk_current = stk;
	stk = NULL;
	while (stk_current)
	{
		stk_next = stk_current->next;
		free(stk_current);
		stk_current = stk_next;
	}
}
