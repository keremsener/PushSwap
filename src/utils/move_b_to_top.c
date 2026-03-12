/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_b_to_top.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 17:47:46 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 17:49:20 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_index(t_list *a_head, t_list *target)
{
	int	i;

	i = 0;
	while (a_head != NULL)
	{
		if (a_head == target)
			return (i);
		i++;
		a_head = a_head->next;
	}
	return (-1);
}

void	move_b_to_top(t_list **b_head, t_list *cheapest_b, int b_size,
		t_op_count *ops)
{
	int	index;

	index = get_index(*b_head, cheapest_b);
	if (index <= (b_size / 2))
	{
		while (*b_head != cheapest_b)
			rb(b_head, ops);
	}
	else
	{
		while (*b_head != cheapest_b)
			rrb(b_head, ops);
	}
}
