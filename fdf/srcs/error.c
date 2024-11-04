/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:41 by hylim             #+#    #+#             */
/*   Updated: 2024/11/04 21:38:06 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(int exit_code)
{
	if (exit_code == 0)
		ft_printf("FDF closed.\n");
	else if (exit_code == 1)
		ft_putstr_fd("Usage : ./fdf <filename> [ case_size z_size ]\n", 2);
	else if (exit_code == 2)
	//TODO : No file <filename>
		ft_putstr_fd("No file.\n", 2);
	else if (exit_code == 3)
		ft_putstr_fd("Cannot initialize fdf.\n", 2);
	else if (exit_code == 4)
		ft_putstr_fd("Cannot parse map.\n", 2);
	else if (exit_code == 5)
		ft_putstr_fd("Cannot create image.\n", 2);
	else if (exit_code == 6)
		ft_putstr_fd("Cannot initialize camera.\n", 2);
	else if (exit_code == 7)
		ft_putstr_fd("Unable to render.\n", 2);
	else if (exit_code == 8)
		ft_putstr_fd("Unable to initialize color.\n", 2);
	exit(exit_code);
}
