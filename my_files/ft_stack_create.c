/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/08 17:01:33 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*ft_init_stack(t_array_int *arg_num)
{
	int		i;
	t_stack	*next;

	i = arg_num->length - 1;
	next = NULL;
	while (i >= 0)
		next = ft_stack_elem_new(arg_num->array_int[i--], next);
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

void	ft_print_stack(t_stack *head)
{
	t_stack	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_printf("\n{\n value: %d, \n next: %p\n}", tmp->value, tmp->next);
		tmp = tmp->next;
	}
}