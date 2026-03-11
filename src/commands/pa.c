/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:44:18 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:35:36 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a, t_list **b, t_op_count *ops)
{
	t_list	*temp;

	if (!b || !a)
		return ;
	temp = (*b)->next;
	ft_lstadd_front(a, *b);
	*b = temp;
	ops->pa++;
	ft_printf("pa\n");
}
