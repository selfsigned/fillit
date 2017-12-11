/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:58:21 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/11 01:26:25 by xperrin          ###   ########.fr       */
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
	int	cnt;

	i = -1;
	cnt = 0;
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

	width = 2;
	map.width = width;
	map.is_solved = 0;
	map.grid = alloc_and_fill(width);
	while (!ft_algo(tet_in, map, width))
	{
		width++;
		free(map.grid);
		map.grid = alloc_and_fill(width);
	}
	ft_display(map.grid, width);
	ft_strdeltab(map.grid, width + 1);
}
