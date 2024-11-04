/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 13:40:18 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:41:12 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	j = 0;
	while (dst[dlen] && dlen < size)
		dlen++;
	slen = ft_strlen(src);
	if (size == 0)
		return (dlen + slen);
	if (size <= dlen)
		return (size + slen);
	while (src[j] && (dlen + j < size - 1))
	{	
		dst[dlen + j] = src[j];
		j++;
	}
	dst[dlen + j] = '\0';
	return (dlen + slen);
}
