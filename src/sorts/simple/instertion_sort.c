/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instertion_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 00:53:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/24 15:31:40 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	for_while(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int	max;
	int	size;
	int	pushed;

	while (*a_head)
	{
		max = get_int(get_max_node(*b_head));
		while (get_int(*b_head) != max)
			rb(b_head, ops);
		size = ft_lstsize(*b_head);
		pushed = 0;
		while (size--)
		{
			if (get_int(*a_head) > get_int(*b_head))
			{
				pb(b_head, a_head, ops);
				pushed = 1;
				break ;
			}
			rb(b_head, ops);
		}
		if (!pushed)
			pb(b_head, a_head, ops);
	}
}

void	insertion_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int	b_size;
	int	max_val;

	b_size = 0;
	max_val = 0;
	if (!a_head || !*a_head || !(*a_head)->next)
		return ;
	if (get_int(*a_head) > get_int((*a_head)->next))
		sa(a_head, ops);
	pb(b_head, a_head, ops);
	for_while(a_head, b_head, ops);
	if (*b_head)
	{
		max_val = get_int(get_max_node(*b_head));
		while (max_val != get_int(*b_head))
			rb(b_head, ops);
	}
	while (*b_head)
		pa(a_head, b_head, ops);
}
