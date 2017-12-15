/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 15:22:08 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/04 18:08:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdeltab(char **tab, size_t tab_len)
{
	size_t i;

	i = -1;
	while (++i < tab_len)
		if (tab[i])
			ft_strdel(&tab[i]);
	free(tab);
	tab = NULL;
}
