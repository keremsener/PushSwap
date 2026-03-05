/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 21:29:06 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 11:11:48 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrb(t_list **b)
{
	t_list	*temp;
	t_list	*temp2;

	if (!b || !(*b) || !(*b)->next)
		return ;
	temp = *b;
	while (temp->next->next != NULL)
	{
		temp = temp->next;
	}
	temp2 = temp->next;
	temp->next = NULL;
	ft_lstadd_front(b, temp2);
	ft_printf("\nrrb");
}
