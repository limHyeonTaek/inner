/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:17:13 by hylim             #+#    #+#             */
/*   Updated: 2024/11/04 20:32:52 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char	*get_projection_name(t_fdf *fdf);

static void	put_str(void *mlx, void *win, int *y, char *str)
{
	mlx_string_put(mlx, win, 50, *y += 20, C_TEXT, str);
}

void	print_menu(t_fdf *fdf)
{
	int		y;
	void	*mlx;
	void	*win;

	y = 30;
	mlx = fdf->mlx;
	win = fdf->win;
	put_str(mlx, win, &y, get_projection_name(fdf));
	put_str(mlx, win, &y, "Press 'ESC' to close");
	put_str(mlx, win, &y, "Zoom: press '-' or '+'");
	put_str(mlx, win, &y, "Move: press arrow keys");
	put_str(mlx, win, &y, "Rotate: X-S/W, Y-Q/E, Z-A/D");
	put_str(mlx, win, &y, "Scale Z: press 'Z' or 'X'");
	put_str(mlx, win, &y, "Change view: I-Iso, P-Persp, O-Top");
	put_str(mlx, win, &y, "Colors: press 'SPACE'");
	put_str(mlx, win, &y, "Reset view: press 'R'");
	put_str(mlx, win, &y, "Mouse: Left click & drag to rotate");
	put_str(mlx, win, &y, "Mouse: Scroll to zoom in/out");
}

static char	*get_projection_name(t_fdf *fdf)
{
	char	*projection;

	projection = "";
	if (fdf->cam->projection == ISOMETRIC)
		projection = "Isometric projection";
	else if (fdf->cam->projection == PERSPECTIVE)
		projection = "Perspective projection";
	else if (fdf->cam->projection == TOP)
		projection = "Top view";
	return (projection);
}
