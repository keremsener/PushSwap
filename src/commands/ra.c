/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 19:52:26 by ksener            #+#    #+#             */
/*   Updated: 2026/03/07 21:19:24 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a)
{
	t_list	*temp;

	if (!a || !(*a))
		return ;
	temp = *a;
	ft_lstadd_back(a, temp);
	*a = (*a)->next;
	temp->next = NULL;
	ft_printf("ra\n");
}
