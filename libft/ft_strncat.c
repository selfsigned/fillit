/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 00:26:28 by xperrin           #+#    #+#             */
/*   Updated: 2017/10/06 00:40:02 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t len)
{
	int		i;
	size_t	e;

	e = -1;
	i = ft_strlen(s1) - 1;
	while (s2[++e] && e < len)
		s1[++i] = s2[e];
	s1[++i] = '\0';
	return (s1);
}
