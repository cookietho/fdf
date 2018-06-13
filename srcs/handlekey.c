/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlekey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:23:45 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 13:24:34 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	keyfunction(int key, t_fdf *m)
{
	key == 53 ? exit(0) : 0;
	key == 123 ? m->map_x_move += -1 : 0;
	key == 124 ? m->map_x_move += 1 : 0;
	key == 125 ? m->map_y_move += 1 : 0;
	key == 126 ? m->map_y_move += -1 : 0;
	key == 2 ? m->zoom += -2.5 : 0;
	key == 3 ? m->zoom += 2.5 : 0;
	key == 12 ? m->color = 0xff0000 : 0x0000ff;
	key == 13 ? m->color = 0xff00ff : 0x0000ff;
	key == 14 ? m->color = 0x0085ff : 0x0000ff;
	key == 15 ? m->color = 0xf9bb00 : 0x0000ff;
	key == 34 ? m->z_change += .1 : 1;
	key == 32 ? m->z_change += -.1 : 1;
	key == 18 ? m->rx += .01 : 0;
	key == 19 ? m->ry += .01 : 0;
	key == 20 ? m->rz += .01 : 0;
}

int		handlekey(int key, t_fdf *m)
{
	(void)m;
	printf("key = %d\n", key);
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	key == 53 ? keyfunction(key, m) : 0;
	(key >= 123 && key <= 126) ? keyfunction(key, m) : 0;
	(key >= 12 && key <= 15) ? keyfunction(key, m) : 0;
	(key >= 2 && key <= 3) ? keyfunction(key, m) : 0;
	(key == 32 || key == 34) ? keyfunction(key, m) : 0;
	(key >= 18 && key <= 20) ? keyfunction(key, m) : 0;
	plot_map(m);
	return (0);
}
