/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/05 21:09:48 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/14 16:36:36 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *tmp1;
	const unsigned char *tmp2;

	tmp1 = (const unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	while (n)
	{
		if (*tmp1 != *tmp2)
			return (*tmp1 - *tmp2);
		++tmp1;
		++tmp2;
		--n;
	}
	return (0);
}
