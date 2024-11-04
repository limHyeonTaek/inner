/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:54:50 by hylim             #+#    #+#             */
/*   Updated: 2024/10/28 19:56:11 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	ft_printf("rra\n");
}

void	rrb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
	ft_printf("rrb\n");
}

void	rrr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_bottom(stacks->stack_a);
	push_top(stacks->stack_a, tmp);
	tmp = pop_bottom(stacks->stack_b);
	push_top(stacks->stack_b, tmp);
	ft_printf("rrr\n");
}
