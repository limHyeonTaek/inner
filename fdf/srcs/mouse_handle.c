/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:29:49 by hylim             #+#    #+#             */
/*   Updated: 2024/11/07 13:18:44 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == MOUSE_LEFT_BUTTON)
	{
		fdf->mouse.is_pressed = 1;
		fdf->mouse.prev_x = x;
		fdf->mouse.prev_y = y;
	}
	else if (button == MOUSE_RIGHT_BUTTON)
	{
	}
	if (button == MOUSE_SCROLL_UP)
	{
		fdf->cam->scale_factor *= 1.1;
		if (fdf->cam->scale_factor > MAX_SCALE)
			fdf->cam->scale_factor = MAX_SCALE;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		fdf->cam->scale_factor *= 0.9;
		if (fdf->cam->scale_factor < MIN_SCALE)
			fdf->cam->scale_factor = MIN_SCALE;
	}
	render(fdf);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_BUTTON)
		fdf->mouse.is_pressed = 0;
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	float	dx;
	float	dy;
	float	rotation_speed;

	if (fdf->mouse.is_pressed)
	{
		dx = (float)(x - fdf->mouse.prev_x);
		dy = (float)(y - fdf->mouse.prev_y);
		rotation_speed = 0.002f;
		fdf->cam->beta += dx * rotation_speed;
		fdf->cam->alpha -= dy * rotation_speed;
		fdf->mouse.prev_x = x;
		fdf->mouse.prev_y = y;
		render(fdf);
	}
	return (0);
}
