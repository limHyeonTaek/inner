/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:29:49 by hylim             #+#    #+#             */
/*   Updated: 2024/11/04 20:32:55 by hylim            ###   ########.fr       */
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
	else if (button == MOUSE_SCROLL_UP)
	{
		fdf->cam->scale_factor += 1;
	}
	else if (button == MOUSE_SCROLL_DOWN)
	{
		fdf->cam->scale_factor -= 1;
	}
	render(fdf);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	(void)x;
	(void)y;
	if (button == MOUSE_LEFT_BUTTON)
	{
		fdf->mouse.is_pressed = 0;
	}
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	int	dx;
	int	dy;

	if (fdf->mouse.is_pressed)
	{
		dx = x - fdf->mouse.prev_x;
		dy = y - fdf->mouse.prev_y;
		fdf->cam->beta -= dx * 0.015;
		fdf->cam->alpha -= dy * 0.015;
		if (abs(dx) > 10 || abs(dy) > 10)
		{
			fdf->mouse.prev_x = x;
			fdf->mouse.prev_y = y;
			render(fdf);
		}
	}
	return (0);
}
