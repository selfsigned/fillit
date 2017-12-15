/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 10:15:21 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/01 20:01:46 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		wi;
	int		wc;
	char	**dst;

	wc = ft_cntword(s, c);
	if (!(dst = (char**)ft_memalloc(sizeof(char*) * (wc + 1))))
		return (NULL);
	if (!ft_strlen(s))
		return (dst);
	wi = -1;
	while (++wi < wc)
	{
		while (*s == c)
			s++;
		dst[wi] = ft_strndup(s, ft_strrlen(s, c));
		s += ft_strrlen(s, c);
	}
	dst[wi] = 0;
	return (dst);
}
