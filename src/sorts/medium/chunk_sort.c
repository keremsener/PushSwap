/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:13:30 by ksener            #+#    #+#             */
/*   Updated: 2026/03/09 03:37:41 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calc_chunk_size(int total_numbers)
{
	if (total_numbers <= 10)
		return(total_numbers);
	else if (total_numbers <= 150)
		return (total_numbers / 5);
	else
		return (total_numbers / 11);	
}

void	chunk_sort(t_list  **a_head, t_list **b_head)
{
	int	chunk_size;

	if (!a_head || !(*a_head))
		return ;
	chunk_size = calc_chunk_size(ft_lstsize(*a_head));
	if(chunk_size <= 10)
	{
		selection_sort(a_head, b_head);
		return ;
	}
	while (chunk_size != 0)
	{
		pb(b_head, a_head);
		chunk_size--;
	}
	t_list	*temp = NULL;
	selection_sort(b_head, &temp);
	//buble_sort(b_head);
}
