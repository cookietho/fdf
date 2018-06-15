/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:55:55 by minakim           #+#    #+#             */
/*   Updated: 2018/06/13 15:20:39 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	error_handling(void)
{
	ft_putstr("Invalid File\n");
	ft_putstr("./fdf <FILE.fdf>	Width > 1200	Height > 900\n");
	exit(0);
}

void	error_fd(char *str, int fd)
{
	ft_putendl(str);
	close(fd);
	exit(0);
}
