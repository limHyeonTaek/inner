/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handle_util_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 12:18:56 by hylim             #+#    #+#             */
/*   Updated: 2024/11/07 13:31:03 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	key_press_extra(int keycode, t_fdf *fdf);
static void	key_release_extra(int keycode, t_fdf *fdf);

int	key_press(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->keys.up = 1;
	else if (keycode == KEY_DOWN)
		fdf->keys.down = 1;
	else if (keycode == KEY_LEFT)
		fdf->keys.left = 1;
	else if (keycode == KEY_RIGHT)
		fdf->keys.right = 1;
	else if (keycode == KEY_PLUS)
		fdf->keys.plus = 1;
	else if (keycode == KEY_MINUS)
		fdf->keys.minus = 1;
	else
		key_press_extra(keycode, fdf);
	return (0);
}

static void	key_press_extra(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->keys.z = 1;
	else if (keycode == KEY_X)
		fdf->keys.x = 1;
	else if (keycode == KEY_A)
		fdf->keys.a = 1;
	else if (keycode == KEY_D)
		fdf->keys.d = 1;
	else if (keycode == KEY_S)
		fdf->keys.s = 1;
	else if (keycode == KEY_Q)
		fdf->keys.q = 1;
	else if (keycode == KEY_E)
		fdf->keys.e = 1;
	else if (keycode == KEY_W)
		fdf->keys.w = 1;
}

int	key_release(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_UP)
		fdf->keys.up = 0;
	else if (keycode == KEY_DOWN)
		fdf->keys.down = 0;
	else if (keycode == KEY_LEFT)
		fdf->keys.left = 0;
	else if (keycode == KEY_RIGHT)
		fdf->keys.right = 0;
	else if (keycode == KEY_PLUS)
		fdf->keys.plus = 0;
	else if (keycode == KEY_MINUS)
		fdf->keys.minus = 0;
	else
		key_release_extra(keycode, fdf);
	return (0);
}

static void	key_release_extra(int keycode, t_fdf *fdf)
{
	if (keycode == KEY_Z)
		fdf->keys.z = 0;
	else if (keycode == KEY_X)
		fdf->keys.x = 0;
	else if (keycode == KEY_A)
		fdf->keys.a = 0;
	else if (keycode == KEY_D)
		fdf->keys.d = 0;
	else if (keycode == KEY_S)
		fdf->keys.s = 0;
	else if (keycode == KEY_Q)
		fdf->keys.q = 0;
	else if (keycode == KEY_E)
		fdf->keys.e = 0;
	else if (keycode == KEY_W)
		fdf->keys.w = 0;
}
