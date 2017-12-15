/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 14:30:29 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/25 00:06:08 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*magic(int n, int len, int is_neg)
{
	char *dst;

	if (!(dst = ft_strnew(len)))
		return (NULL);
	while (len-- != -1)
	{
		dst[len] = (n % 10 + '0');
		n /= 10;
	}
	if (is_neg)
		dst[0] = '-';
	return (dst);
}

char			*ft_itoa(int n)
{
	int		len;
	int		is_neg;

	if (n == MINIMUM_INT)
		return (ft_strdup(MINIMUM_INT_STR));
	is_neg = 0;
	if (n < 0)
	{
		n *= -1;
		is_neg = 1;
	}
	len = (is_neg) ? ft_cntdigit(n) + 1 : ft_cntdigit(n);
	return (magic(n, len, is_neg));
}
