/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 09:37:10 by minakim           #+#    #+#             */
/*   Updated: 2018/06/12 17:42:10 by minakim          ###   ########.fr       */
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
//	m->key1 = 0;
//	m->key2 = 0;
//	m->key3 = 0;
	m->key4 = 1;
//	m->key5 = 0;
//	m->key6 = 0;
//	m->key7 = 0;
//	m->key8 = 0;
	m->key9 = 1;
//	m->key0 = 0;
//	m->zoom = 0;
//	m->win_min = 900;
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
	mlx_string_put(m->
}
