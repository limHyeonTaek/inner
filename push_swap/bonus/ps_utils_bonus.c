/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:19:57 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 13:34:18 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

char	*ps_all_join(int ac, char **av)
{
	long long	i;
	long long	len;
	char		*str;
	long long	idx;
	long long	j;

	i = 0;
	idx = 0;
	len = 0;
	while (++i < ac)
		len += ft_strlen(av[i]);
	i = 0;
	str = (char *)malloc(sizeof(char) * (len + ac));
	if (!str)
		return (NULL);
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
			str[idx++] = av[i][j++];
		if (i != ac - 1)
			str[idx++] = ' ';
	}
	str[idx] = '\0';
	return (str);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	find_list_max(t_var *stacks)
{
	int	max;
	int	idx;

	max = -2147483648;
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max < stacks->list[idx])
			max = stacks->list[idx];
		idx++;
	}
	idx = 0;
	while (idx < stacks->list_size)
	{
		if (max == stacks->list[idx])
		{
			stacks->list[idx] = -2147483648;
			return (idx);
		}
		idx++;
	}
	return (-1);
}
