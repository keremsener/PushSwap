/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/06 11:13:30 by ksener            #+#    #+#             */
/*   Updated: 2026/03/06 15:07:15 by ksener           ###   ########.fr       */
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

void	chunksort(t_list  **a_head, t_list **b_head)
{
	int	chunk_size;

	if (!a_head || !(*a_head))
		return ;
	chunk_size = calc_chunk_size(ft_lstsize(*a_head));
	if(chunk_size <= 10)
	{
		selectionsort(a_head, b_head);
		return ;
	}
	while (chunk_size != 0)
	{
		pb(b_head, a_head);
		chunk_size--;
	}
	t_list	*temp = NULL;
	selectionsort(b_head, &temp);
	//bublesort(b_head);
}
