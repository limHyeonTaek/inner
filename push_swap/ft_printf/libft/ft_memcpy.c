/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 10:51:23 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:42:47 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void		*d;

	if (!dest && !src)
		return (NULL);
	d = dest;
	while (n--)
		*(unsigned char *)dest++ = *(const unsigned char *)src++;
	return (d);
}
