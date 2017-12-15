/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:50:16 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/23 22:08:44 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	i;

	i = -1;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	if (!size || dstlen > size)
		return (srclen + size);
	while (src[++i] && dstlen + i < size - 1)
		dst[dstlen + i] = src[i];
	dst[i + dstlen] = '\0';
	return (srclen + dstlen);
}
