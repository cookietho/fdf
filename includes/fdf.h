/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 21:11:48 by minakim           #+#    #+#             */
/*   Updated: 2018/06/14 17:47:19 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx_macos/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# define BUF_SIZE 99999

typedef struct	s_array
{
	float		x;
	float		y;
	float		nx;
	float		ny;
	int			z;
}				t_array;

typedef struct	s_point
{
	double		x0;
	double		y0;
	double		x1;
	double		y1;
}				t_point;

typedef struct	s_plot
{
	double		x0;
	double		y0;
	double		z0;
	double		x1;
	double		y1;
	double		z1;
	double		x2;
	double		y2;
}				t_plot;

typedef struct	s_fdf
{
	t_array		**map;
	void		*mlx_ptr;
	void		*win_ptr;
	int			color;
	int			window_x;
	int			window_y;
	int			win_min;
	int			map_y;
	int			map_x;
	int			map_max;
	int			gap;
	int			zoom;
	int			diagonal;
	int			map_x_mid;
	int			map_y_mid;
	int			x_move;
	int			y_move;
	double		rx;
	double		ry;
	double		rz;
	double		z_change;
}				t_fdf;

int				main(int ac, char **av);
int				check_nbr(char *str, char c);
void			check_map(char *buf, int fd);
void			validation(char *filename);
void			error_handling(void);
void			error_fd(char *str, int fd);
int				count_x(char *str, char c);
void			initialize(t_fdf *m);
void			init_map(t_fdf *m, int fd);
void			screen_msg(t_fdf *m);
void			read_xy(t_fdf *m, int fd);
void			get_z(t_fdf *m, int y, char *line);
void			read_z(t_fdf *m, int fd);
void			malloc_xy(t_fdf *m);
void			read_map(char *filename, t_fdf *m);
void			dda(t_fdf *m, t_point *p);
void			vertical_line(t_fdf *m);
void			horizontal_line(t_fdf *m);
void			projected_pt(t_fdf *m, t_plot *k);
void			plot_map(t_fdf *m);
void			keyfunction(int key, t_fdf *m);
int				handlekey(int key, t_fdf *m);
int				color_it(int color, t_fdf *m);

#endif
