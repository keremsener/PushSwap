/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/23 10:18:57 by ksener            #+#    #+#             */
/*   Updated: 2026/03/24 09:36:49 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line_bonus.h"

static void	execute_command(t_list **a_head, t_list **b_head, char *line)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap(a_head);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap(b_head);
	else if (!ft_strncmp(line, "ss\n", 3))
		(swap(a_head), swap(b_head));
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate(a_head);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate(b_head);
	else if (!ft_strncmp(line, "rr\n", 3))
		(rotate(a_head), rotate(b_head));
	else if (!ft_strncmp(line, "rra\n", 4))
		rotate_reverse(a_head);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rotate_reverse(b_head);
	else if (!ft_strncmp(line, "rrr\n", 4))
		(rotate_reverse(a_head), rotate_reverse(b_head));
	else if (!ft_strncmp(line, "pa\n", 3))
		push(b_head, a_head);
	else if (!ft_strncmp(line, "pb\n", 3))
		push(a_head, b_head);
	else
		error();
}

static void	sort(t_list **a_head, t_list **b_head)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		execute_command(a_head, b_head, line);
		free(line);
		line = get_next_line(0);
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
	sort(&a_head, &b_head);
	if (checker(&a_head, &b_head, a_size))
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&a_head, free);
	return (0);
}
