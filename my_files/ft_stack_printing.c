#include "../push_swap.h"

int	ft_stack_size(t_stack *stack)
{
	int	len;

	len = 0;
	while (stack)
	{
		len ++;
		stack = stack->next;
	}
	return (len);
}

void	ft_stacks_print(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("\n\n\nSTACKS:\n");
	while (stack_a || stack_b)
	{
		if (stack_a)
		{
			ft_printf("\n%d", stack_a->value);
			stack_a = stack_a->next;
		}
		else
			ft_printf("\n   ");
		if (stack_b)
		{
			ft_printf("%d", stack_b->value);
			stack_b = stack_b->next;
		}
		else
			ft_printf("   ");
	}
	ft_printf("\n___   ___");
	ft_printf("\n A     B \n\n");
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