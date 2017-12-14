/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solvefun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:10:08 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/13 17:19:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	place_on_map(t_tetra tet, t_map map, int y, int x)
{
	int	i;
	int	j;
	int	cnt;
	int wdh;

	i = -1;
	cnt = 0;
	wdh = (map.width < 4) ? map.width : 4;
	while (++i < wdh)
	{
		j = -1;
		while (++j < wdh && cnt < 4)
		{
			if (ft_isalpha(tet.content[i][j]))
			{
				map.grid[y + i][x + j] = tet.content[i][j];
				cnt++;
			}
		}
	}
}

void	remove_on_map(t_map map, int tet_nbr)
{
	int	i;
	int	j;
	int	cnt;

	i = -1;
	cnt = 0;
	while (++i < map.width && cnt < 4)
	{
		j = -1;
		while (++j < map.width && cnt < 4)
		{
			if (map.grid[i][j] == 'A' + tet_nbr)
			{
				map.grid[i][j] = '.';
				cnt++;
			}
		}
	}
}
