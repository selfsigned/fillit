/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 14:42:12 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/07 22:01:58 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	ft_error(void)
{
	ft_putstr_fd(ERROR_MSG, 2);
	exit(1);
}
void	free_mem(t_tetra *tab, char **input)
{
	int i;

	ft_strdeltab(input, 27);
	i = -1;
	while(tab[++i].content)
		ft_strdeltab(tab[i].content, 4);
	free(tab);
}
