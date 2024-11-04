/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 14:54:24 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:30:22 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	littlen;

	if (!*little || !little)
		return ((char *)big);
	littlen = ft_strlen(little);
	while (*big && len-- >= littlen)
	{
		if (*big == *little && !ft_memcmp(big, little, littlen))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
