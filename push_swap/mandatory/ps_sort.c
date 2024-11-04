/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:25:41 by hylim             #+#    #+#             */
/*   Updated: 2024/10/28 20:26:55 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_args(t_var *stacks)
{
	int	top;
	int	mid;
	int	bot;

	top = stacks->stack_a->top->right->val;
	mid = stacks->stack_a->top->right->right->val;
	bot = stacks->stack_a->top->right->right->right->val;
	if (top > mid && mid > bot && top > bot)
	{
		sa(stacks);
		rra(stacks);
	}
	else if (top > mid && bot > mid && top > bot)
		ra(stacks);
	else if (mid > top && mid > bot && bot > top)
	{
		sa(stacks);
		ra(stacks);
	}
	else if (top > mid && bot > mid && bot > top)
		sa(stacks);
	else if (mid > top && mid > bot && top > bot)
		rra(stacks);
}

void	sort_big_last(t_var *stacks)
{
	int	min_location;

	min_location = find_a_min(stacks);
	while (min_location)
	{
		if (min_location > 0)
		{
			ra(stacks);
			min_location--;
		}
		else
		{
			rra(stacks);
			min_location++;
		}
	}
}

void	check_sort(t_var *stacks)
{
	int	idx;
	int	check;

	idx = stacks->list_size;
	check = 0;
	while (idx > 1)
	{
		if (stacks->list[idx - 1] - stacks->list[idx - 2] > 0)
			check++;
		idx--;
	}
	if (check == stacks->list_size - 1)
	{
		free_stacks(stacks);
		exit(0);
	}
}
