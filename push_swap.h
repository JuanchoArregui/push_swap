/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2024/02/21 14:45:14 by jarregui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "my_libs/libft/libft.h"
# include "my_libs/printf/printf.h"

// Struct for storing the array of integers and its length
typedef struct s_array_int
{
	unsigned int	length;
	int				*array_int;
}	t_array_int;

// Stack
// NOTA: lo llamo s_stack porque en la libft ya está definida esa estructura,
// como s_list pero de forma diferente.
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

// Functions for checking arguments. At ./args/ft_check_args.c
int		ft_unique(int num_to_check, unsigned int n, t_array_int *arg_num);
int		ft_arg_to_i(char **temp_args, unsigned int n, t_array_int *arg_num);
char	**ft_args_split(int argc, char **argv);
int		ft_args_to_num(char **temp_args, t_array_int *arg_num);
void	ft_args_check(int argc, char **argv, t_array_int *arg_num);

// Functions for general utils
void	ft_error(char **ptr_char, t_array_int *arg_num);
void	ft_print_array_str(char **array);
void	ft_print_t_array_int(t_array_int *arg_num);
void	ft_free_array_str(char **temp_args);

// Functions for STACKS handling
t_stack	*ft_stack_init(t_array_int *arg_num);
t_stack	*ft_stack_elem_new(int value, t_stack	*next);
int		ft_stack_is_sorted(t_stack *st_head);
void	ft_stack_free(t_stack **stack_ptr);

// Functions for STACKS printing
int		ft_stack_size(t_stack *stack);
void	ft_stack_print(t_stack *head, const char *mode);
void	ft_stacks_print(t_stack *stack_a, t_stack *stack_b);

// // Custom Functions from libft but adapted to new struct t_stack_node
// t_stack_node	*ft_lstnew(int value);
// t_stack_node	*ft_lstlast(t_stack_node *head);
// void	ft_lstadd_front(t_stack_node **stack, t_stack_node *new);
// void	ft_lstadd_back(t_stack_node **stack, t_stack_node *new);
// void	printList(t_stack_node *head);
// int		ft_lstsize(t_stack_node *head);

// // Util functions 
// int		is_sorted(t_stack_node **stack);
// int		get_distance(t_stack_node **stack, int index);
// void	make_top(t_stack_node **stack, int distance);
// void	free_stack(t_stack_node **stack);
// void	ft_free(char **str);

// // Algorithm utils
// void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b);
// void	simple_sort(t_stack_node **stack_a, t_stack_node **stack_b);
// void	index_stack(t_stack_node **stack);
// void	sort_5(t_stack_node **stack_a, t_stack_node **stack_b);

// // Instruction functions
// int		swap(t_stack_node **stack);
// int		push(t_stack_node **stack_to, t_stack_node **stack_from);
// int		rotate(t_stack_node **stack);
// int		reverseRotate(t_stack_node **stack);

// int		sa(t_stack_node **stack_a);
// int		sb(t_stack_node **stack_b);
// int		ss(t_stack_node **stack_a, t_stack_node **stack_b);
// int		pa(t_stack_node **stack_a, t_stack_node **stack_b);
// int		pb(t_stack_node **stack_b, t_stack_node **stack_a);
// int		ra(t_stack_node **stack_a);
// int		rb(t_stack_node **stack_b);
// int		rr(t_stack_node **stack_a, t_stack_node **stack_b);
// int		rra(t_stack_node **stack_a);
// int		rrb(t_stack_node **stack_b);
// int		rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif

