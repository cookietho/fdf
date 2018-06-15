/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 10:33:07 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 15:58:08 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		color_it(int color, t_fdf *m)
{
	int		i;
	int		j;

	i = 0;
	while (i < m->map_y)
	{
		j = 0;
		while (j < m->map_x - 1)
		{
			m->color = color;
			color += 20;
			j++;
		}
		i++;
	}
	return (m->color);
}
