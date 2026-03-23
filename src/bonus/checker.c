/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:12:55 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 15:32:31 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	checker(t_list **a_head, t_list **b_head, t_op_count *ops, int size)
{
	if (!a_head || !(*a_head))
		return (-1);
	if(ft_lstsize(*a_head) != size)
		return (-1);
	while (*a_head)
	{
		if (get_int(*a_head) == get_int(get_min_node(*a_head)))
			pb(b_head, a_head, ops);
		else
			return (-1);
	}
	return (1);
}
