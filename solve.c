/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:58:21 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/11 13:41:17 by xperrin          ###   ########.fr       */
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

static	int		is_placeable(t_tetra tet, t_map  map, int y, int x)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			if (ft_isalpha(map.grid[y + i][x + j])
					&& ft_isalpha(tet.content[i][j]))
				return (FALSE);
		}
	}
	return (TRUE);
}

static	void	place_on_map(t_tetra tet, t_map map, int y, int x)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4 && cnt != 4)
		{
			if (ft_isalpha(map.grid[y + i][x + j])
					&& ft_isalpha(tet.content[i][j]))
				map.grid[y + i][x + j] = tet.content[i][j];
		}
	}
}

int				ft_algo(t_tetra *tet_in, t_map map, int mapw)
{
	return (ERROR);
}

/*
** Here we call the algo until we've got the right map
*/

void		ft_solve(t_tetra *tet_in)
{
	t_map	map;
	int		width;

	width = 4;
	map.width = width;
	map.is_solved = 0;
	map.grid = alloc_and_fill(width);
	/* while (!ft_algo(tet_in, map, width)) */
	/* { */
	/* 	width++; */
	/* 	free(map.grid); */
	/* 	map.grid = alloc_and_fill(width); */
	/* } */
	place_on_map(tet_in[0], map, 0, 0);
	ft_display(map.grid, width);
	ft_strdeltab(map.grid, width + 1);
}
