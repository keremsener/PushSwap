/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 17:34:44 by adede             #+#    #+#             */
/*   Updated: 2026/03/12 16:00:53 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	print_disorder(double disorder)
{
	ft_putstr_fd("[bench] disorder:  ", 2);
	ft_putnbr_fd((int)disorder, 2);
	ft_putchar_fd('.', 2);
	ft_putnbr_fd((int)(disorder * 100) % 100, 2);
	ft_putendl_fd("%", 2);
}

static void	print_strategy(t_strategy strategy, double disorder)
{
	const char	*names[4] = {
		"Adaptive",
		"Simple",
		"Medium",
		"Complex"
	};
	const char	*complexity[3] = {
		"O(n^2)",
		"O(n√n)",
		"O(n log n)"
	};

	ft_putstr_fd("[bench] strategy:  ", 2);
	ft_putstr_fd((char *)names[strategy], 2);
	ft_putstr_fd(" / ", 2);
	if (strategy == ADAPTIVE)
	{
		if (disorder < 20)
			strategy = SIMPLE;
		else if (disorder < 50)
			strategy = MEDIUM;
		else
			strategy = COMPLEX;
	}
	ft_putendl_fd((char *)complexity[strategy - 1], 2);
}

static void	print_total(t_op_count ops)
{
	int	total;

	total = 0;
	total += ops.sa;
	total += ops.sb;
	total += ops.ss;
	total += ops.pa;
	total += ops.pb;
	total += ops.ra;
	total += ops.rb;
	total += ops.rr;
	total += ops.rra;
	total += ops.rrb;
	total += ops.rrr;
	ft_putstr_fd("[bench] total_ops:  ", 2);
	ft_putnbr_fd(total, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_ops(t_op_count ops)
{
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("sa:  ", 2);
	ft_putnbr_fd(ops.sa, 2);
	ft_putstr_fd("  sb:  ", 2);
	ft_putnbr_fd(ops.sb, 2);
	ft_putstr_fd("  pa:  ", 2);
	ft_putnbr_fd(ops.pa, 2);
	ft_putstr_fd("  pb:  ", 2);
	ft_putnbr_fd(ops.pb, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] ", 2);
	ft_putstr_fd("ra:  ", 2);
	ft_putnbr_fd(ops.ra, 2);
	ft_putstr_fd("  rb:  ", 2);
	ft_putnbr_fd(ops.rb, 2);
	ft_putstr_fd("  rr:  ", 2);
	ft_putnbr_fd(ops.rr, 2);
	ft_putstr_fd("  rra:  ", 2);
	ft_putnbr_fd(ops.rra, 2);
	ft_putstr_fd("  rrb:  ", 2);
	ft_putnbr_fd(ops.rrb, 2);
	ft_putstr_fd("  rrr:  ", 2);
	ft_putnbr_fd(ops.rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_metrics metrics)
{
	print_disorder(metrics.disorder);
	print_strategy(metrics.config.strategy, metrics.disorder);
	print_total(metrics.ops);
	print_ops(metrics.ops);
}
