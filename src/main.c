/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:27:49 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/04 13:35:55 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_error(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit(1);
}

int		main(int argc, char **argv)
{
	int		fd;

	fd = 0;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error();
	ft_putstr(ft_read(fd)[3]);
}
