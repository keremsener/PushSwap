/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 11:47:20 by ksener            #+#    #+#             */
/*   Updated: 2026/03/17 13:54:02 by adede            ###   ########.fr       */
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
			chunk_sort(a_head, b_head, &metrics->ops);
		else
			ft_printf("complex-adaptive\n");
	}
	if (metrics->config.strategy == SIMPLE)
	{
		// buble_sort(a_head, &metrics->ops); // 100: 12625, 500: 313343
		// insertion_sort(a_head, b_head, &metrics->ops); // 100: 5176, 500: 125829
		selection_sort(a_head, b_head, &metrics->ops); // 100: 2635, 500: 63366
	}
	if (metrics->config.strategy == MEDIUM)
	{
		// chunk_sort(a_head, b_head, &metrics->ops);
		turk_sort(a_head, b_head, &metrics->ops);
	}
	if (metrics->config.strategy == COMPLEX)
	{
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
	sort(&a_head, &b_head, &metrics);
	if (metrics.config.bench_mode)
		print_bench(metrics);
	ft_lstclear(&a_head, free);
	return (0);
}
