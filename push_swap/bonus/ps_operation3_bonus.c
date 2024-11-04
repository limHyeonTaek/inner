/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operation3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 19:54:50 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 14:21:28 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ra(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
}

void	rb(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
}

void	rr(t_var *stacks)
{
	t_node	*tmp;

	tmp = pop_top(stacks->stack_a);
	push_bottom(stacks->stack_a, tmp);
	tmp = pop_top(stacks->stack_b);
	push_bottom(stacks->stack_b, tmp);
}

int	operation(char *op, t_var *stacks)
{
	if (!ft_strcmp(op, "\n"))
		return (0);
	else if (!ft_strcmp(op, "sa\n"))
		return (sa(stacks), 1);
	else if (!ft_strcmp(op, "sb\n"))
		return (sb(stacks), 1);
	else if (!ft_strcmp(op, "ss\n"))
		return (ss(stacks), 1);
	else if (!ft_strcmp(op, "pa\n"))
		return (pa(stacks), 1);
	else if (!ft_strcmp(op, "pb\n"))
		return (pb(stacks), 1);
	else if (!ft_strcmp(op, "ra\n"))
		return (ra(stacks), 1);
	else if (!ft_strcmp(op, "rb\n"))
		return (rb(stacks), 1);
	else if (!ft_strcmp(op, "rr\n"))
		return (rr(stacks), 1);
	else if (!ft_strcmp(op, "rra\n"))
		return (rra(stacks), 1);
	else if (!ft_strcmp(op, "rrb\n"))
		return (rrb(stacks), 1);
	else if (!ft_strcmp(op, "rrr\n"))
		return (rrr(stacks), 1);
	return (0);
}

void	operating(t_var *stacks)
{
	char	*op;
	int		flag;

	while (1)
	{
		op = get_next_line(0);
		if (!op)
			break ;
		flag = operation(op, stacks);
		if (!flag)
		{
			free(op);
			ps_error(stacks, NULL);
		}
		free(op);
	}
}
