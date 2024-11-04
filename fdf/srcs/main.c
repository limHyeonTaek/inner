/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:17:05 by hylim             #+#    #+#             */
/*   Updated: 2024/11/04 20:32:48 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose_handle(t_fdf *fdf);

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_key_hook(fdf->win, &key_handle, fdf);
	mlx_mouse_hook(fdf->win, &mouse_press, fdf);
	mlx_hook(fdf->win, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
}

static int	expose_handle(t_fdf *fdf)
{
	render(fdf);
	return (0);
}
