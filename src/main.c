/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/23 11:51:07 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort(t_list **a_head, t_list **b_head, t_metrics *metrics)
{
	if (metrics->config.strategy == ADAPTIVE)
	{
		if (metrics->disorder < 20)
			selection_sort(a_head, b_head, &metrics->ops);
		else if (metrics->disorder < 50)
			turk_sort(a_head, b_head, &metrics->ops);
		else
			up_turk_sort(a_head, b_head, &metrics->ops);
	}
	if (metrics->config.strategy == SIMPLE)
		selection_sort(a_head, b_head, &metrics->ops);
	if (metrics->config.strategy == MEDIUM)
		turk_sort(a_head, b_head, &metrics->ops);
	if (metrics->config.strategy == COMPLEX)
		up_turk_sort(a_head, b_head, &metrics->ops);
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
	sort(&a_head, &b_head, &metrics);
	if (metrics.config.bench_mode)
		print_bench(metrics);
	// print_stack(a_head, b_head);
	ft_lstclear(&a_head, free);
	return (0);
}
