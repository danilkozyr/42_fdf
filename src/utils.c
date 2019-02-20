/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:04:03 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 18:07:03 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double		percentage_help(int *d[2], t_dot *a, t_mlx *mlx)
{
	double percentage;

	if (*d[0] > *d[1])
		percentage = percent(LINE->a.x, LINE->b.x, a->x);
	else
		percentage = percent(LINE->a.y, LINE->b.y, a->y);
	return (percentage);
}

void		custom(int *d[2], int arr[2])
{
	d[0] = &arr[0];
	d[1] = &arr[1];
}
