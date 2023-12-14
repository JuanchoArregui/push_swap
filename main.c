/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:20:38 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/14 16:04:30 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_array(int argc, char **argv)
{
	int	i;

	i = 0;
	ft_printf("argc: %d\n", argc);
	ft_printf("[");
	while (i <argc)
	{
		ft_printf("%s", argv[i]);
		if (i < argc - 1)
		ft_printf(", ");
		i++;
	}
	ft_printf("]\n");
}


int main(int argc, char **argv)
{

	ft_printf("argc: %d\n", argc);
	ft_printf("Array of arguments argv: ");
	ft_print_array(argc, argv);

	if (argc < 2)
		return (-1);
	ft_check_args(argc, argv);

	ft_printf("Args are ok\n");
	ft_printf("Checked Array of numbers: ");
	ft_print_array(argc, argv);

	// if (argc == 2) {
	//       i = 1;
	//       int spaces = 0;
	//       while (argv[1][i] != '\0') {
	//       if (argv[1][i] == ' ')
	//       spaces++;
	//       i++;
	//       }
	//       printf("spaces: %d\n", spaces);
	//       return 1;
	// } else {
	//       j = 0;
	//       while (j < argc - 1)
	//       {
	//		 numbers[j] = ft_atoi(argv[j + 1]);
	//		 j++;
	//       }
	//       printf("Array of numbers: [");
	//       for (int i = 0; i < argc - 1; i++) {
	//       printf("%d, ", numbers[i]);
	//       }
	//       printf("]\n");
	//       return 1;
	// }

	// for (i = 1; i < argc; i++) {
	//       char* end;
	//       long val = strtol(argv[i], &end, 10);
	//       if (end == argv[i] || *end != '\0') {
	//       printf("Error\n");
	//       return 1;
	//       }

	//       for (j = 0; j < i - 1; j++) {
	//       if (numbers[j] == val) {
	//       printf("Error\n");
	//       return 1;
	//       }
	//       }

	//       numbers[i - 1] = val;
	// }

	ft_printf("No duplicates found\n");
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	t_stack_node	**stack_a;
// 	t_stack_node	**stack_b;

// 	if (argc < 2)
// 		return (-1);
// 	ft_check_args(argc, argv);
	// stack_a = (t_stack_node **)malloc(sizeof(t_stack_node));
	// stack_b = (t_stack_node **)malloc(sizeof(t_stack_node));
	// *stack_a = NULL;
	// *stack_b = NULL;
	// ft_stack_init(stack_a, argc, argv);
	// if (is_sorted(stack_a))
	// {
	// 	free_stack(stack_a);
	// 	free_stack(stack_b);
	// 	return (0);
	// }
	// ft_stack_sort(stack_a, stack_b);
	// free_stack(stack_a);
	// free_stack(stack_b);
// 	return (0);
// }

