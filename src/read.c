/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:33:46 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/07 17:57:48 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

/*
** Here we read the input file and convert it to a 2D array
*/

char		**ft_read(int fd)
{
	char	buf[READ_SIZE];
	int		seek;
	int		tet_nb;
	char	**tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (26 + 1))))
		return (NULL);
	tet_nb = 0;
	while ((seek = read(fd, buf, READ_SIZE)))
	{
		if (tet_nb <= 26 && (seek == 21 || seek == 20) && buf[seek - 1] == '\n')
		{
			buf[seek - 1] = '\0';
			tab[tet_nb] = ft_strdup(buf);
		}
		else
		{
			ft_strdeltab(tab, 27);
			ft_error();
		}
		tet_nb++;
	}
	if (ft_strlen(tab[tet_nb - 1]) != 19)
		ft_error();
	return (tab);
}

static	int	ft_check(char **src)
{
	int	x;
	int	y;
	int	e_cnt;

	y = -1;
	e_cnt = 0;
	while (++y < 4)
	{
		x = -1;
		while (src[y][++x])
		{
			if (src[y][x] != '#' && src[y][x] != '.')
				return (ERROR);
			if (src[y][x] == '#' && !((x > 0 && src[y][x - 1] == '#')
				|| (x < 3 && src[y][x + 1] == '#')
				|| (y > 0 && src[y - 1][x] == '#')
				|| (y < 3 && src[y + 1][x] == '#')))
				return (ERROR);
			e_cnt = (src[y][x] == '#') ? e_cnt + 1 : e_cnt;
		}
	}
	return ((e_cnt == 4) ? SUCCESS : ERROR);
}

/*
** And now we... parse
*/

t_tetra		*ft_parse(char **in)
{
	t_tetra	*tet;
	int		t;

	t = 0;
	if (!(tet = (t_tetra*)ft_memalloc(sizeof(t_tetra) * 26)))
	{
		ft_strdeltab(in, 27);
		ft_error();
	}
	while (in[t])
	{
		tet[t].content = ft_strsplit(in[t], '\n');
		if (ft_check(tet[t].content))
		{
			ft_strdeltab(in, 27);
			free(tet);
			ft_error();
		}
		ft_move_left(tet[t].content);
		ft_tetra_letter(tet[t].content, t);
		tet[t].index = t;
		t++;
	}
	return (tet);
}
