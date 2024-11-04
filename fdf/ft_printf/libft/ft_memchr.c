/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:38:34 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 13:08:21 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ss;

	ss = (const unsigned char *)s;
	while (n--)
	{
		if (*ss == (unsigned char)c)
			return ((void *)ss);
		ss++;
	}
	return (NULL);
}
