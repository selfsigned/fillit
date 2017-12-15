/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 18:58:54 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/20 22:24:23 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const	char	*tmp;

	tmp = s;
	s = s + ft_strlen(s);
	while (*s != c)
		if (*s-- == *tmp)
			return (NULL);
	return ((char*)s);
}
