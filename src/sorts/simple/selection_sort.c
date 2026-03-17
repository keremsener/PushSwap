/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 11:27:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/17 11:22:44 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	selection_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int	min_val;

	min_val = 0;
	if (!a_head || !(*a_head))
		return ;
	while ((*a_head) != NULL)
	{
		min_val = get_int(get_min_node(*a_head));
		if (get_int(*a_head) == min_val)
			pb(b_head, a_head, ops);
		else
			ra(a_head, ops);	
	}
	while (*b_head)
		pa(a_head, b_head, ops);
}
