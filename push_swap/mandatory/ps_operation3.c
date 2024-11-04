/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:54:50 by hylim             #+#    #+#             */
/*   Updated: 2024/10/28 22:58:20 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	ft_printf("ra\n");
}

void	rb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	ft_printf("rb\n");
}

void	rr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
	ft_printf("rr\n");
}

void	operating(t_var *stacks)
{
	if (stacks->list_size == 2)
		sa(stacks);
	else if (stacks->list_size == 3)
		sort_three_args(stacks);
	else
		sort_args(stacks);
}
