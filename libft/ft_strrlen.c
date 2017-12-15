/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 18:59:51 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/22 21:35:31 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strrlen(const char *s, char c)
{
	const	char	*tmp;

	tmp = s;
	while (*tmp && *tmp != c)
		tmp++;
	return (tmp - s);
}
