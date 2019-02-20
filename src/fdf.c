/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 19:05:23 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/20 15:06:16 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include "stdlib.h"

int		fdf(char *argv)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	allocate_memory(mlx);
	initialize_mlx(mlx, argv);
	read_file(mlx);
	get_colors(mlx);
	draw_map(mlx);
	interface(mlx, 0);
	mlx_hook(WINDOW, KEYPRESSED, 0, key_press, mlx);
	mlx_hook(WINDOW, KEYRELEASED, 0, key_release, mlx);
	mlx_hook(WINDOW, MOUSEPRESSED, 0, mouse_press, mlx);
	mlx_hook(WINDOW, MOSUERELEASED, 0, mouse_release, mlx);
	mlx_hook(WINDOW, MOUSEMOVED, 0, mouse_move, mlx);
	mlx_hook(WINDOW, REDBUTTONPRESSED, 0, exit_fdf, (void *)0);
	mlx_loop(PTR);
	return (1);
}

int		exit_fdf(int err_key, char *err_reason, t_mlx *mlx)
{
	if (mlx && err_key == 0)
	{
		free_memory(mlx);
		ft_putendl(err_reason);
	}
	else if (err_key == 1)
	{
		ft_putstr_fd("usage: ", STDERR_FILENO);
		ft_putstr_fd("42_fdf", STDERR_FILENO);
		ft_putstr_fd(" [input file]\n", STDERR_FILENO);
	}
	system("leaks fdf");
	exit(EXIT_FAILURE);
}
