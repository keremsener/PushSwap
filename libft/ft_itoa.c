/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 10:54:40 by adede             #+#    #+#             */
/*   Updated: 2026/01/19 08:53:49 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_intlen(int n)
{
	size_t	length;

	length = 0;
	if (n <= 0)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char	*s;
	long	number;
	size_t	length;

	number = n;
	length = ft_intlen(n);
	s = ft_calloc(length + 1, sizeof(char));
	if (!s)
		return (NULL);
	if (number == 0)
		s[0] = '0';
	if (number < 0)
	{
		s[0] = '-';
		number *= -1;
	}
	while (number > 0)
	{
		s[--length] = (number % 10) + '0';
		number /= 10;
	}
	return (s);
}
