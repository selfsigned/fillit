/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:27:49 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/13 18:08:12 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>

void	ft_display(char **map, int maplen)
{
	int i;

	i = -1;
	while (++i < maplen)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}

int				main(int argc, char **argv)
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
	ft_solve(t_in);
	free_tet(t_in);
}
