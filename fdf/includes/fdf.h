/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hylim <hylim@student.42gyeongsan.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:19:25 by hylim             #+#    #+#             */
/*   Updated: 2024/11/08 22:13:42 by hylim            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "mlx.h"
# include <math.h>
# include "ft_printf.h"

# include "colors.h"
# include "keys_n_mouse.h"


typedef struct s_point
{
	float	x;
	float	y;
	float	z;
	int		color;
}			t_point;

typedef struct s_map
{
	t_point	**coordinates;
	int		max_x;
	int		max_y;
	int		max_z;
	int		min_z;
}			t_map;

typedef struct s_line
{
	t_point	start;
	t_point	end;
	float	transform_z;
}			t_line;

typedef struct s_color
{
	int		start_color;
	int		start_r;
	int		start_g;
	int		start_b;
	int		end_color;
	int		end_r;
	int		end_g;
	int		end_b;
	int		delta_r;
	int		delta_g;
	int		delta_b;
}			t_color;

typedef struct s_image
{
	void	*image;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buffer;
	t_line	*line;
}			t_image;

typedef struct s_mouse
{
	int		is_pressed;
	int		prev_x;
	int		prev_y;
}			t_mouse;

typedef struct s_keys
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		plus;
	int		minus;
	int		z;
	int		x;
	int		a;
	int		q;
	int		e;
	int		w;
	int		s;
	int		d;
}			t_keys;

typedef struct s_cam
{
	int		projection;
	int		color_pallet;
	float	scale_factor;
	float	scale_z;
	float	move_x;
	float	move_y;
	double	alpha;
	double	beta;
	double	gamma;
}			t_cam;

typedef struct s_fdf
{
	t_map	*map;
	void	*mlx;
	int		win_x;
	int		win_y;
	void	*win;
	t_image	*image;
	t_cam	*cam;
	t_mouse	mouse;
	t_keys	keys;
}			t_fdf;

# define MIN_SCALE 1.0
# define MAX_SCALE 100.0
# define WINDOW_NAME "fdf"
# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 1000
# define MAX_PIXEL 1080000
# define LINE_DEFAULT C_WHITE
# define BACKGROUND_DEFAULT C_BLACK
# define C_TEXT C_WHITE
# define HEXADECIMAL_L_BASE "0123456789abcdef"
# define ANG_1 0.01745329
# define ANG_30 0.52359877
# define ANG_45 0.78539816

enum		e_projection
{
	ISOMETRIC,
	PERSPECTIVE,
	TOP
};

enum		e_bool
{
	FALSE,
	TRUE
};

t_map		*read_map(char *file_name);
int			ft_atoi_base(char *str, char *base);
int			ft_split_count(char *s, char c);

void		error(int exit_code);

t_fdf		*init_fdf(char *file_name);
t_map		*init_map(void);
t_image		*init_image(void *mlx);
t_line		*init_line(t_point start, t_point end, t_fdf *fdf);
t_cam		*init_cam(t_map *map);
void		init_mouse_n_keys(t_fdf *fdf);

t_point		**init_coordinates(int width, int depth);
void		center_to_origin(t_map *map);
float		scale_to_fit(t_map *map);
void		reset(t_fdf *fdf);
void		close_all(t_fdf *fdf, int exit_code);
void		close_map(t_fdf *fdf, int exit_code);
t_color		*color_init(t_point start, t_point end);
t_color		*color_pallet_init(int min_color, int max_color);

int			close_window(t_fdf *fdf);
float		absolute(float nbr);
float		max(float a, float b);
float		min(float a, float b);

void		render(t_fdf *fdf);
void		draw_image(t_image *image, int max_x, int max_y);
void		bresenham(t_fdf *fdf, t_point start, t_point end);
void		pixel_to_image(t_image *image, float x, float y, int color);
void		clear_image(t_image *image, int image_size);
void		print_menu(t_fdf *fdf);
int			get_color(t_color *color, int i_line, int line_size);

void		rotate(t_cam *cam, t_line *line);
void		rotate_x(t_line *line, double angle);
void		rotate_y(t_line *line, double angle);
void		rotate_z(t_line *line, double angle);
void		project(t_cam *cam, t_line *line);
void		transform(t_cam *cam, t_line *line);
void		scale(t_line *line, int scale_factor);
void		translate(t_line *line, int move_x, int move_y);

int			key_handle(int keycode, t_fdf *fdf);
int			key_release(int keycode, t_fdf *fdf);
int			key_press(int keycode, t_fdf *fdf);
void		key_translate(int keycode, t_fdf *fdf);
void		key_scale(int keycode, t_fdf *fdf);
void		key_rotate(int keycode, t_fdf *fdf);
void		update_translate(t_fdf *fdf);
void		update_scale(t_fdf *fdf);
void		update_rotate(t_fdf *fdf);
void		update(t_fdf *fdf);

int			mouse_press(int button, int x, int y, t_fdf *fdf);
int			mouse_release(int button, int x, int y, t_fdf *fdf);
int			mouse_move(int x, int y, t_fdf *fdf);

#endif