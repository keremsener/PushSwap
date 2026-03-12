/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 16:35:11 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <stdbool.h>

typedef enum e_strategy {
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_config {
	t_strategy	strategy;
	bool		bench_mode;
}	t_config;

typedef struct s_op_count {
	size_t	sa;
	size_t	sb;
	size_t	ss;
	size_t	pa;
	size_t	pb;
	size_t	ra;
	size_t	rb;
	size_t	rr;
	size_t	rra;
	size_t	rrb;
	size_t	rrr;
}	t_op_count;

typedef struct s_metrics
{
	double		disorder;
	t_config	config;
	t_op_count	ops;
}	t_metrics;

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
void	insertion_sort(t_list **a_head, t_list **b_head, t_op_count *ops);
void	selection_sort(t_list **a_head, t_list **b_head, t_op_count *ops);

// Medium

void	chunk_sort(t_list **a_head, t_list **b_head, t_op_count *ops);
void	turk_sort(t_list **a_head, t_list **b_head, t_op_count *ops);

//	Utilities

void	print_stack(t_list *a_head, t_list *b_head);
int		get_max_value(t_list *list);
int		get_min_value(t_list *list);
t_list	*get_max_node(t_list *list);
t_list	*get_min_node(t_list *list);
int		get_int(t_list *node);
double	compute_disorder(t_list *a_head);
void	print_bench(t_metrics metrics);
int	calc_chunk_size(int total_numbers);

#endif
