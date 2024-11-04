/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 20:26:09 by hylim             #+#    #+#             */
/*   Updated: 2024/10/29 17:40:20 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	gnl_strlen(char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*gnl_strchr(char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*gnl_strjoin(char *s1, char *s2)
{
	char	*start;
	char	*join;
	char	*ss1;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	join = malloc(sizeof(char) * ((gnl_strlen(s1) + gnl_strlen(s2)) + 1));
	if (join == NULL)
		return (NULL);
	start = join;
	ss1 = s1;
	while (*ss1)
		*join++ = *ss1++;
	while (*s2)
		*join++ = *s2++;
	*join = '\0';
	return (free(s1), start);
}

char	*ft_dup_upto_nl(char *s)
{
	int		i;
	char	*d;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	d = (char *)malloc(sizeof(char) * (i + 2));
	if (!d)
		return (NULL);
	i = 0;
	while (*s && *s != '\n')
		d[i++] = *s++;
	if (*s == '\n')
		d[i++] = *s++;
	d[i] = '\0';
	return (d);
}

char	*ft_dup_after_nl(char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
		return (free(s), NULL);
	d = (char *)malloc(sizeof(char) * (gnl_strlen(s) - i + 1));
	if (!d)
		return (free(s), NULL);
	i++;
	j = 0;
	while (s[i])
		d[j++] = s[i++];
	d[j] = '\0';
	return (free(s), d);
}
