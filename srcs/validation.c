/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minakim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 17:49:46 by minakim           #+#    #+#             */
/*   Updated: 2018/06/14 16:31:53 by minakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		check_nbr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	check_map(char *buf, int fd)
{
	int		i;

	i = -1;
	while (buf[++i] != '\0')
	{
		if (buf[i] == '\n' && buf[i + 1] == '\n')
			error_fd("invalid input file\n", fd);
		else if (buf[i] < ' ' && buf[i] != '\n')
			error_fd("invalid input file\n", fd);
		else if (buf[i] > ' ' && buf[i] < ',')
			error_fd("invalid input file\n", fd);
		else if (buf[i] > '-' && buf[i] < '0')
			error_fd("invalid input file\n", fd);
		else if (buf[i] > '9' && buf[i] < 'A')
			error_fd("invalid input file\n", fd);
		else if (buf[i] > 'F' && buf[i] < 'a')
			error_fd("invalid input file\n", fd);
		else if (buf[i] > 'f' && buf[i] != 'x')
			error_fd("invalid input file\n", fd);
	}
}

void	validation(char *filename)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	if ((fd = open(filename, O_RDONLY)) < 0)
		error_fd("invalid file\n", fd);
	ret = read(fd, buf, BUF_SIZE);
	if (*buf == 0)
		error_fd("empty file\n", fd);
	if (ret)
		check_map(buf, fd);
	close(fd);
}
