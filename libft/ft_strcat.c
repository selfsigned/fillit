/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 23:34:56 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/06 00:26:19 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int i;
	int e;

	e = -1;
	i = ft_strlen(s1) - 1;
	while (s2[++e])
		s1[++i] = s2[e];
	s1[++i] = '\0';
	return (s1);
}
