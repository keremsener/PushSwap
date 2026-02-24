/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 12:04:03 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 13:58:34 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sb(t_list **b)
{
	t_list	*three;
	t_list	*two;
	if (!b || !(*b) || !(*b)->next)
		return ;
	three = (*b)->next->next;
	(*b)->next->next = (*b);
	two = (*b)->next;
	(*b)->next = three;
	*b = two;	
}