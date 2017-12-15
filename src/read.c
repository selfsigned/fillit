/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 16:56:48 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/15 22:15:02 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

static	int		ft_count_connections(char **src, int y, int x)
{
	int	con;

	con = 0;
	if (x > 0 && src[y][x - 1] == '#')
		con++;
	if (x < 3 && src[y][x + 1] == '#')
		con++;
	if (y > 0 && src[y - 1][x] == '#')
		con++;
	if (y < 3 && src[y + 1][x] == '#')
		con++;
	return (con);
}

static	int		ft_check(char **src)
{
	int	x;
	int	y;
	int	e_cnt;
	int	con;

	y = -1;
	e_cnt = 0;
	con = 0;
	while (++y < 4)
	{
		x = -1;
		while (src[y][++x])
		{
			if (src[y][x] == '#')
			{
				e_cnt++;
				con += ft_count_connections(src, y, x);
			}
			else if (src[y][x] != '.')
				return (ERROR);
		}
		if (x != 4)
			return (ERROR);
	}
	return ((e_cnt == 4 && (con == 6 || con == 8)) ? SUCCESS : ERROR);
}

static	t_tetra	count_len_width(t_tetra t)
{
	int x;

	x = -1;
	t.h_w[0] = 0;
	t.h_w[1] = 0;
	while (++x < 4)
	{
		if (!column_isempty(t.content, x))
			t.h_w[1]++;
	}
	x = -1;
	while (++x < 4)
	{
		if (!line_isempty(t.content[x]))
			t.h_w[0]++;
	}
	return (t);
}

/*
** Here we read the input file and convert it to a 2D array
*/

char			**ft_read(int fd)
{
	char	buf[READ_SIZE];
	int		seek;
	int		tet_nb;
	char	**tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (26 + 1))))
		ft_error();
	tet_nb = 0;
	while ((seek = read(fd, buf, READ_SIZE)))
	{
		if (tet_nb < 26 && (seek == 21 || seek == 20) && buf[seek - 1] == '\n')
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
	if (!(*tab) || ft_strlen(tab[tet_nb - 1]) != 19)
		ft_error();
	return (tab);
}

/*
** And now we... parse
*/

t_tetra			*ft_parse(char **in)
{
	t_tetra	*tet;
	int		t;

	t = -1;
	if (!(tet = (t_tetra*)ft_memalloc(sizeof(t_tetra) * 27)))
	{
		free_mem(tet, in);
		ft_error();
	}
	while (in[++t])
	{
		tet[t].content = ft_strsplit(in[t], '\n');
		if (!tet[t].content || !ft_check(tet[t].content))
		{
			free_mem(tet, in);
			ft_error();
		}
		ft_move_left(tet[t].content);
		tet[t] = count_len_width(tet[t]);
		ft_tetra_letter(tet[t].content, t);
	}
	ft_strdeltab(in, 27);
	return (tet);
}
