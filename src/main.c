/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/25 11:32:11 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **a_head, t_list **b_head, t_metrics *metrics, int size)
{
	if (size == 2)
		sa(a_head, &metrics->ops);
	else if (size == 3)
		three(a_head, b_head, metrics);
	else if (size == 4 || size == 5)
		five(a_head, b_head, metrics);
	else
	{
		if (metrics->config.strategy == ADAPTIVE)
		{
			if (metrics->disorder < 0.2)
				selection_sort(a_head, b_head, &metrics->ops);
			else if (metrics->disorder < 0.5)
				turk_sort(a_head, b_head, &metrics->ops);
			else
				up_turk_sort(a_head, b_head, &metrics->ops);
		}
		else if (metrics->config.strategy == SIMPLE)
			selection_sort(a_head, b_head, &metrics->ops);
		else if (metrics->config.strategy == MEDIUM)
			turk_sort(a_head, b_head, &metrics->ops);
		else if (metrics->config.strategy == COMPLEX)
			up_turk_sort(a_head, b_head, &metrics->ops);
	}
}

int	main(int argc, const char *argv[])
{
	t_list		*a_head;
	t_list		*b_head;
	t_metrics	metrics;

	if (argc < 2)
		return (0);
	ft_bzero(&metrics, sizeof(t_metrics));
	a_head = parse(argc, argv, &metrics.config);
	b_head = NULL;
	metrics.disorder = compute_disorder(a_head);
	if (metrics.disorder == 0)
		return (0);
	sort(&a_head, &b_head, &metrics, ft_lstsize(a_head));
	if (metrics.config.bench_mode)
		print_bench(metrics);
	ft_lstclear(&a_head, free);
	return (0);
}
