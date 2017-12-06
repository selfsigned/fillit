/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:33:46 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/06 16:51:38 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdlib.h>

/*
** read the input file and convert it to a 2D array we're going to parse later
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

/*
** Here's the actual parsing action
*/

static	int	ft_neighbcheck(char *s)
{
	int i;
	int line;
	int linepos;

	ft_putchar('\n');
	i = -1;
	while (s[++i] != '#')
		;
	line = i / 4;
	linepos = i % 4;
	/* printf("i: %d line of i:%d linepost of i:%d\n", i, line, linepos); */
	if ((linepos > 0 && s[linepos - 1 * (line * 4)] == '#')
		|| (linepos < 3 && s[linepos + 1 * (line * 4)] == '#')
		|| (line > 0 && s[line - 1 * (linepos * 4)] == '#')
		|| (line < 3 && s[line + 1 * (linepos * 4)] == '#'))
	{
		return (SUCCESS);
	}
	return (ERROR);
}

static	int	ft_check_n_dup(char *dst, char *src)
{
	int	ri;
	int elem_nbr;

	ri = 0;
	elem_nbr = 0;
	while ((*src == '.' || *src == '#' || *src == '\n') && elem_nbr <= 4)
	{
		elem_nbr = (*src == '#') ? elem_nbr + 1 : elem_nbr;
		if (*src != '\n')
			dst[ri++] = *src;
		src++;
	}
	dst[ri] = '\0';
	if (elem_nbr != 4 || ft_strlen(dst) != 16 || ft_neighbcheck(dst))
		return (ERROR);
	return (SUCCESS);
}

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
		if (ft_check_n_dup(tet[t].content, in[t]))
		{
			ft_strdeltab(in, 27);
			free(tet);
			ft_error();
		}
		tet[t].index = t;
		t++;
	}
	return (tet);
}
