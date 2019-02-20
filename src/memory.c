/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 19:47:49 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/20 15:06:13 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	initialize_mlx(t_mlx *mlx, char *argv)
{
	mlx->filename = argv;
	IMAGE->bits_per_pixel = IMAGE->bits_per_pixel / 8;
	CAMERA->x = RAD(0);
	CAMERA->y = RAD(55);
	CAMERA->z = -RAD(45);
	CAMERA->scale = 10;
	CAMERA->xshift = WIN_WIDTH / 2;
	CAMERA->yshift = WIN_HEIGHT / 2;
	MOUSE->ispressed = 0;
	MOUSE->lcrds[0] = 0;
	MOUSE->lcrds[1] = 0;
	MOUSE->crds[0] = 0;
	MOUSE->crds[1] = 0;
	MAP->height = 0;
	MAP->width = 0;
	MAP->depth = 0;
	MAP->atitude = 0;
	MAP->color = WHITE;
	COLOR1 = BLACK;
	COLOR2 = WHITE;
	COLOR3 = WHITE;
	COLOR4 = WHITE;
}

void	allocate_memory(t_mlx *mlx)
{
	IMAGE = malloc(sizeof(t_image));
	MAP = malloc(sizeof(t_map));
	CAMERA = malloc(sizeof(t_camera));
	MOUSE = malloc(sizeof(t_mouse));
	LINE = malloc(sizeof(t_line));
	PTR = mlx_init();
	WINDOW = mlx_new_window(PTR, WIN_WIDTH, WIN_HEIGHT, "FdF 42");
	IMAGE->image = mlx_new_image(PTR, WIN_WIDTH, WIN_HEIGHT);
	IMAGE->ptr = mlx_get_data_addr(IMAGE->image, &IMAGE->bits_per_pixel,
									&IMAGE->size_len, &IMAGE->endian);
}

void	free_memory(t_mlx *mlx)
{
	int i;

	i = MAP->width * MAP->height;
	if (mlx)
	{
		if (DOT)
		{
			while (--i >= 0)
				free(DOT[i]);
			free(DOT);
		}
		if (CAMERA)
			free(CAMERA);
		if (MAP)
			free(MAP);
		if (IMAGE->image)
			mlx_destroy_image(PTR, IMAGE->image);
		if (IMAGE)
			free(IMAGE);
		if (MOUSE)
			free(MOUSE);
		if (LINE)
			free(LINE);
		free(mlx);
	}
}
