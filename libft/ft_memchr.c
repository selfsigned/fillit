/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 20:39:39 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/26 19:07:06 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *src, int c, size_t len)
{
	size_t i;

	i = -1;
	while (++i < len)
		if (((unsigned char*)src)[i] == (unsigned char)c)
			return ((void*)src + i);
	return (NULL);
}
