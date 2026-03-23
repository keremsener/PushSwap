/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:18:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 15:30:51 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void execute_command(t_list **a_head, t_list **b_head, char *gnl, t_op_count *ops)
{
	if (ft_strncmp(gnl, "sa\n", 3) == 0)
		sa(a_head, ops);
	else if (ft_strncmp(gnl, "sb\n", 3) == 0)
		sb(b_head, ops);
	else if (ft_strncmp(gnl, "ss\n", 3) == 0)
		ss(a_head, b_head, ops);
	else if (ft_strncmp(gnl, "ra\n", 3) == 0)
		ra(a_head, ops);
	else if (ft_strncmp(gnl, "rb\n", 3) == 0)
		rb(b_head, ops);
	else if (ft_strncmp(gnl, "rr\n", 3) == 0)
		rr(a_head, b_head, ops);
	else if (ft_strncmp(gnl, "rra\n", 4) == 0)
		rra(a_head, ops);
	else if (ft_strncmp(gnl, "rrb\n", 4) == 0)
		rrb(b_head, ops);
	else if (ft_strncmp(gnl, "rrr\n", 4) == 0)
		rrr(a_head, b_head, ops);
	else if (ft_strncmp(gnl, "pa\n", 3) == 0)
		pa(a_head, b_head, ops);
	else if (ft_strncmp(gnl, "pb\n", 3) == 0)
		pb(b_head, a_head, ops);
	else
		error();
}

static void	sort(t_list **a_head, t_list **b_head, t_op_count *ops)
{
    char    *gnl;
    gnl = get_next_line(0);
    while (gnl != NULL)
    {
		execute_command(a_head, b_head, gnl, ops);
		print_stack(*a_head, *b_head);
		free(gnl);
        gnl = get_next_line(0);
    }
    
}

int	main(int argc, const char *argv[])
{
	t_list		*a_head;
	t_list		*b_head;
	t_metrics	metrics;
	int			a_size;

	if (argc < 2)
		return (0);
	ft_bzero(&metrics, sizeof(t_metrics));
	a_head = parse(argc, argv, &metrics.config);
	b_head = NULL;
	a_size = ft_lstsize(a_head);
	sort(&a_head, &b_head, &metrics.ops);
	if (checker(&a_head, &b_head, &metrics.ops, a_size) == 1)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&a_head, free);
	return (0);
}
