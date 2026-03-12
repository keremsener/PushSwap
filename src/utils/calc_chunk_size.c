/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_chunk_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksener <ksener@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 16:34:28 by ksener            #+#    #+#             */
/*   Updated: 2026/03/12 16:35:02 by ksener           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc_chunk_size(int total_numbers)
{
	int	i;

	i = 2;
	while (i < total_numbers)
	{
		if (i * i <= total_numbers && total_numbers < (i + 1) * (i + 1))
			return (i);
		else
			i++;
	}
	return (i);
}
