/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:08:18 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/21 00:53:33 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				i;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	if (!n)
		return (0);
	i = 0;
	tmp1 = (const unsigned char*)s1;
	tmp2 = (const unsigned char*)s2;
	while ((i + 1) < n && tmp1[i] && tmp2[i] && tmp1[i] == tmp2[i])
		i++;
	return (tmp1[i] - tmp2[i]);
}
