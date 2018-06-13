/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/31 23:37:56 by minakim           #+#    #+#             */
/*   Updated: 2018/06/11 16:15:38 by minakim          ###   ########.fr       */
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
//		m->y[y][x].z = m->x[x][y].z;
//		if (m->x[x][y].z != 0) /* when there is height */
//			m->z_h[y][x] = (3 * m->x[x][y].z);
//		if (check_nbr(height[x], ',') == 1)
//		{
//			color = ft_strsplit(height[x], 'x');
//			m->color[y][x] = (ft_atoi_base(color[1], 16));
//			free(color);
//		}
//		else if (check_nbr(height[x], 'x') == 0)
//			m->color[y][x] = (0);
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
	//int	j;

	i = -1;
	m->map = (t_array**)malloc(sizeof(t_array*) * (m->map_x + 1));
	while (++i < m->map_x) /* (x,y) in x point of view */
		m->map[i] = (t_array*)malloc(sizeof(t_array) * (m->map_y + 1));
	//i = -1;
	/*m->new_xy = (t_array**)malloc(sizeof(t_array*) * (m->x_value + 1));
	while (++i < m->x_value)
		m->new_xy[i] = (t_array*)malloc(sizeof(t_array) * (m->y_value + 1));*/
	/*i = -1;
	m->y = (t_array**)malloc(sizeof(t_array*) * (m->y_value + 1));
	while (++i < m->y_value)  //(y,x) in y point of view 
		m->y[i] = (t_array*)malloc(sizeof(t_array) * (m->x_value + 1));*/
//	i = -1;
//	m->z_h = (int**)malloc(sizeof(int*) * (m->y_value + 1));
//	while (++i < m->y_value)
//		m->z_h[i] = (int*)malloc(sizeof(int) * (m->x_value + 1));
//	i = -1;
//	m->color = (t_array**)malloc(sizeof(t_array*) * (m->map_x + 1));
//	while (++i < m->map_x)
//	{
//		m->color[i] = (t_array*)malloc(sizeof(t_array) * (m->map_y + 1));
//		j = -1;
//		while (++j < m->map_y)
//			m->color[i][j].c = 0x0000ff;
//	}
}

void	read_map(char *filename, t_fdf *m)
{
	int		fd;

	fd = open(filename, O_RDONLY); /*open again to read info*/
	init_map(m, fd);
	close(fd);
	malloc_xy(m);
	fd = open(filename, O_RDONLY);
	read_z(m, fd);
	close(fd);
}
