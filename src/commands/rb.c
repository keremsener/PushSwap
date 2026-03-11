/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:11:56 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:37:19 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b, t_op_count *ops)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	ft_lstadd_back(b, temp);
	*b = (*b)->next;
	temp->next = NULL;
	ops->rb++;
	ft_printf("rb\n");
}
