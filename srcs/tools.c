/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:37:10 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 13:09:09 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		count_x(char *str, char c)
{
	int	count;
	int	i;

	count = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	return (count);
}

void	initialize(t_fdf *m)
{
	m->color = 0x0000ff;
	m->rx = 0;
	m->ry = 0;
	m->rz = 0;
	m->z_change = 1;
}

void	init_map(t_fdf *m, int fd)
{
	char	*line;

	while (get_next_line(fd, &line) == 1)
	{
		m->map_x = count_x(line, ' ');
		free(line);
		//m->line = NULL;
		m->map_y++;
	}
	m->map_max = (m->map_x > m->map_y) ? (m->map_x) : (m->map_y);
	m->win_min = (m->window_x >= m->window_y) ? m->window_x : m->window_y;
//	m->p_gap = (m->win_min - 450) / (m->map_max + m->zoom);
	initialize(m);
}

void	screen_msg(t_fdf *m)
{
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 5, 0xffffff, "[ESC] : EXIT");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 25, 0xffffff, "X ROTATION : 1");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 50, 0xffffff, "Y ROTATION : 2");
	mlx_string_put(m->mlx_ptr, m->win_ptr, 5, 75, 0xffffff, "Z ROTATION : 3");
}
