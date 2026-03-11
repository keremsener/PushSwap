/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:26:54 by ksener            #+#    #+#             */
/*   Updated: 2026/03/11 15:38:03 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a, t_op_count *ops)
{
	t_list	*temp;
	t_list	*temp2;

	if (!a || !(*a) || !(*a)->next)
		return ;
	temp = *a;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(a, temp2);
	ops->rra++;
	ft_printf("rra\n");
}
