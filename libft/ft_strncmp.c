/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:09:29 by adede             #+#    #+#             */
/*   Updated: 2026/01/13 09:46:16 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;
	size_t				c;

	p1 = (const unsigned char *)s1;
	p2 = (const unsigned char *)s2;
	c = 0;
	while (n > 0 && (p1[c] || p2[c]))
	{
		if (p1[c] != p2[c])
			return (p1[c] - p2[c]);
		c++;
		n--;
	}
	return (0);
}
