/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:30:59 by adede             #+#    #+#             */
/*   Updated: 2026/01/28 09:22:03 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_casted;
	unsigned char	*src_casted;
	size_t			i;

	if (dest == src)
		return (dest);
	dest_casted = (unsigned char *)dest;
	src_casted = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dest_casted[i] = src_casted[i];
		i++;
	}
	return (dest);
}
