/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:35:45 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:36:09 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_list **b, t_list **a, t_op_count *ops)
{
	t_list	*temp;

	if (!b || !a)
		return ;
	temp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = temp;
	ops->pb++;
	ft_printf("pb\n");
}
