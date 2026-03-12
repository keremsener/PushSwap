/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 11:55:05 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 15:27:01 by ksener           ###   ########.fr       */
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

int calc_cost(int index, int size)
{
	if (index <= (size / 2))
		return (index);
	return (size - index);	
}
void	move_a_to_top(t_list **a_head,t_list *cheapest_a, int a_size, t_op_count *ops)
{
	int index;

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
void	move_b_to_top(t_list **b_head,t_list *cheapest_b, int b_size, t_op_count *ops)
{
	int index;

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
	int		a_size;
	int		b_size;
	int 	min_cost;
	int		best_match;
	t_list	*target_node;
	t_list	*tempa;
	t_list	*tempb;
	t_list *cheapest_a;
	t_list *cheapest_target;

	if (ft_lstsize(*a_head) <= 3)
	{
		selection_sort(a_head, b_head, ops);
		return ;
	}
	
	pb(b_head, a_head, ops);
	pb(b_head, a_head, ops);
	tempa = *a_head;
	tempb = *b_head;
	a_size = ft_lstsize(*a_head);
	while (a_size > 3)
	{
		b_size = ft_lstsize(*b_head);
		min_cost = 2147483647;
		while (tempa != NULL)
		{
			best_match = -2147483648;
			target_node = NULL;
			while (tempb != NULL)
			{
				if (get_int(tempa) >= get_int(tempb) && best_match <= get_int(tempb))
				{
					best_match = get_int(tempb);
					target_node = tempb;
				}
				tempb = tempb->next;
			}
			if (target_node == NULL)
				target_node = get_max_node(*b_head);
			if (calc_cost(get_index(*a_head, tempa), a_size) + calc_cost(get_index(*b_head, target_node), b_size) < min_cost)
            {
                min_cost = calc_cost(get_index(*a_head, tempa), a_size) + calc_cost(get_index(*b_head, target_node), b_size);
                cheapest_a = tempa;
                cheapest_target = target_node;
            }
			tempb = *b_head;
			tempa = tempa->next;
		}
		move_a_to_top(a_head, cheapest_a, a_size, ops);
		move_b_to_top(b_head, cheapest_target, b_size, ops);
		pb(b_head, a_head, ops);
		tempa = *a_head;
		a_size--;
	}
	buble_sort(a_head, ops);
	while (*b_head)
	{
		tempa = *a_head;
		best_match = 2147483647;
		target_node = NULL;
		while (tempa)
		{
			if (get_int(tempa) > get_int(*b_head) && get_int(tempa) < best_match)
			{
				best_match = get_int(tempa);
				target_node = tempa;
			}
			tempa = tempa->next;
		}
		if (target_node == NULL)
			target_node = get_min_node(*a_head);
		move_a_to_top(a_head, target_node, ft_lstsize(*a_head), ops);
		pa(a_head, b_head, ops);
	}
	target_node = get_min_node(*a_head);
	move_a_to_top(a_head, target_node, ft_lstsize(*a_head), ops);
}
