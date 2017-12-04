/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:33:46 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/04 18:47:07 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

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
