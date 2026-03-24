/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:12:55 by ksener            #+#    #+#             */
/*   Updated: 2026/03/24 09:38:30 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	checker(t_list **a_head, t_list **b_head, int size)
{
	if (!a_head || !(*a_head))
		return (false);
	if (ft_lstsize(*a_head) != size)
		return (false);
	while (*a_head)
	{
		if (get_int(*a_head) == get_int(get_min_node(*a_head)))
			push(a_head, b_head);
		else
			return (false);
	}
	return (true);
}
