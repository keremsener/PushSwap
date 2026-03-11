/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:52:26 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:37:04 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a, t_op_count *ops)
{
	t_list	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	ft_lstadd_back(a, temp);
	*a = (*a)->next;
	temp->next = NULL;
	ops->ra++;
	ft_printf("ra\n");
}
