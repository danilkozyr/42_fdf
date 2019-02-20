/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 14:23:40 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 15:48:05 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double	percent(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(int c1, int c2, double percentage)
{
	int red;
	int green;
	int blue;

	red = 0;
	green = 0;
	blue = 0;
	if (c1 == c2)
		return (c1);
	red = get_light((c1 >> 16) & 0xFF, (c2 >> 16) & 0xFF, percentage);
	green = get_light((c1 >> 8) & 0xFF, (c2 >> 8) & 0xFF, percentage);
	blue = get_light(c1 & 0xFF, c2 & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}

void	get_colors(t_mlx *mlx)
{
	int n;

	n = -1;
	while (++n < MAP->width * MAP->height)
		if (DOT[n]->z > MAP->atitude)
			DOT[n]->c = get_color(COLOR3, COLOR4,
				percent(MAP->atitude, MAP->atitude * 2, DOT[n]->z));
		else if (DOT[n]->z >= MAP->depth && DOT[n]->z <= MAP->atitude)
			DOT[n]->c = get_color(COLOR2, COLOR3,
				percent(MAP->depth, MAP->atitude, DOT[n]->z));
		else if (DOT[n]->z >= -(MAP->atitude) && DOT[n]->z < MAP->depth)
			DOT[n]->c = get_color(COLOR1, COLOR2,
				percent(-(MAP->atitude), MAP->depth, DOT[n]->z));
		else if (DOT[n]->z < MAP->depth)
			DOT[n]->c = get_color(COLOR1, COLOR1,
				percent(-(MAP->atitude * 2), -(MAP->atitude), DOT[n]->z));
}
