/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:43:54 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/15 15:15:41 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned int		i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	i = 0;
	tmp1 = (const unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	while (tmp1[i] && tmp2[i] && tmp1[i] == tmp2[i])
		i++;
	return (tmp1[i] - tmp2[i]);
}
