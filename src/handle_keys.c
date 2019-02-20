/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:05:35 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 18:08:33 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		key_press(int key, t_mlx *mlx)
{
	if (ESC)
		exit_fdf(0, "ESC is pressed", mlx);
	if (TAB)
		show_hints(mlx);
	if (PLUS || MINUS)
		change_camera_scale(key, mlx);
	if (Q || W || E || R)
		change_projection(key, mlx);
	if (A || S || D || F || G)
		change_color(key, mlx);
	if (LEFT || RIGHT || UP || DOWN)
		change_position(key, mlx);
	if (Z || X || C)
		change_height(key, mlx);
	return (0);
}

int		key_release(int key, t_mlx *mlx)
{
	(void)key;
	hide_hints(mlx);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *mlx)
{
	MOUSE->ispressed = 1;
	(void)button;
	(void)x;
	(void)y;
	return (0);
}

int		mouse_release(int button, int x, int y, t_mlx *mlx)
{
	MOUSE->ispressed = 0;
	(void)x;
	(void)y;
	(void)button;
	return (0);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	MOUSE->lcrds[0] = MOUSE->crds[0];
	MOUSE->lcrds[1] = MOUSE->crds[1];
	MOUSE->crds[0] = x;
	MOUSE->crds[1] = y;
	if (MOUSE->ispressed == 1)
		change_camera_angle(mlx, x, y, MOUSE->lcrds);
	return (0);
}
