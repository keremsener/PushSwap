/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 19:10:28 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}				t_strategy;

typedef struct s_config
{
	t_strategy	strategy;
	bool		bench_mode;
}				t_config;

typedef struct s_op_count
{
	size_t		sa;
	size_t		sb;
	size_t		ss;
	size_t		pa;
	size_t		pb;
	size_t		ra;
	size_t		rb;
	size_t		rr;
	size_t		rra;
	size_t		rrb;
	size_t		rrr;
}				t_op_count;

typedef struct s_metrics
{
	double		disorder;
	t_config	config;
	t_op_count	ops;
}				t_metrics;

//	Operations

bool	push(t_list **from, t_list **to);
bool	swap(t_list **stack);
bool	rotate(t_list **stack);
bool	rotate_reverse(t_list **stack);

//	Commands

void	sa(t_list **a, t_op_count *ops);
void	sb(t_list **b, t_op_count *ops);
void	ss(t_list **a, t_list **b, t_op_count *ops);
void	pb(t_list **b, t_list **a, t_op_count *ops);
void	pa(t_list **a, t_list **b, t_op_count *ops);
void	ra(t_list **a, t_op_count *ops);
void	rb(t_list **b, t_op_count *ops);
void	rr(t_list **a, t_list **b, t_op_count *ops);
void	rra(t_list **a, t_op_count *ops);
void	rrb(t_list **b, t_op_count *ops);
void	rrr(t_list **a, t_list **b, t_op_count *ops);

//	Sorting algorithms

void	buble_sort(t_list **a_head, t_op_count *ops);
void	insertion_sort(t_list **a_head, t_list **b_head,
			t_op_count *ops);
void	selection_sort(t_list **a_head, t_list **b_head,
			t_op_count *ops);

// Medium

void	chunk_sort(t_list **a_head, t_list **b_head, t_op_count *ops);
void	turk_sort(t_list **a_head, t_list **b_head, t_op_count *ops);

// Complex

void	up_turk_sort(t_list **a_head, t_list **b_head, t_op_count *ops);

//	Utilities

double	compute_disorder(t_list *a_head);
void	error(void);
int		get_int(t_list *node);
t_list	*get_max_node(t_list *list);
t_list	*get_min_node(t_list *list);
t_list	*parse(int argc, const char *argv[], t_config *config);
void	print_bench(t_metrics metrics);
void	print_stack(t_list *a_head, t_list *b_head);
int		calc_chunk_size(int total_numbers);
void	move_b_to_top(t_list **b_head, t_list *cheapest_b, int b_size,
			t_op_count *ops);

// Bonus

int		checker(t_list **a_head, t_list **b_head, t_op_count *ops, int size);

#endif
