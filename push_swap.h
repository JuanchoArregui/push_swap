/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jarregui <jarregui@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/14 13:09:43 by jarregui         ###   ########.fr       */
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

typedef struct s_stks
{
	t_stack			*a;
	t_stack			*b;
	char			last_stk;
	int				last_a_sorted;
	int				debug;
	int				counter;
}	t_stks;



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
t_stack	*ft_stk_init(t_array_int *arg_num);
t_stack	*ft_stk_elem_new(int value, t_stack	*next);
void	ft_stk_free(t_stack *stk);
void	ft_stks_init(t_stks	*stks);

// Functions for STACKS handling
int		ft_stk_size(t_stack *stk);
int		ft_value_last(t_stack *stk);
int		ft_stk_get_pivot(t_stack *stk, int half);
int		ft_stk_a_is_sorted(t_stack *stk);
int		ft_stk_b_is_reversed(t_stack *stk);

// Functions for STACKS printing
void	ft_stk_print(t_stack *head, const char *mode);
void	ft_stks_print(t_stks *stks);

// Stack Operations
int		ft_swap(t_stack *stk);
int		sa(t_stks *stks);
int		sb(t_stks *stks);
int		ss(t_stks *stks);

int		ft_push(t_stks *stks, char source);
int		pa(t_stks *stks);
int		pb(t_stks *stks);

int		ft_rotate(t_stack *stk);
int		ra(t_stks *stks);
int		rb(t_stks *stks);
int		rr(t_stks *stks);

int		ft_reverse_rotate(t_stack *stk);
int		rra(t_stks *stks);
int		rrb(t_stks *stks);
int		rrr(t_stks *stks);

int		rasa(t_stks *stks);
int		sara(t_stks *stks);
int		rbsb(t_stks *stks);
int		sbrb(t_stks *stks);
void	dump_b(t_stks *stks);

// Functions for STACK SORTING
int		ft_stks_sort(t_stks *stks);
int		ft_stk_a_sort_three(t_stks *stks);
int		ft_stk_b_sort_three_reversed(t_stks *stks);
void	ft_divide_a(t_stks *stks);
void	ft_divide_b(t_stks *stks);
void	ft_divide_conquer(t_stks *stks);

#endif

