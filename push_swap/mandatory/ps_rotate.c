/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:51:41 by hylim             #+#    #+#             */
/*   Updated: 2024/10/28 20:33:19 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_var *stacks, int a)
{
	while (a)
	{
		if (a > 0)
		{
			ra(stacks);
			a--;
		}
		else
		{
			rra(stacks);
			a++;
		}
	}
}

void	rotate_b(t_var *stacks, int b)
{
	while (b)
	{
		if (b > 0)
		{
			rb(stacks);
			b--;
		}
		else
		{
			rrb(stacks);
			b++;
		}
	}
}

void	rotate_same(t_var *stacks, int *a, int *b)
{
	while (*a && *b && (*a > 0 && *b > 0))
	{
		rr(stacks);
		(*a)--;
		(*b)--;
	}
	while (*a && *b && (*a < 0 && *b < 0))
	{
		rrr(stacks);
		(*a)++;
		(*b)++;
	}
}

void	sort_args(t_var *stacks)
{
	int	a;
	int	b;

	divide_pivot(stacks);
	while (stacks->a_size > 3)
		pb(stacks);
	if (stacks->a_size == 2)
	{
		if (stacks->stack_a->top->right->val
			> stacks->stack_a->top->right->right->val)
			sa(stacks);
	}
	if (stacks->a_size == 3)
		sort_three_args(stacks);
	while (stacks->b_size)
	{
		a = 0;
		b = 0;
		get_min_rotate(stacks, &a, &b);
		rotate_same(stacks, &a, &b);
		rotate_a(stacks, a);
		rotate_b(stacks, b);
		pa(stacks);
	}
	sort_big_last(stacks);
}

void	get_min_rotate(t_var *stacks, int *a, int *b)
{
	int			a_location;
	int			b_location;
	int			idx;
	t_node		*b_node;
	int			num;

	idx = 0;
	b_node = stacks->stack_b->top->right;
	while (idx < stacks->b_size)
	{
		num = b_node->val;
		a_location = find_a_location(num, stacks);
		if (idx >= (stacks->b_size + 1) / 2)
			b_location = (stacks->b_size - idx) * -1;
		else
			b_location = idx;
		if (idx == 0 || get_bigger(*a, *b, a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		b_node = b_node->right;
		idx++;
	}
}
