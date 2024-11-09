/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:16:58 by hylim             #+#    #+#             */
/*   Updated: 2024/11/08 12:58:56 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handle(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_ESC)
		close_all(fdf, 0);
	else if (keycode == KEY_P)
		fdf->cam->projection = PERSPECTIVE;
	else if (keycode == KEY_I)
		fdf->cam->projection = ISOMETRIC;
	else if (keycode == KEY_O)
		fdf->cam->projection = TOP;
	else if (keycode == KEY_SPACE)
		fdf->cam->color_pallet = !fdf->cam->color_pallet;
	else if (keycode == KEY_R)
		reset(fdf);
	else
		key_press(keycode, fdf);
	render(fdf);
	return (0);
}

void	key_translate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_RIGHT)
		fdf->cam->move_x += 10;
	else if (keycode == KEY_LEFT)
		fdf->cam->move_x -= 10;
	else if (keycode == KEY_DOWN)
		fdf->cam->move_y += 10;
	else if (keycode == KEY_UP)
		fdf->cam->move_y -= 10;
}

void	key_scale(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_PLUS)
	{
		fdf->cam->scale_factor *= 1.1;
		if (fdf->cam->scale_factor > MAX_SCALE)
			fdf->cam->scale_factor = MAX_SCALE;
	}
	else if (keycode == KEY_MINUS)
	{
		fdf->cam->scale_factor *= 0.9;
		if (fdf->cam->scale_factor < MIN_SCALE)
			fdf->cam->scale_factor = MIN_SCALE;
	}
	else if (keycode == KEY_Z && fdf->cam->scale_z > -1)
		fdf->cam->scale_z -= 0.01;
	else if (keycode == KEY_X && fdf->cam->scale_z < 1)
		fdf->cam->scale_z += 0.01;
}

void	key_rotate(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_S)
		fdf->cam->alpha -= (1 * ANG_1);
	else if (keycode == KEY_W)
		fdf->cam->alpha += (1 * ANG_1);
	else if (keycode == KEY_D)
		fdf->cam->gamma -= (1 * ANG_1);
	else if (keycode == KEY_A)
		fdf->cam->gamma += (1 * ANG_1);
	else if (keycode == KEY_Q)
		fdf->cam->beta -= (1 * ANG_1);
	else if (keycode == KEY_E)
		fdf->cam->beta += (1 * ANG_1);
}
