/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:11:56 by ksener            #+#    #+#             */
/*   Updated: 2026/03/05 11:11:20 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb(t_list **b)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	ft_lstadd_back(b, temp);
	*b = (*b)->next;
	temp->next = NULL;
	ft_printf("\nrb");
}
