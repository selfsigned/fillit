/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 15:59:44 by bede-fre          #+#    #+#             */
/*   Updated: 2017/12/05 18:13:34 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

void	ft_display(t_map map)
{
	char	*tmp;

	tmp = map.grid;
	while (*tmp != '\0')
	{
		write(1, tmp, map.width);
		tmp = tmp + map.width;
		ft_putchar('\n');
	}
}
