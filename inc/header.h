/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 17:11:30 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 18:07:35 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "libft.h"
# include "mlx.h"

# include <stdio.h>
# include <math.h>

# define WIN_WIDTH 1900
# define WIN_HEIGHT 1100
# define WIN_NAME "42 FDF"

# define ESC key == 53
# define TAB key == 48
# define PLUS key == 24
# define MINUS key == 27
# define Q key == 12
# define W key == 13
# define E key == 14
# define R key == 15
# define A key == 0
# define S key == 1
# define D key == 2
# define F key == 3
# define G key == 5
# define Z key == 6
# define X key == 7
# define C key == 8
# define UP key == 126
# define DOWN key == 125
# define LEFT key == 123
# define RIGHT key == 124

# define WHITE 0xFFFFFF
# define RED 0xCA2300
# define YELLOW 0xDED80C
# define BLUE 0x1A71D5
# define GREEN 0x11AD22
# define AQUA 0x00FFFF
# define BLACK 0x000000

# define KEYPRESSED 2
# define KEYRELEASED 3
# define MOUSEPRESSED 4
# define MOSUERELEASED 5
# define MOUSEMOVED 6
# define REDBUTTONPRESSED 17

# define PTR mlx->ptr
# define WINDOW mlx->window
# define IMAGE mlx->image
# define MAP mlx->map
# define CAMERA mlx->camera
# define MOUSE mlx->mouse
# define KEYBRD mlx->keyboard
# define LINE mlx->line

# define DOT mlx->map->dot
# define IN(x, y) y * MAP->width + x
# define RAD(d) ((d) * M_PI / 180.0)

# define COLOR1 mlx->map->colors.color1
# define COLOR2 mlx->map->colors.color2
# define COLOR3 mlx->map->colors.color3
# define COLOR4 mlx->map->colors.color4

typedef	struct	s_colors
{
	int			color1;
	int			color2;
	int			color3;
	int			color4;
}				t_colors;

typedef	struct	s_dot
{
	double		x;
	double		y;
	double		z;
	double		c;
	double		dz;
	double		dc;
}				t_dot;

typedef struct	s_line
{
	t_dot		a;
	t_dot		b;
	int			d[2];
	int			s[2];
	int			err[2];
}				t_line;

typedef struct	s_mouse
{
	int			ispressed;
	int			lcrds[2];
	int			crds[2];
}				t_mouse;

typedef struct	s_camera
{
	double		x;
	double		y;
	double		z;
	double		xshift;
	double		yshift;
	double		scale;
}				t_camera;

typedef struct	s_map
{
	int			height;
	int			width;
	int			depth;
	int			atitude;
	int			length;
	int			color;
	t_dot		**dot;
	t_colors	colors;
}				t_map;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bits_per_pixel;
	int			size_len;
	int			endian;
}				t_image;

typedef struct	s_mlx
{
	void		*ptr;
	void		*window;
	char		*filename;
	t_image		*image;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
	t_line		*line;
}				t_mlx;

int				fdf(char *argv);
int				exit_fdf(int err_key, char *err_reason, t_mlx *mlx);

void			initialize_mlx(t_mlx *mlx, char *argv);
void			allocate_memory(t_mlx *mlx);
void			free_memory(t_mlx *mlx);

int				read_file(t_mlx *mlx);

int				key_press(int key, t_mlx *mlx);
int				key_release(int key, t_mlx *mlx);
int				mouse_press(int button, int x, int y, t_mlx *mlx);
int				mouse_release(int button, int x, int y, t_mlx *mlx);
int				mouse_move(int x, int y, t_mlx *mlx);

void			show_hints(t_mlx *mlx);
void			hide_hints(t_mlx *mlx);
void			interface(t_mlx *mlx, int key);

void			draw_map(t_mlx *mlx);

void			line(t_dot a, t_dot b, t_mlx *mlx);

void			change_camera_scale(int key, t_mlx *mlx);
void			change_projection(int key, t_mlx *mlx);
void			change_position(int key, t_mlx *mlx);
void			change_camera_angle(t_mlx *mlx, int x, int y, int *last);
void			change_color(int key, t_mlx *mlx);
void			change_height(int key, t_mlx *mlx);
void			get_colors(t_mlx *mlx);
double			percent(int start, int end, int current);
int				get_color(int c1, int c2, double percentage);

void			custom(int *d[2], int arr[2]);
double			percentage_help(int *d[2], t_dot *a, t_mlx *mlx);

#endif
