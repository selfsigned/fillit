/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/07 15:45:29 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_display(char **map, int maplen)
{
	int i;

	i = -1;
	while (++i < maplen)
	{
		ft_putstr(map[i]);
		ft_putchar('\n');
	}
}
