/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:13:30 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 16:22:53 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int calc_chunk_size(int total_numbers)
{
    if (total_numbers <= 150)
        return (5);
    else
        return (11);
}

void chunk_sort(t_list **a_head, t_list **b_head)
{
	int chunk_size;
	int min_val;
	int max_val;
	int gap;
	int limit;
	int size;

	if (!a_head || !(*a_head))
		return;
	min_val = get_min_value(*a_head);
	max_val = get_max_value(*a_head);
	size = ft_lstsize(*a_head);
	if (size <= 10)
	{
    	selection_sort(a_head, b_head);
    	return ;
	}
	chunk_size = calc_chunk_size(size);
	gap = (max_val - min_val) / chunk_size;
	limit = min_val + gap;
	while (*a_head != NULL)
	{
		size = ft_lstsize(*a_head);
		while (size > 0)
		{
			if (*(int *)(*a_head)->content <= limit)
				pb(b_head, a_head);
			else
				ra(a_head);
			size--;
		}
		limit += gap;
	}
	while (*b_head != NULL)
	{
		max_val = get_max_value(*b_head);
		if (*(int *)(*b_head)->content == max_val)
			pa(a_head, b_head);
		else
			rb(b_head);
	}	
}
