/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 12:19:56 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/21 13:29:59 by jarregui         ###   ########.fr       */
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

void	ft_stack_print(t_stack *head, const char *mode)
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

int	ft_stack_is_sorted(t_stack *st_head)
{
	t_stack	*st_next;

	st_next = st_head;
	while (st_next && st_next->next)
	{
		if (st_next->value > st_next->next->value)
		{
			ft_printf("\nSTACK NOT SORTED");
			return (0);
		}
		st_next = st_next->next;
	}
	ft_printf("\nStack is sorted!!!");
	return (1);
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

