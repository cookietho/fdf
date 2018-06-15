/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlekey.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:23:45 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 20:46:17 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	keyfunction(int key, t_fdf *m)
{
	key == 53 ? exit(0) : 0;
	key == 123 ? m->x_move += -1 : 0;
	key == 124 ? m->x_move += 1 : 0;
	key == 125 ? m->y_move += 1 : 0;
	key == 126 ? m->y_move += -1 : 0;
	key == 2 ? m->zoom += -2.5 : 0;
	key == 3 ? m->zoom += 2.5 : 0;
	key == 12 ? m->color = 0xff0000 : 0x0000ff;
	key == 13 ? m->color = 0xff00ff : 0x0000ff;
	key == 14 ? m->color = 0x0085ff : 0x0000ff;
	key == 15 ? m->color = 0xf9bb00 : 0x0000ff;
	key == 16 ? color_it(m->color, m) : 0x0000ff;
	key == 8 ? m->z_change += .1 : 1;
	key == 9 ? m->z_change += -.1 : 1;
}

void	rotation(int key, t_fdf *m)
{
	key == 18 ? m->rx += .01 : 0;
	key == 19 ? m->ry += .01 : 0;
	key == 20 ? m->rz += .01 : 0;
	key == 83 ? m->rx += -.01 : 0;
	key == 84 ? m->ry += -.01 : 0;
	key == 85 ? m->rz += -.01 : 0;
}

int		handlekey(int key, t_fdf *m)
{
	(void)m;
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	key == 53 ? keyfunction(key, m) : 0;
	(key >= 123 && key <= 126) ? keyfunction(key, m) : 0;
	(key >= 12 && key <= 16) ? keyfunction(key, m) : 0;
	(key >= 2 && key <= 3) ? keyfunction(key, m) : 0;
	(key == 8 || key == 9) ? keyfunction(key, m) : 0;
	((key >= 18 && key <= 20) || (key >= 83 && key <= 85))
		? rotation(key, m) : 0;
	screen_msg(m);
	plot_map(m);
	return (0);
}
