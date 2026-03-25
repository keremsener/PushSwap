/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 12:50:02 by adede             #+#    #+#             */
/*   Updated: 2026/03/25 11:18:30 by ksener           ###   ########.fr       */
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

void	three(t_list **a_head, t_list **b_head, t_metrics *metrics)
{
	while (get_int(get_min_node(*a_head)) != get_int(*a_head))
		ra(a_head, &metrics->ops);
	pb(b_head, a_head, &metrics->ops);
	if (get_int(*a_head) != get_int(get_min_node(*a_head)))
		sa(a_head, &metrics->ops);
	pa(a_head, b_head, &metrics->ops);
}

void	five(t_list **a_head, t_list **b_head, t_metrics *metrics)
{
	int	i;
	int	size;
	int	index;

	i = 0;
	while (i < 2)
	{
		size = ft_lstsize(*a_head);
		index = get_index(*a_head, get_min_node(*a_head));
		if (index <= (size - index))
		{
			while (get_int(*a_head) != get_int(get_min_node(*a_head)))
				ra(a_head, &metrics->ops);
		}
		else
		{
			while (get_int(*a_head) != get_int(get_min_node(*a_head)))
				rra(a_head, &metrics->ops);
		}
		pb(b_head, a_head, &metrics->ops);
		i++;
	}
	three(a_head, b_head, metrics);
	pa(a_head, b_head, &metrics->ops);
	pa(a_head, b_head, &metrics->ops);
}
