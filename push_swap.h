/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2024/03/16 02:22:20 by juancho          ###   ########.fr       */
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
	int				a_len;
	int				a_first_srtd;
	int				a_len_pend;
	int				a_half;
	int				a_pivot;
	int				a_last;
	t_stack			*b;
	int				b_len;
	int				b_first_rev;
	int				b_len_pend;
	int				b_half;
	int				b_pivot;
	int				b_last;
	char			current_stk;
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
size_t	ft_arg_size(const char *s);

// Functions for STACKS init
t_stack	*ft_stk_init(t_array_int *arg_num);
t_stack	*ft_stk_elem_new(int value, t_stack	*next);
void	ft_stk_free(t_stack *stk);

// Functions for STACKS handling
int		ft_stk_size(t_stack *stk);
int		ft_value_last(t_stack *stk);
int		ft_fst_a_ok(t_stack *stk, int val);
int		ft_fst_b_ok(t_stack *stk, int val);


void	ft_a_get_pivot(t_stks *stks);
void	ft_b_get_pivot(t_stks *stks);

// Functions for STACKS check
int		ft_is_sort(t_stack *stk);
int		ft_is_rev(t_stack *stk);
void	ft_a_check(t_stks *stks);
void	ft_b_check(t_stks *stks);
void	ft_check_stks(t_stks *stks);

// Functions for STACKS printing
void	ft_stk_print(t_stack *head, const char *mode);
void	ft_stks_print(t_stks *stks);

// Stack Operations
int		ft_swap(t_stack **stk);
int		sa(t_stks *stks);
int		sb(t_stks *stks);
int		ss(t_stks *stks);

int		ft_push(t_stks *stks, char source);
int		pa(t_stks *stks);
int		pb(t_stks *stks);

int		ft_rotate(t_stack **stk);
int		ra(t_stks *stks);
int		rb(t_stks *stks);
int		rr(t_stks *stks);

int		ft_reverse_rotate(t_stack **stk);
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
int		ft_a_sort_three(t_stks *stks);
int		ft_b_reverse_three(t_stks *stks);
void	ft_divide_a(t_stks *stks);
void	ft_divide_b(t_stks *stks);
void	ft_divide_conquer(t_stks *stks);

#endif
