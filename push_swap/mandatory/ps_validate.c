/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:40:41 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 13:43:58 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	overlap_checker(t_var *stacks, int check, char **tmp,
		t_node *new_node)
{
	int	*new_tmp;
	int	idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		if (stacks->list[idx] == check)
		{
			free(new_node);
			ps_error(stacks, tmp);
		}
		idx++;
	}
	stacks->list_size++;
	new_tmp = (int *)malloc(sizeof(int) * stacks->list_size);
	if (!new_tmp)
		ps_error(stacks, tmp);
	if (stacks->list_size == 1)
		new_tmp[0] = check;
	idx = -1;
	while (++idx < stacks->list_size - 1)
		new_tmp[idx] = stacks->list[idx];
	new_tmp[idx] = check;
	free(stacks->list);
	stacks->list = new_tmp;
}

static int	ps_atoi(const char *str)
{
	long long	ret;
	int			sign;

	ret = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '+' || *str == '-')
		str++;
	if (!(*str >= '0' && *str <= '9'))
		ps_error(NULL, NULL);
	while (*str >= '0' && *str <= '9')
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	if (*str)
		ps_error(NULL, NULL);
	if (ret * sign > 2147483647 || ret * sign < -2147483648)
		ps_error(NULL, NULL);
	return (sign * ret);
}

static int	ps_size_check(char const *str, char c)
{
	int	size;
	int	i;

	size = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			size++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (size);
}

static int	ps_valid_atoi(char *str)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (!ft_strchr("+-0123456789", str[idx]))
			return (0);
		idx++;
	}
	return (1);
}

void	validate_args(int ac, char **av, t_var *stacks)
{
	int		idx;
	int		size;
	char	*args;
	char	**tmp;
	t_node	*new_node;

	if (av[1][0] == '\0')
		ps_error(stacks, NULL);
	args = ps_all_join(ac, av);
	size = ps_size_check(args, ' ');
	tmp = ft_split(args, ' ');
	free(args);
	idx = -1;
	while (++idx < size)
	{
		if (!ps_valid_atoi(tmp[idx]))
			ps_error(stacks, tmp);
		new_node = get_new_node(ps_atoi(tmp[idx]));
		overlap_checker(stacks, new_node->val, tmp, new_node);
		free(new_node);
	}
	idx = -1;
	while (++idx < size)
		free(tmp[idx]);
	free(tmp);
}
