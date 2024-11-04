/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:56:58 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:42:54 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	void	*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	if (d < src)
		ft_memcpy(dest, src, n);
	else
	{
		d += n;
		src += n;
		while (n--)
			*(unsigned char *)(--d) = *(const unsigned char *)(--src);
	}
	return (dest);
}
