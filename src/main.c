/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:27:49 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/05 22:07:19 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	char	**input;
	t_tetra	*t_in;

	fd = 0;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error();
	if (!(input = ft_read(fd)))
		ft_error();
	t_in = ft_parse(input);
	ft_putstr(t_in[0].content);
}
