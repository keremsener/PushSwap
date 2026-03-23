/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:50:02 by adede             #+#    #+#             */
/*   Updated: 2026/03/23 12:52:54 by adede            ###   ########.fr       */
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

int	calc_chunk_size(int total_numbers)
{
	int	i;

	i = 2;
	while (i < total_numbers)
	{
		if (i * i <= total_numbers && total_numbers < (i + 1) * (i + 1))
			return (i);
		else
			i++;
	}
	return (i);
}
