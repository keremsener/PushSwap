/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:55:05 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 17:50:15 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_a_head(t_list **a_head, t_list **b_head, int *arr,
		t_op_count *ops)
{
	int	size;
	int	count;
	int	chunk;

	size = ft_lstsize(*a_head);
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
}

static void	helpper(int size, int *arr)
{
	int	i;
	int	j;
	int	tmp;

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
}

static void	arr_sort(int *arr, int size, t_list *target_node)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = get_int(target_node);
		target_node = target_node->next;
		i++;
	}
	helpper(size, arr);
}

void	turk_sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
	int		*arr;
	int		size;
	t_list	*target_node;

	size = ft_lstsize(*a_head);
	arr = malloc(sizeof(int) * size);
	if (!arr)
		return ;
	target_node = *a_head;
	arr_sort(arr, size, target_node);
	ft_a_head(a_head, b_head, arr, ops);
	while (*b_head)
	{
		target_node = get_max_node(*b_head);
		move_b_to_top(b_head, target_node, ft_lstsize(*b_head), ops);
		pa(a_head, b_head, ops);
	}
	free(arr);
}
