/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:58:21 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/13 00:58:17 by xperrin          ###   ########.fr       */
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

int				ft_algo(t_tetra *tet, t_map map, int tetnbr)
{
	int x;
	int y;

	if (tetnbr == map.ctet)
		return (SUCCESS);
	y = -1;
	while (++y < map.width - tet[tetnbr].h_w[0] + 1)
	{
		x = -1;
		while (++x < map.width - tet[tetnbr].h_w[1] + 1)
			if (is_placeable(tet[tetnbr], map, y, x))
			{
				place_on_map(tet[tetnbr], map, y, x);
				if (ft_algo(tet, map, tetnbr + 1))
					return (SUCCESS);
				else
					remove_on_map(map, tetnbr);
			}
	}
	return (FALSE);
}

/*
** Here we call the algo until we've got the right map
*/

void			ft_solve(t_tetra *tet_in)
{
	t_map	map;

	map.ctet = count_tetra(tet_in);
	map.width = 4;
	map.is_solved = 0;
	map.grid = alloc_and_fill(map.width);
	while (!ft_algo(tet_in, map, 0))
	{
		map.width++;
		ft_strdeltab(map.grid, map.width  + 1);
		map.grid = alloc_and_fill(map.width);
	}
	ft_display(map.grid, map.width);
	ft_strdeltab(map.grid, map.width  + 1);
}
