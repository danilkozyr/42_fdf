/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:58:15 by bslipoko          #+#    #+#             */
/*   Updated: 2019/02/19 18:06:22 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	draw(int x, int y, int color, t_mlx *mlx)
{
	int h;
	int w;
	int b;

	b = IMAGE->bits_per_pixel;
	h = WIN_HEIGHT;
	w = WIN_WIDTH;
	if (x < 0 || x >= w || y < 0 || y >= h)
		return ;
	*(int *)(IMAGE->ptr + ((x + y * w) * b)) = color;
}

int		get_axis(int x, int y)
{
	int a;

	a = 0;
	if (y >= WIN_HEIGHT)
		a = 1;
	else if (y < 0)
		a = 2;
	if (x >= WIN_WIDTH)
		a = 11;
	else if (x < 0)
		a = 12;
	return (a);
}

int		connect(t_dot *a, t_dot *b, t_mlx *mlx)
{
	double	percentage;
	int		*d[2];
	int		*s[2];
	int		*err[2];

	custom(d, mlx->line->d);
	custom(s, mlx->line->s);
	custom(err, mlx->line->err);
	if ((a->x < 0 || a->x >= WIN_WIDTH) || (a->y < 0 || a->y >= WIN_HEIGHT) ||
		(b->x < 0 || b->x >= WIN_WIDTH) || (b->y < 0 || b->y >= WIN_HEIGHT))
		return (1);
	percentage = percentage_help(d, a, mlx);
	draw(a->x, a->y, get_color(a->c, b->c, percentage), mlx);
	*err[1] = *err[0];
	if (*err[1] > -*d[0])
	{
		*err[0] = *err[0] - *d[1];
		a->x = a->x + *s[0];
	}
	if (*err[1] < *d[1])
	{
		*err[0] = *err[0] + *d[0];
		a->y = a->y + *s[1];
	}
	return (0);
}

void	line(t_dot a, t_dot b, t_mlx *mlx)
{
	int	*d[2];
	int *s[2];
	int *err;

	d[0] = &LINE->d[0];
	d[1] = &LINE->d[1];
	s[0] = &LINE->s[0];
	s[1] = &LINE->s[1];
	err = &LINE->err[0];
	LINE->a = a;
	LINE->b = b;
	*d[0] = abs((int)b.x - (int)a.x);
	*d[1] = abs((int)b.y - (int)a.y);
	*s[0] = a.x < b.x ? 1 : -1;
	*s[1] = a.y < b.y ? 1 : -1;
	*err = (*d[0] > *d[1] ? *d[0] : -*d[1]) / 2;
	while (((int)a.x != (int)b.x || (int)a.y != (int)b.y))
		if (connect(&a, &b, mlx))
			break ;
}
