/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xperrin <xperrin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:17:01 by xperrin           #+#    #+#             */
/*   Updated: 2017/12/01 20:01:28 by xperrin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	unsigned int	e;

	e = 0;
	i = ft_strlen(s);
	while (s[e] == ' ' || s[e] == ',' || s[e] == '\n' || s[e] == '\t')
		e++;
	if (e == i)
		return (ft_strnew(0));
	while (s[i - 1] == ' ' || s[i - 1] == ','
			|| s[i - 1] == '\n' || s[i - 1] == '\t')
		i--;
	return ((!(*s) || (!e && i == ft_strlen(s) - 1)) ? ((char*)s)
			: ft_strsub(s, e, i - e));
}
