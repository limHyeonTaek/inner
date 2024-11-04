/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:39:27 by hylim             #+#    #+#             */
/*   Updated: 2024/10/08 17:21:49 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	count_words(const char *s, char c)
{
	int	words_count;

	words_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			words_count++;
		while (*s && *s != c)
			s++;
	}
	return (words_count);
}

static	char	*get_next_word(const char **s, char c)
{
	const char	*start;
	size_t		i;
	size_t		len;
	char		*word;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = *s - start;
	word = (char *)malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = start[i];
		i++;
	}
	word[len] = '\0';
	return (word);
}

static	void	*ft_free(char **result, int i)
{
	while (i-- > 0)
		free(result[i]);
	free(result);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words_count;
	int		i;

	if (!s)
		return (NULL);
	words_count = count_words(s, c);
	result = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!result)
		return (NULL);
	result[words_count] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = get_next_word(&s, c);
			if (!result[i])
				return (ft_free(result, i));
			i++;
		}
	}
	return (result);
}
