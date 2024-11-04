/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 15:41:09 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:11:55 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dest, const char *src)
{
	char	*d;

	if (!dest || !src)
		return (NULL);
	d = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (d);
}
