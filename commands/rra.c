/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:26:54 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 13:58:34 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void	rra(t_list **a)
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
}
