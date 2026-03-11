/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instertion_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:53:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:45:30 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	forwhile(t_list **a_head, t_list **b_head, int b_size, int max_val, t_op_count *ops)
{
	while (*a_head)
	{
		max_val = get_max_value(*b_head);
		while (max_val != get_int(b_head))
		{
			rb(b_head, ops);
		}
		b_size = ft_lstsize(*b_head);
		while (*b_head)
		{
			if ((get_int(a_head) > get_int(b_head))
				|| b_size <= 0)
			{
				pb(b_head, a_head, ops);
				break ;
			}
			else
			{
				rb(b_head, ops);
				b_size--;
			}
		}
	}
}

void	insertion_sort(t_list **a_head, t_list **b_head)
{
	t_op_count	ops;
	int	b_size;
	int	max_val;

	ft_bzero(&ops, sizeof(t_op_count));
	b_size = 0;
	max_val = 0;
	if (!a_head || !*a_head || !(*a_head)->next)
		return ;
	if (get_int(a_head) > *(int *)(*a_head)->next->content)
		sa(a_head, &ops);
	pb(b_head, a_head, &ops);
	forwhile(a_head, b_head, b_size, max_val, &ops);
	max_val = get_max_value(*b_head);
	while (max_val != get_int(b_head))
	{
		rb(b_head, &ops);
	}
	while (*b_head)
		pa(a_head, b_head, &ops);
}
