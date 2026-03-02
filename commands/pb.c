/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 13:35:45 by ksener            #+#    #+#             */
/*   Updated: 2026/03/02 14:42:22 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pb(t_list **b, t_list **a)
{
	t_list	*temp;

	if (!b || !a)
		return ;
	temp = (*a)->next;
	ft_lstadd_front(b, *a);
	*a = temp;
	printf("\npb");
}
