/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 20:04:51 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 15:07:11 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_error(t_var *stacks, char **tmp)
{
	int	i;

	i = 0;
	write(2, "Error\n", 6);
	if (tmp)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
	if (stacks)
		free_stacks(stacks);
	exit(1);
}

void	free_stacks(t_var *stacks)
{
	t_node	*current;
	t_node	*next;

	current = stacks->stack_a->top;
	while (current)
	{
		next = current->right;
		free(current);
		current = next;
	}
	free(stacks->stack_a);
	current = stacks->stack_b->top;
	while (current)
	{
		next = current->right;
		free(current);
		current = next;
	}
	free(stacks->stack_b);
	if (stacks->list)
		free(stacks->list);
}

static int	find_int_min(t_var *stacks)
{
	int	idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		if (stacks->list[idx] == -2147483648)
			return (idx);
		idx++;
	}
	return (-1);
}

void	indexing(t_var *stacks)
{
	int	*idx_list;
	int	idx;
	int	max_idx;
	int	min_idx;
	int	start_idx;

	idx_list = (int *)malloc(sizeof(int) * stacks->list_size);
	if (!idx_list)
		ps_error(stacks, NULL);
	min_idx = find_int_min(stacks);
	if (min_idx != -1)
		idx_list[min_idx] = 0;
	idx = stacks->list_size - 1;
	if (min_idx != -1)
		start_idx = 1;
	else
		start_idx = 0;
	while (idx >= start_idx)
	{
		max_idx = find_list_max(stacks);
		idx_list[max_idx] = idx;
		idx--;
	}
	free(stacks->list);
	stacks->list = idx_list;
}
