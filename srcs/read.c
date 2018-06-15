/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:37:56 by minakim           #+#    #+#             */
/*   Updated: 2018/06/14 17:48:43 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

void	get_z(t_fdf *m, int y, char *line)
{
	char	**color;
	char	**height;
	int		x;

	x = -1;
	color = NULL;
	height = ft_strsplit(line, ' ');
	while (height[++x] != NULL)
	{
		m->map[x][y].x = x;
		m->map[x][y].y = y;
		m->map[x][y].z = ft_atoi(height[x]);
		free(height[x]);
	}
	free(height);
}

void	read_z(t_fdf *m, int fd)
{
	int		y;
	char	*line;

	y = 0;
	while (get_next_line(fd, &line) == 1)
	{
		get_z(m, y, line);
		free(line);
		y++;
		line = NULL;
	}
}

void	malloc_xy(t_fdf *m)
{
	int	i;

	i = -1;
	m->map = (t_array**)malloc(sizeof(t_array*) * (m->map_x + 1));
	while (++i < m->map_x)
		m->map[i] = (t_array*)malloc(sizeof(t_array) * (m->map_y + 1));
}

void	read_map(char *filename, t_fdf *m)
{
	int		fd;

	fd = open(filename, O_RDONLY);
	init_map(m, fd);
	close(fd);
	malloc_xy(m);
	fd = open(filename, O_RDONLY);
	read_z(m, fd);
	close(fd);
}
