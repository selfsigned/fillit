/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:27:49 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/11 19:16:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int		fd;
	char	**input;
	t_tetra	*t_in;
	int		i;

	fd = 0;
	i = -1;
	if (argc != 2 || (fd = open(argv[1], O_RDONLY)) <= 0)
		ft_error();
	if (!(input = ft_read(fd)))
		ft_error();
	t_in = ft_parse(input);
	/* while (t_in[++i].content) */
	/* 	ft_display(t_in[i].content, 4); */
	ft_solve(t_in);
	free_tet(t_in);
}
