/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/13 23:16:23 by juancho          ###   ########.fr       */
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

typedef struct s_stuff
{
	int				debug;
	int				last_a_sorted;
	char 			last_stk;
	int				counter;
}	t_stuff;



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

// Functions for STACKS init
t_stack	*ft_stack_init(t_array_int *arg_num);
t_stack	*ft_stack_elem_new(int value, t_stack	*next);
void	ft_stack_free(t_stack **stack_ptr);
void	ft_stuff_init(t_stuff	*stuff);

// Functions for STACKS handling
int		ft_stack_size(t_stack *stack);
int		ft_value_last(t_stack **stk);
int		ft_stack_get_pivot(t_stack **stack, int half);
int		ft_stack_is_sorted(t_stack *st_head);
int		ft_stack_is_reverse_sorted(t_stack *st_head);

// Functions for STACKS printing
void	ft_stack_print(t_stack *head, const char *mode);
void	ft_stacks_print(t_stack *stack_a, t_stack *stack_b);

// Stack Operations
int		ft_swap(t_stack **stack_ptr);
int		sa(t_stack **stack_a);
int		sb(t_stack **stack_b);
int		ss(t_stack **stack_a, t_stack **stack_b);

int		ft_push(t_stack **stack_a, t_stack **stack_b);
int		pa(t_stack **stack_a, t_stack **stack_b);
int		pb(t_stack **stack_b, t_stack **stack_a);

int		ft_rotate(t_stack **stack_ptr);
int		ra(t_stack **stack_a);
int		rb(t_stack **stack_a);
int		rr(t_stack **stack_a, t_stack **stack_b);

int		ft_reverse_rotate(t_stack **stack_ptr);
int		rra(t_stack **stack_a);
int		rrb(t_stack **stack_a);
int		rrr(t_stack **stack_a, t_stack **stack_b);

int		rasa(t_stack **stack_a);
int		sara(t_stack **stack_a);
int		rbsb(t_stack **stack_b);
int		sbrb(t_stack **stack_b);
void	dump_b(t_stack **stack_a, t_stack **stack_b);

// Functions for STACK SORTING
int		ft_stack_sort(t_stack **stack_a, t_stack **stack_b, char last);
int		ft_stack_sort_three(t_stack **stk);
int		ft_stack_sort_three_reversed(t_stack **stk);
void	divide_a(t_stack **stack_a, t_stack **stack_b);
void	divide_b(t_stack **stack_a, t_stack **stack_b);
char	ft_divide_conquer(t_stack **stack_a, t_stack **stack_b, char last);

#endif

