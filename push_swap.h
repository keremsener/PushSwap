/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 02:29:18 by adede            ###   ########.fr       */
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
} t_strategy;

typedef struct s_config {
	t_strategy			strategy;
	bool				bench_mode;
} t_config;

typedef struct s_operation_count {
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
} t_operation_count;

typedef struct s_metrics
{
	double				disorder;
	t_config			config;
	t_operation_count	ops;
} t_metrics;

//	Commands

void	sa(t_list **a);
void	sb(t_list **b);
void	ss(t_list **a, t_list **b);
void	pb(t_list **b, t_list **a);
void	pa(t_list **a, t_list **b);
void	ra(t_list **a);
void	rb(t_list **b);
void	rr(t_list **a, t_list **b);
void	rra(t_list **a);
void	rrb(t_list **b);
void	rrr(t_list **a, t_list **b);

//	Sorting algorithms

void	bublesort(t_list **a_head);
void	insertion_sort(t_list **a_head, t_list **b_head);
void	selectionsort(t_list **a_head, t_list **b_head);
void	selection_n_sort(t_list **a_head, t_list **b_head, int len);

// Medium

void	chunksort(t_list  **a_head, t_list **b_head);

//	Utilities

void	test_print(t_list *a_head, t_list *b_head);
void	printnode(t_list *list);
int		get_max_value(t_list *list);
int		get_min_value(t_list *list);
#endif
