/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 15:08:27 by xperrin           #+#    #+#             */
/*   Updated: 2017/11/23 15:27:53 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *s)
{
	char *tmp;

	tmp = s;
	while (*s)
	{
		if (ft_islower(*s))
			*s = ft_toupper(*s);
		s++;
	}
	return (tmp);
}
