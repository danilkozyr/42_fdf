/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 18:07:41 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 16:02:09 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_dot	rotate(t_dot d, t_mlx *mlx)
{
	t_dot	r;

	r.x = d.x * cos(CAMERA->z) - d.y * sin(CAMERA->z);
	r.y = d.x * sin(CAMERA->z) + d.y * cos(CAMERA->z);
	d.x = r.x;
	d.y = r.y;
	r.x = d.z * sin(CAMERA->x) + d.x * cos(CAMERA->x);
	r.z = d.z * cos(CAMERA->x) - d.x * sin(CAMERA->x);
	d.z = r.z;
	r.y = d.y * cos(CAMERA->y) - d.z * sin(CAMERA->y);
	r.z = d.y * sin(CAMERA->y) + d.z * cos(CAMERA->y);
	r.c = d.c;
	return (r);
}

t_dot	set_dot(t_dot *dot, t_mlx *mlx)
{
	t_dot	r;

	r = *dot;
	r.x = r.x - (MAP->width - 1) / 2;
	r.y = r.y - (MAP->height - 1) / 2;
	r = rotate(r, mlx);
	r.x = r.x * CAMERA->scale;
	r.y = r.y * CAMERA->scale;
	r.x = r.x + CAMERA->xshift;
	r.y = r.y + CAMERA->yshift;
	return (r);
}

void	draw_map(t_mlx *mlx)
{
	int x;
	int y;

	ft_bzero(IMAGE->ptr, WIN_WIDTH * WIN_HEIGHT * IMAGE->bits_per_pixel);
	mlx_clear_window(PTR, WINDOW);
	x = -1;
	y = -1;
	while (++y < MAP->height && (x = -1))
		while (++x < MAP->width)
		{
			if (x + 1 < MAP->width)
				line(set_dot(DOT[IN(x, y)], mlx),
					set_dot(DOT[IN((x + 1), y)], mlx), mlx);
			if (y + 1 < MAP->height)
				line(set_dot(DOT[IN(x, y)], mlx),
					set_dot(DOT[IN(x, (y + 1))], mlx), mlx);
		}
	mlx_put_image_to_window(PTR, WINDOW, IMAGE->image, 0, 0);
}
