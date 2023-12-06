/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juancho <juancho@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:19:37 by jarregui          #+#    #+#             */
/*   Updated: 2023/12/06 10:10:25 by juancho          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack_node
{
	int					value;
	int					index;
	struct s_stack_node	*next;
}	t_stack_node;


// Custom Functions from libft but adapted to new struct t_stack_node
t_stack_node	*ft_lstnew(int value);
t_stack_node	*ft_lstlast(t_stack_node *head);
void	ft_lstadd_front(t_stack_node **stack, t_stack_node *new);
void	ft_lstadd_back(t_stack_node **stack, t_stack_node *new);
void	printList(t_stack_node *head);
int		ft_lstsize(t_stack_node *head);

// Util functions 
void	ft_error(char *msg);
void	ft_check_args(int argc, char **argv);
int		is_sorted(t_stack_node **stack);
int		get_distance(t_stack_node **stack, int index);
void	make_top(t_stack_node **stack, int distance);
void	free_stack(t_stack_node **stack);
void	ft_free(char **str);

// Algorithm utils
void	radix_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void	simple_sort(t_stack_node **stack_a, t_stack_node **stack_b);
void	index_stack(t_stack_node **stack);
void	sort_5(t_stack_node **stack_a, t_stack_node **stack_b);

// Instruction functions
int		swap(t_stack_node **stack);
int		push(t_stack_node **stack_to, t_stack_node **stack_from);
int		rotate(t_stack_node **stack);
int		reverseRotate(t_stack_node **stack);

int		sa(t_stack_node **stack_a);
int		sb(t_stack_node **stack_b);
int		ss(t_stack_node **stack_a, t_stack_node **stack_b);
int		pa(t_stack_node **stack_a, t_stack_node **stack_b);
int		pb(t_stack_node **stack_b, t_stack_node **stack_a);
int		ra(t_stack_node **stack_a);
int		rb(t_stack_node **stack_b);
int		rr(t_stack_node **stack_a, t_stack_node **stack_b);
int		rra(t_stack_node **stack_a);
int		rrb(t_stack_node **stack_b);
int		rrr(t_stack_node **stack_a, t_stack_node **stack_b);

#endif

