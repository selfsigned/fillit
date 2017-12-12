/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:58:21 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/12 20:18:57 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

/*
** Returning a new clean map
*/

static	char	**alloc_and_fill(size_t mapw)
{
	size_t	y;
	size_t	x;
	char	**grid;

	y = -1;
	if (!(grid = (char**)ft_memalloc(sizeof(char*) * (mapw + 1))))
		return (NULL);
	while (++y < mapw)
	{
		x = -1;
		if (!(grid[y] = ft_strnew(mapw)))
			return (NULL);
		while (++x < mapw)
			grid[y][x] = '.';
	}
	grid[y] = 0;
	return (grid);
}

/*
** Checking if we can place the tetra on the map at the given coordinates
*/

static	int		is_placeable(t_tetra tet, t_map map, int y, int x)
{
	int	i;
	int	j;

	if ((map.width - y) < tet.h_w[0] || (map.width - x) < tet.h_w[1])
		return (FALSE);
	i = -1;
	while (++i < tet.h_w[0])
	{
		j = -1;
		while (++j < tet.h_w[1])
			if (ft_isalpha(map.grid[y + i][x + j])
				&& ft_isalpha(tet.content[i][j]))
				return (FALSE);
	}
	return (TRUE);
}

int				ft_algo(t_tetra *tet_in, t_map map, int tetnbr)
{
	int x;
	int y;
	int t;

	t = 0;
	y = 0;
	while ((y < map.width) && (x < map.width))
	{
		x = 0;
		if (is_placeable(tet_in[tetnbr], map, y, x))
		{
			place_on_map(tet_in[tetnbr], map, y, x);
			if (ft_algo(tet_in, map, tetnbr + 1))
				return (SUCCESS);
			remove_on_map(map, tetnbr);
			x++;
		}
		y++;
	}
	return (FALSE);
}

/*
** Here we call the algo until we've got the right map
*/

void			ft_solve(t_tetra *tet_in)
{
	t_map	map;

	map.ctet = 0;
	map.width = 5;
	map.is_solved = 0;
	map.grid = alloc_and_fill(map.width);
	/* while (!ft_algo(tet_in, map, 0)) */
	/* { */
	/* 	ft_display(map.grid, map.width); */
	/* 	map.width++; */
	/* 	free(map.grid); */
	/* 	map.grid = alloc_and_fill(map.width); */
	/* } */
	int x = 1; int y = 1;
	if (is_placeable(tet_in[0], map, y, x))
		place_on_map(tet_in[0], map, y, x);
	ft_display(map.grid, map.width);
	ft_strdeltab(map.grid, map.width  + 1);
}
