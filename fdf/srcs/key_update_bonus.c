/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 13:24:07 by hylim             #+#    #+#             */
/*   Updated: 2024/11/07 13:31:13 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	update(t_fdf *fdf)
{
	update_translate(fdf);
	update_scale(fdf);
	update_rotate(fdf);
	render(fdf);
}

void	update_translate(t_fdf *fdf)
{
	if (fdf->keys.right)
		key_translate(KEY_RIGHT, fdf);
	if (fdf->keys.left)
		key_translate(KEY_LEFT, fdf);
	if (fdf->keys.up)
		key_translate(KEY_UP, fdf);
	if (fdf->keys.down)
		key_translate(KEY_DOWN, fdf);
}

void	update_scale(t_fdf *fdf)
{
	if (fdf->keys.plus)
		key_scale(KEY_PLUS, fdf);
	if (fdf->keys.minus)
		key_scale(KEY_MINUS, fdf);
	if (fdf->keys.z)
		key_scale(KEY_Z, fdf);
	if (fdf->keys.x)
		key_scale(KEY_X, fdf);
}

void	update_rotate(t_fdf *fdf)
{
	if (fdf->keys.a)
		key_rotate(KEY_A, fdf);
	if (fdf->keys.d)
		key_rotate(KEY_D, fdf);
	if (fdf->keys.s)
		key_rotate(KEY_S, fdf);
	if (fdf->keys.q)
		key_rotate(KEY_Q, fdf);
	if (fdf->keys.w)
		key_rotate(KEY_W, fdf);
	if (fdf->keys.e)
		key_rotate(KEY_E, fdf);
}
