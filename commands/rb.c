/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 20:11:56 by ksener            #+#    #+#             */
/*   Updated: 2026/02/24 13:58:34 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

void	rb(t_list **b)
{
	t_list	*temp;

	if (!b || !(*b))
		return ;
	temp = *b;
	ft_lstadd_back(b, temp);
	*b = (*b)->next;
	temp->next = NULL;
}
