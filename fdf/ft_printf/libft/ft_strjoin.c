/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 17:31:09 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 12:13:57 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	onelen;
	size_t	twolen;

	if (!s1 || !s2)
		return (NULL);
	onelen = ft_strlen(s1);
	twolen = ft_strlen(s2);
	join = (char *)malloc(sizeof(char) * (onelen + twolen + 1));
	if (!join)
		return (NULL);
	ft_strcpy(join, s1);
	ft_strcat(join, s2);
	return (join);
}
