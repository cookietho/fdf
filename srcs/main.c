/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/29 22:40:41 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 12:59:02 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		main(int ac, char **av)
{
	t_fdf	m;

	ft_bzero(&m, sizeof(t_fdf));
	if (ac == 4)
	{
		m.window_x = ft_atoi(av[2]);
		m.window_y = ft_atoi(av[3]);
		if (m.window_x < 1200)
			error_handling();
		if (m.window_y < 900)
			error_handling();
		// printf("m.win_min = %d\n", m.win_min);
		validation(av[1]); //read for validation
	}
	else
		error_handling();
	read_map(av[1], &m); //read to get actual map info
	initialize(&m);
	m.mlx_ptr = mlx_init();
	m.win_ptr = mlx_new_window(m.mlx_ptr, m.window_x, m.window_y, av[1]);
	screen_msg(&m);
	mlx_hook(m.win_ptr, 2, 0,  handlekey, &m);
	plot_map(&m);
	mlx_loop(m.mlx_ptr);
	return (0);
}
