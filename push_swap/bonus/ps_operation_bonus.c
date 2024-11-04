/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:19:54 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 13:40:46 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	sa(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (stacks->a_size == 0 || stacks->a_size == 1)
		return ;
	tmp1 = pop_top(stacks->stack_a);
	tmp2 = pop_top(stacks->stack_a);
	push_top(stacks->stack_a, tmp1);
	push_top(stacks->stack_a, tmp2);
}

void	sb(t_var *stacks)
{
	t_node	*tmp1;
	t_node	*tmp2;

	if (stacks->b_size == 0 || stacks->b_size == 1)
		return ;
	tmp1 = pop_top(stacks->stack_b);
	tmp2 = pop_top(stacks->stack_b);
	push_top(stacks->stack_b, tmp1);
	push_top(stacks->stack_b, tmp2);
}

void	ss(t_var *stacks)
{
	sa(stacks);
	sb(stacks);
}

void	pa(t_var *stacks)
{
	if (stacks->stack_b->top->right->val)
	{
		push_top(stacks->stack_a, pop_top(stacks->stack_b));
		stacks->a_size++;
		stacks->b_size--;
	}
}

void	pb(t_var *stacks)
{
	if (stacks->stack_a->top->right->val)
	{
		push_top(stacks->stack_b, pop_top(stacks->stack_a));
		stacks->a_size--;
		stacks->b_size++;
	}
}
