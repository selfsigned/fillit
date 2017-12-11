/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:42:12 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/10 22:10:11 by xperrin          ###   ########.fr       */
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
