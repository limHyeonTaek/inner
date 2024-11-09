/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:17:05 by hylim             #+#    #+#             */
/*   Updated: 2024/11/08 21:20:34 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	expose_handle(t_fdf *fdf);
static void	validate_extension(char *file_name);

int	main(int argc, char **argv)
{
	char	*file_name;
	t_fdf	*fdf;

	if (argc != 2)
		error(1);
	file_name = argv[1];
	validate_extension(file_name);
	fdf = init_fdf(file_name);
	render(fdf);
	mlx_hook(fdf->win, 2, 1L << 0, key_handle, fdf);
	mlx_hook(fdf->win, 3, 1L << 1, key_release, fdf);
	mlx_loop_hook(fdf->mlx, (void *)update, fdf);
	mlx_mouse_hook(fdf->win, &mouse_press, fdf);
	mlx_hook(fdf->win, 5, 1L << 3, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 1L << 6, mouse_move, fdf);
	mlx_hook(fdf->win, DESTROY_NOTIFY, 0, &close_window, fdf);
	mlx_expose_hook(fdf->win, &expose_handle, fdf);
	mlx_loop(fdf->mlx);
}

static int	expose_handle(t_fdf *fdf)
{
	return (render(fdf), 0);
}

static void	validate_extension(char *file_name)
{
	const char	*dot;

	dot = ft_strrchr(file_name, '.');
	if (!dot || dot == file_name || ft_strncmp(dot + 1, "fdf", 3) != 0)
		error(2);
}
