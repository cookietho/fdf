/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 18:06:07 by minakim           #+#    #+#             */
/*   Updated: 2018/06/14 17:48:35 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	dda(t_fdf *m, t_point *p)
{
	float	x;
	float	y;
	float	dx;
	float	dy;
	float	step;

	dx = p->x1 - p->x0;
	dy = p->y1 - p->y0;
	step = (fabs(dx) >= fabs(dy)) ? fabs(dx) : fabs(dy);
	dx = dx / step;
	dy = dy / step;
	x = p->x0;
	y = p->y0;
	while (step-- > 0)
	{
		mlx_pixel_put(m->mlx_ptr, m->win_ptr, x, y, m->color);
		x = x + dx;
		y = y + dy;
	}
}

void	vertical_line(t_fdf *m)
{
	int		i;
	int		j;
	t_point	*p;

	p = malloc(sizeof(t_point));
	i = 0;
	while (i < m->map_y - 1)
	{
		j = 0;
		while (j < m->map_x)
		{
			p->x0 = m->map[j][i].nx;
			p->y0 = m->map[j][i].ny;
			p->x1 = m->map[j][i + 1].nx;
			p->y1 = m->map[j][i + 1].ny;
			dda(m, p);
			j++;
		}
		i++;
	}
	free(p);
}

void	horizontal_line(t_fdf *m)
{
	int		i;
	int		j;
	t_point	*p;

	p = malloc(sizeof(t_point));
	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x - 1)
		{
			p->x0 = m->map[j][i].nx;
			p->y0 = m->map[j][i].ny;
			p->x1 = m->map[j + 1][i].nx;
			p->y1 = m->map[j + 1][i].ny;
			dda(m, p);
			j++;
		}
		i++;
	}
	free(p);
}

void	projected_pt(t_fdf *m, t_plot *k)
{
	k->x1 = k->x0 * cos(m->ry) - k->z0 * sin(m->ry);
	k->y1 = k->y0;
	k->z1 = k->z0 * cos(m->ry) + k->x0 * sin(m->ry);
	k->x2 = k->x1 * cos(m->rz) + k->y1 * sin(m->rz);
	k->y2 = k->y1 * cos(m->rz) - k->x1 * sin(m->rz);
}

void	plot_map(t_fdf *m)
{
	int		x;
	int		y;
	t_plot	*k;

	k = malloc(sizeof(t_plot));
	y = -1;
	while (++y < m->map_y)
	{
		x = -1;
		while (++x < m->map_x)
		{
			m->gap = (m->win_min - 450) / (m->map_max + m->zoom);
			k->x0 = m->map[x][y].x - (m->map_x / 2);
			k->y0 = (m->map[x][y].y - (m->map_y / 2)) * cos(m->rx) +
				(m->map[x][y].z * m->z_change) * sin(m->rx);
			k->z0 = (m->map[x][y].z * m->z_change) * cos(m->rx) -
				(m->map[x][y].y - (m->map_y / 2)) * sin(m->rx);
			projected_pt(m, k);
			m->map[x][y].nx = (k->x2 * m->gap + (m->window_x / 2)) + m->x_move;
			m->map[x][y].ny = (k->y2 * m->gap + (m->window_y / 2)) + m->y_move;
		}
	}
	free(k);
	horizontal_line(m);
	vertical_line(m);
}
