/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:47:50 by hylim             #+#    #+#             */
/*   Updated: 2024/11/08 20:35:02 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_split_count(char *s, char c)
{
	int	words_count;

	words_count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s && !(*s == '\t' || *s == '\n'))
			words_count++;
		while (*s && *s != c)
			s++;
	}
	return (words_count);
}

static int	ft_check_base_error(char *str)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (ft_strlen(str) <= 1)
		return (0);
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		c = 1;
		while (str[i + c])
		{
			if (str[i + c] == str[i])
				return (0);
			c++;
		}
		i++;
	}
	return (1);
}

static int	ft_convert_from_base(char *str, char *base)
{
	size_t	i;
	size_t	c;
	int		total;
	int		base_len;

	i = 0;
	total = 0;
	base_len = ft_strlen(base);
	while (str[i] && ft_strchr(base, ft_tolower(str[i])))
	{
		c = 0;
		while (base[c] != ft_tolower(str[i]) && base[c])
			c++;
		total = (total * base_len) + c;
		i++;
	}
	return (total);
}

int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	int		total;
	size_t	i;

	if (!ft_check_base_error(base))
		return (0);
	sign = 1;
	total = 0;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	if (str[i] == '0')
	{
		i++;
		if (str[i] == 'x')
			i++;
	}
	total = ft_convert_from_base(&str[i], base);
	return (total * sign);
}
