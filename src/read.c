/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 18:33:46 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/03 23:12:13 by xperrin          ###   ########.fr       */
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
	int		tet_nbr;
	char	**tab;

	if (!(tab = (char**)ft_memalloc(sizeof(char*) * (26 + 1))))
		return (NULL);
	tet_nbr = 0;
	while ((seek = read(fd, buf, READ_SIZE)))
	{
		if ((buf[seek - 1] == '\n' || buf[seek - 1] == '\0') && tet_nbr <= 26)
		{
			buf[seek - 1] = '\0';
			tab[tet_nbr] = ft_strdup(buf);
		}
		else
			ft_error();
		tet_nbr++;
	}
	return (tab);
}
