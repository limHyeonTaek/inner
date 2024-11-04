/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:22:36 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 13:32:19 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	stacking(t_var *stacks)
{
	t_node	*new_node;
	int		idx;

	idx = 0;
	while (idx < stacks->list_size)
	{
		new_node = get_new_node(stacks->list[idx] + 1);
		push_bottom(stacks->stack_a, new_node);
		idx++;
	}
	stacks->a_size = stacks->list_size;
	stacks->max_size = stacks->list_size;
}

void	init_stack(t_var *stacks)
{
	stacks->stack_a = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->stack_a)
		ps_error(stacks, NULL);
	stacks->stack_b = (t_stack *)malloc(sizeof(t_stack));
	if (!stacks->stack_b)
		ps_error(stacks, NULL);
	stacks->stack_a->top = get_new_node(0);
	stacks->stack_a->bottom = get_new_node(0);
	stacks->stack_a->top->right = stacks->stack_a->bottom;
	stacks->stack_a->bottom->left = stacks->stack_a->top;
	stacks->stack_b->top = get_new_node(0);
	stacks->stack_b->bottom = get_new_node(0);
	stacks->stack_b->top->right = stacks->stack_b->bottom;
	stacks->stack_b->bottom->left = stacks->stack_b->top;
	stacks->list = (int *)malloc(sizeof(int));
	if (!stacks->list)
		ps_error(stacks, NULL);
	stacks->list_size = 0;
	stacks->a_size = 0;
	stacks->b_size = 0;
}

t_node	*get_new_node(int num)
{
	t_node	*node;

	node = (t_node *)malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->val = num;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
