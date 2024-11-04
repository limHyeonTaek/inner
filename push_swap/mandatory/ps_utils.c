/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:19:57 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 11:59:55 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	divide_pivot(t_var *stacks)
{
	t_node	*tmp;
	int		times;
	int		p1;
	int		p2;

	p1 = stacks->max_size / 3;
	p2 = (stacks->max_size / 3) * 2;
	times = 0;
	while (times < stacks->max_size)
	{
		tmp = pop_top(stacks->stack_a);
		if (tmp->val < p2)
		{
			push_top(stacks->stack_a, tmp);
			pb(stacks);
			if (tmp->val < p1 && stacks->b_size != 1)
				rb(stacks);
		}
		else
		{
			push_top(stacks->stack_a, tmp);
			ra(stacks);
		}
		times++;
	}
}

int	get_bigger(int a, int b, int a_loc, int b_loc)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a_loc < 0)
		a_loc *= -1;
	if (b_loc < 0)
		b_loc *= -1;
	if (a + b > a_loc + b_loc)
		return (1);
	else
		return (0);
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
