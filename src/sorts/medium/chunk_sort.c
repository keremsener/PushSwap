/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:13:30 by ksener            #+#    #+#             */
/*   Updated: 2026/03/17 11:21:58 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_a(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int	size;

	pa(a_head, b_head, ops);
	while (*b_head)
	{
		size = ft_lstsize(*a_head);
		while (size && get_int(*b_head) > get_int(*a_head))
		{
			ra(a_head, ops);
			size--;
		}
		pa(a_head, b_head, ops);
		while (get_int(get_min_node(*a_head)) != get_int(*a_head))
			ra(a_head, ops);
	}
}

static void	sort_chunk(t_list **a_head, t_list **b_head, t_op_count *ops)
{	
	int	i;
	int	j;
	int	chunk_size;

	i = 0;
	chunk_size = calc_chunk_size(ft_lstsize(*a_head));
	while (i < chunk_size + 1 && *a_head)
	{
		pb(b_head, a_head, ops);
		i++;
		j = 0;
		while (j < i - 1 && (*b_head)->next != NULL)
		{
			if (get_int(*b_head) > get_int((*b_head)->next))
				sb(b_head, ops);
			rb(b_head, ops);
			j++;
		}
		while (j--)
			rrb(b_head, ops);
	}
}

void	chunk_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	if (!a_head || !(*a_head))
		return ;
	while (*a_head != NULL)
	{
		sort_chunk(a_head, b_head, ops);
	}
	push_a(a_head, b_head, ops);
}
