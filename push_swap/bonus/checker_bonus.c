/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:58:00 by hylim             #+#    #+#             */
/*   Updated: 2024/10/31 13:31:20 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	main(int ac, char **av)
{
	t_var	stacks;

	if (ac >= 2)
	{
		init_stack(&stacks);
		validate_args(ac, av, &stacks);
		indexing(&stacks);
		stacking(&stacks);
		operating(&stacks);
		checker(&stacks);
		free_stacks(&stacks);
		exit(0);
	}
	return (0);
}
