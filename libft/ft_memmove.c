/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adede <adede@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 09:30:59 by adede             #+#    #+#             */
/*   Updated: 2026/01/29 17:33:59 by adede            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_casted;
	unsigned char	*src_casted;

	dest_casted = (unsigned char *)dest;
	src_casted = (unsigned char *)src;
	if (dest_casted > src_casted)
	{
		while (n--)
			dest_casted[n] = src_casted[n];
	}
	else if (dest_casted < src_casted)
		ft_memcpy(dest, src, n);
	return (dest);
}
