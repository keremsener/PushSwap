/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/06 15:38:07 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"

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
