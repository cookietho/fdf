/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:06:07 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 13:08:31 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	dda(t_fdf *m, float x0, float y0, float x1, float y1)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;
	
	dx = x1 - x0;
	dy = y1 - y0;

	step = (fabs(dx) >= fabs(dy)) ? fabs(dx) : fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = x0;
	y = y0;
	while (step-- > 0)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, x, y, m->color);
		x = x + dx;
		y = y + dy;
	}
}

void	draw_map(t_fdf *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x - 1)
		{
			dda(m, m->map[j][i].nx, m->map[j][i].ny, m->map[j + 1][i].nx, m->map[j + 1][i].ny);
			j++;
		}
		i++;
	}
	i = 0;
	while (i < m->map_y - 1)
	{
		j = 0;
		while (j < m->map_x)
		{
			dda(m, m->map[j][i].nx, m->map[j][i].ny, m->map[j][i + 1].nx, m->map[j][i + 1].ny);
			j++;
		}
		i++;
	}
}

void	plot_map(t_fdf *m)
{
	int	x;
	int	y;
	t_plot *k;

	x = -1;
	k = malloc(sizeof(t_plot));
	while (++x < m->map_x)
	{
		y = -1;
		while (++y < m->map_y)
		{
			m->p_gap = (m->win_min - 450) / (m->map_max + m->zoom);
			k->x0 = m->map[x][y].x - (m->map_x / 2);
			k->y0 = (m->map[x][y].y - (m->map_y / 2)) * cos(m->rx) + (m->map[x][y].z * m->z_change) * sin(m->rx);
			k->z0 = (m->map[x][y].z * m->z_change) * cos(m->rx) - (m->map[x][y].y - (m->map_y / 2)) * sin(m->rx);
			k->x1 = k->x0 * cos(m->ry) - k->z0 * sin(m->ry);
			k->y1 = k->y0;
			k->z1 = k->z0 * cos(m->ry) + k->x0 * sin(m->ry);
			k->x2 = k->x1 * cos(m->rz) + k->y1 * sin(m->rz);
			k->y2 = k->y1 * cos(m->rz) - k->x1 * sin(m->rz);
			m->map[x][y].nx = (k->x2 * m->p_gap + (m->window_x / 2)) + m->map_x_move;
			m->map[x][y].ny = (k->y2 * m->p_gap + (m->window_y / 2)) + m->map_y_move;
		}
	}
	free(k);
	draw_map(m);
}
