/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys_action.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:45:05 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 16:05:01 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	change_camera_scale(int key, t_mlx *mlx)
{
	if (PLUS)
	{
		if (CAMERA->scale < 46)
			CAMERA->scale += 1;
	}
	else
	{
		if (CAMERA->scale > 1)
			CAMERA->scale -= 1;
	}
	draw_map(mlx);
	interface(mlx, key);
}

void	change_projection(int key, t_mlx *mlx)
{
	CAMERA->x = RAD(0);
	if (Q)
	{
		CAMERA->y = RAD(55);
		CAMERA->z = -RAD(45);
	}
	else if (W)
	{
		CAMERA->y = RAD(56);
		CAMERA->z = -RAD(42);
	}
	else if (E)
	{
		CAMERA->y = RAD(14);
		CAMERA->z = -RAD(42);
	}
	else if (R)
	{
		CAMERA->y = RAD(90);
		CAMERA->z = RAD(0);
	}
	CAMERA->xshift = WIN_WIDTH / 2;
	CAMERA->yshift = WIN_HEIGHT / 2;
	draw_map(mlx);
	interface(mlx, key);
}

void	change_position(int key, t_mlx *mlx)
{
	if (LEFT)
		CAMERA->xshift = CAMERA->xshift - 10;
	else if (RIGHT)
		CAMERA->xshift = CAMERA->xshift + 10;
	else if (UP)
		CAMERA->yshift = CAMERA->yshift - 10;
	else if (DOWN)
		CAMERA->yshift = CAMERA->yshift + 10;
	draw_map(mlx);
	interface(mlx, key);
}

void	change_camera_angle(t_mlx *mlx, int x, int y, int *last)
{
	CAMERA->x = CAMERA->x + ((x - last[0]) / 400.0f);
	CAMERA->y = CAMERA->y + ((last[1] - y) / 400.0f);
	draw_map(mlx);
	interface(mlx, 10);
}

void	change_color(int key, t_mlx *mlx)
{
	COLOR1 = BLACK;
	COLOR4 = WHITE;
	if (A)
	{
		COLOR2 = BLUE;
		COLOR3 = YELLOW;
	}
	else if (S)
	{
		COLOR2 = AQUA;
		COLOR3 = BLUE;
	}
	else if (D)
	{
		COLOR2 = GREEN;
		COLOR3 = AQUA;
	}
	else if (F)
	{
		COLOR2 = WHITE;
		COLOR3 = WHITE;
	}
	get_colors(mlx);
	draw_map(mlx);
	interface(mlx, 10);
}
