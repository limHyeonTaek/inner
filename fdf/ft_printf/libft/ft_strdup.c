/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:37:58 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:43:27 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	size_t	slen;

	slen = ft_strlen(s);
	result = (char *)malloc(slen + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s);
	return (result);
}
