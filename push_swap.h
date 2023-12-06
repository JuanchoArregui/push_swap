/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/06 09:51:20 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_node
{
	int				value;
	int				index;
	struct s_stack_node	*next;
}	t_stack_node;


// Custom Functions from libft but adapted to new struct s_stack_node
s_stack_node	*ft_lstnew(int value);
s_stack_node	*ft_lstlast(s_stack_node *head);
void	ft_lstadd_front(s_stack_node **stack, s_stack_node *new);
void	ft_lstadd_back(s_stack_node **stack, s_stack_node *new);
void	printList(s_stack_node *head);
int		ft_lstsize(s_stack_node *head);

// Util functions 
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(s_stack_node **stack);
int		get_distance(s_stack_node **stack, int index);
void	make_top(s_stack_node **stack, int distance);
void	free_stack(s_stack_node **stack);
void	ft_free(char **str);

// Algorithm utils
void	radix_sort(s_stack_node **stack_a, s_stack_node **stack_b);
void	simple_sort(s_stack_node **stack_a, s_stack_node **stack_b);
void	index_stack(s_stack_node **stack);
void	sort_5(s_stack_node **stack_a, s_stack_node **stack_b);

// Instruction functions
int		swap(s_stack_node **stack);
int		push(s_stack_node **stack_to, s_stack_node **stack_from);
int		rotate(s_stack_node **stack);
int		reverseRotate(s_stack_node **stack);

int		sa(s_stack_node **stack_a);
int		sb(s_stack_node **stack_b);
int		ss(s_stack_node **stack_a, s_stack_node **stack_b);
int		pa(s_stack_node **stack_a, s_stack_node **stack_b);
int		pb(s_stack_node **stack_b, s_stack_node **stack_a);
int		ra(s_stack_node **stack_a);
int		rb(s_stack_node **stack_b);
int		rr(s_stack_node **stack_a, s_stack_node **stack_b);
int		rra(s_stack_node **stack_a);
int		rrb(s_stack_node **stack_b);
int		rrr(s_stack_node **stack_a, s_stack_node **stack_b);

#endif

