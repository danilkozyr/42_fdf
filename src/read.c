/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/17 14:18:34 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 15:43:38 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		count_map_size(char *str)
{
	int	map_size;
	int	i;

	map_size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '\0' && str[i] == ' ')
			i++;
		if (str[i] != '\0' && str[i] != ' ')
			map_size++;
		while (str[i] != '\0' && str[i] != ' ')
			i++;
	}
	return (map_size);
}

void	create_dots(t_mlx *mlx, int i, int x)
{
	int		fd;
	int		y;
	char	*line;
	char	**nds;

	y = -1;
	if ((fd = open(mlx->filename, O_RDONLY)) < 0)
		exit_fdf(0, "error opening fd 2", mlx);
	while ((get_next_line(fd, &line) > 0) && (++y > -1) && (x = -1))
	{
		nds = ft_strsplit(line, ' ');
		while (++x < MAP->width && ((++i > -1)))
		{
			DOT[i]->z = ft_atoi(nds[x]);
			DOT[i]->x = x;
			DOT[i]->y = y;
			DOT[i]->dz = DOT[i]->z;
			free(nds[x]);
		}
		free(nds);
		free(line);
	}
	if (((close(fd) < 0)))
		exit_fdf(0, "error closing fd", mlx);
}

void	map_depth(t_mlx *mlx)
{
	int len;
	int n;

	len = MAP->width * MAP->height;
	MAP->atitude = 0;
	MAP->depth = 0;
	n = 0;
	while (n < len)
	{
		if (DOT[n]->z < MAP->depth)
			MAP->depth = DOT[n]->z;
		else if (DOT[n]->z > MAP->atitude)
			MAP->atitude = DOT[n]->z;
		n++;
	}
}

int		create_map(t_mlx *mlx)
{
	int i;
	int x;

	x = 0;
	i = MAP->width * MAP->height;
	if (!(DOT = malloc(sizeof(t_dot *) * i)))
		exit_fdf(0, "DOT memory alloc error", mlx);
	while (--i >= 0)
	{
		if (!(DOT[i] = malloc(sizeof(t_dot))))
			exit_fdf(0, "DOT memory alloc error", mlx);
	}
	create_dots(mlx, -1, x);
	map_depth(mlx);
	return (0);
}

int		read_file(t_mlx *mlx)
{
	int		fd;
	char	*line;
	int		len;
	int		r;

	MAP->width = 0;
	MAP->height = 0;
	if (!(fd = open(mlx->filename, O_RDONLY)))
		return (exit_fdf(0, "fd opening error", mlx));
	while ((r = get_next_line(fd, &line)) > 0)
	{
		len = count_map_size(line);
		if ((MAP->width && (MAP->width != len)))
			exit_fdf(0, "error map width", mlx);
		MAP->width = len;
		MAP->height++;
		free(line);
	}
	if ((r < 0 || (MAP->width == 0) || (MAP->height == 0)))
		exit_fdf(0, "ENTER CORRECT FILE", mlx);
	if (close(fd) < 0)
		exit_fdf(0, "fd closing error", mlx);
	create_map(mlx);
	get_colors(mlx);
	return (1);
}
