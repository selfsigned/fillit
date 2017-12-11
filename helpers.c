/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:42:12 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/11 19:52:39 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_error(void)
{
	ft_putstr(ERROR_MSG);
	exit(1);
}

void	free_tet(t_tetra *tab)
{
	int i;

	i = -1;
	while (tab[++i].content)
		ft_strdeltab(tab[i].content, 4);
	free(tab);
}

void	free_mem(t_tetra *tab, char **input)
{
	ft_strdeltab(input, 27);
	free_tet(tab);
}

void	ft_tetra_letter(char **tab, int tet_nbr)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 4)
		{
			if (tab[j][i] == '#')
				tab[j][i] += 30 + tet_nbr;
			i++;
		}
		j++;
	}
}
