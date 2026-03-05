/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:48:24 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 11:02:40 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft.h"
# include <unistd.h>

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
void	controls(char *operation, t_list **a_head, t_list **b_head);
void	bublesort(t_list **a_head);
void	insertion_sort(t_list **a_head, t_list **b_head);
void	test_print(t_list *a_head, t_list *b_head);
void	printnode(t_list *list);
#endif
