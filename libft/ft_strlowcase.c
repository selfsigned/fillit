/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:11:08 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/23 15:26:38 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *s)
{
	char *tmp;

	tmp = s;
	while (*s)
	{
		if (ft_isupper(*s))
			*s = ft_tolower(*s);
		s++;
	}
	return (tmp);
}
