/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:23:50 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 18:09:32 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	reset_height(t_mlx *mlx)
{
	int length;
	int i;

	i = -1;
	length = MAP->width * MAP->height;
	while (++i < length)
		DOT[i]->z = DOT[i]->z == DOT[i]->dz ? DOT[i]->z : DOT[i]->dz;
}

void	rise_height(t_mlx *mlx)
{
	int length;
	int i;
	int diff;

	diff = 0;
	i = -1;
	length = MAP->width * MAP->height;
	while (++i < length && diff != 1)
		DOT[i]->dz > 0 && DOT[i]->z < -DOT[i]->dz ? diff = 1 : 0;
	if (diff && (i = -1))
		while (++i < length)
			DOT[i]->dz > 0 && DOT[i]->z + 1 <= -DOT[i]->dz ? DOT[i]->z += 1 : 0;
	else if ((i = -1))
	{
		while (++i < length && diff != 1)
			DOT[i]->dz > 0 && DOT[i]->z < DOT[i]->dz ? diff = 1 : 0;
		if (diff && (i = -1))
			while (++i < length)
				DOT[i]->dz > 0 &&
				DOT[i]->z + 1 <= DOT[i]->dz ? DOT[i]->z += 1 : 0;
		else if ((i = -1))
			while (++i < length)
				DOT[i]->dz > 0 &&
				DOT[i]->z + 1 <= DOT[i]->dz * 2 ? DOT[i]->z += 1 : 0;
	}
}

void	drop_height(t_mlx *mlx)
{
	int length;
	int i;
	int diff;

	diff = 0;
	i = -1;
	length = MAP->width * MAP->height;
	while (++i < length && diff != 1)
		DOT[i]->dz > 0 && DOT[i]->z > DOT[i]->dz ? diff = 1 : 0;
	if (diff && (i = -1))
		while (++i < length)
			DOT[i]->dz > 0 && DOT[i]->z - 1 >= DOT[i]->dz ? DOT[i]->z -= 1 : 0;
	else if ((i = -1))
	{
		while (++i < length && diff != 1)
			DOT[i]->dz > 0 && DOT[i]->z > -DOT[i]->dz ? diff = 1 : 0;
		if (diff && (i = -1))
			while (++i < length)
				DOT[i]->dz > 0 &&
				DOT[i]->z - 1 >= -DOT[i]->dz ? DOT[i]->z -= 1 : 0;
		else if ((i = -1))
			while (++i < length)
				DOT[i]->dz > 0 &&
				DOT[i]->z - 1 >= -DOT[i]->dz * 2 ? DOT[i]->z -= 1 : 0;
	}
}

void	change_height(int key, t_mlx *mlx)
{
	if (Z)
		rise_height(mlx);
	else if (X)
		drop_height(mlx);
	else if (C)
		reset_height(mlx);
	draw_map(mlx);
	interface(mlx, 0);
	get_colors(mlx);
}
