/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:55:05 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 16:38:13 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_list *a_head, t_list *target)
{
	int	i;

	i = 0;
	while (a_head != NULL)
	{
		if (a_head == target)
			return (i);
		i++;
		a_head = a_head->next;
	}
	return (-1);
}

void	move_a_to_top(t_list **a_head, t_list *cheapest_a, int a_size,
		t_op_count *ops)
{
	int	index;

	index = get_index(*a_head, cheapest_a);
	if (index <= (a_size / 2))
	{
		while (*a_head != cheapest_a)
			ra(a_head, ops);
	}
	else
	{
		while (*a_head != cheapest_a)
			rra(a_head, ops);
	}
}

void	move_b_to_top(t_list **b_head, t_list *cheapest_b, int b_size,
		t_op_count *ops)
{
	int	index;

	index = get_index(*b_head, cheapest_b);
	if (index <= (b_size / 2))
	{
		while (*b_head != cheapest_b)
			rb(b_head, ops);
	}
	else
	{
		while (*b_head != cheapest_b)
			rrb(b_head, ops);
	}
}

void	turk_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int		*arr;
	int		i;
	int		j;
	int		tmp;
	int		count;
	int		chunk;
	int		size;
	t_list	*target_node;

	size = ft_lstsize(*a_head);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;	
	target_node = *a_head;
	i = 0;
	while (i < size)
	{
		arr[i] = get_int(target_node);
		target_node = target_node->next;
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
			j++;
		}
		i++;
	}
	if (size <= 100)
		chunk = calc_chunk_size(size);
	else
		chunk = calc_chunk_size(size);
	count = 0;
	while (*a_head)
	{
		if (get_int(*a_head) <= arr[count])
		{
			pb(b_head, a_head, ops);
			rb(b_head, ops);
			count++;
		}
		else if (get_int(*a_head) <= arr[count + chunk])
		{
			pb(b_head, a_head, ops);
			count++;
		}
		else
			ra(a_head, ops);
		if (count + chunk >= size)
			chunk = size - count - 1;
	}
	while (*b_head)
	{
		target_node = get_max_node(*b_head);
		move_b_to_top(b_head, target_node, ft_lstsize(*b_head), ops);
		pa(a_head, b_head, ops);
	}
	free(arr);
}
