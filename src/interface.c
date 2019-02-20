/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkozyr <dkozyr@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 17:29:56 by dkozyr            #+#    #+#             */
/*   Updated: 2019/02/19 14:50:00 by dkozyr           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	show_hints(t_mlx *mlx)
{
	char	*w;
	int		h;

	h = WIN_HEIGHT;
	w = WINDOW;
	mlx_string_put(PTR, w, 20, h - 110, WHITE, "          +/-:        zoom");
	mlx_string_put(PTR, w, 20, h - 90, WHITE, "   MOUSE HOLD:      rotate");
	mlx_string_put(PTR, w, 20, h - 70, WHITE, "  KBRD ARROWS:   movements");
	mlx_string_put(PTR, w, 20, h - 50, WHITE, "A, S, D, F, G:      colors");
	mlx_string_put(PTR, w, 20, h - 30, WHITE, "   Q, W, E, R:  projection");
}

void	hide_hints(t_mlx *mlx)
{
	mlx_clear_window(PTR, WINDOW);
	draw_map(mlx);
	interface(mlx, 0);
}

void	interface(t_mlx *mlx, int key)
{
	int w;
	int h;

	w = WIN_WIDTH - 80;
	h = WIN_HEIGHT - 40;
	if (Q)
		mlx_string_put(PTR, WINDOW, w, h, WHITE, "VIEW 1");
	else if (W)
		mlx_string_put(PTR, WINDOW, w, h, WHITE, "VIEW 2");
	else if (E)
		mlx_string_put(PTR, WINDOW, w, h, WHITE, "VIEW 3");
	else if (R)
		mlx_string_put(PTR, WINDOW, w, h, WHITE, "VIEW 4");
	mlx_string_put(PTR, WINDOW, WIN_WIDTH - 110, 10, WHITE, "ESC: exit");
	mlx_string_put(PTR, WINDOW, WIN_WIDTH - 110, 30, WHITE, "TAB: help");
}
